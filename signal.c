#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include "libft/include/libft.h"


/*
	SIGNAL	- sets the function of a signal

		sighandler_t	signal(int sig, sighandler_t handler);

		ARGS

			sig - sig is the signal whose function you want to set	

			handler - this is a `void	handler(int sig)` function which with run when sig is used

				the kill() function is call in the prograom or the user inputs the signal

			you have three options for handler
				
				1. SIG_IGN - this tells the process to ignore sig
				2. SIG_DFL - this tells the process to treat sig normally
				3. handler - this tells the process to redefine sig with the code in the handler

		RETURN

			returns the previous value of the handler or SIG_ERR on error(errno set)

		IMPORTANT NOTES

			if you call signal() and fork() the handler will affect both the parent and child
			it is best to use signal() inside the child to ignore all signals

*/

volatile sig_atomic_t	g_signal;


void	handle_sigint(int signal)
{
	g_signal = signal;
	rl_on_new_line();
	rl_replace_line("", 0);
	printf("\n");
	rl_redisplay();
}

void	handle_sigquit(int signal)
{
	g_signal = signal;
	printf("Ctrl-\\\n");
	exit(0);
}

void	config_parent_signals(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	config_child_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	process_input(char **cmdv)
{
	char **tmp;

	tmp = cmdv;
	while (*tmp)
	{
		printf("\t%s ...\n", *tmp);
		tmp++;
	}
	printf("\tYeah... I'm not doing that.\n");
}

int		main(int ac, char **av)
{
	char	*input;
	char	**cmdv;
	pid_t	pid;

	config_parent_signals();
	while (true)
	{
		printf("Parent (Before Fork): %d\n", getpid());
		input = readline("minishell$ ");
		if (input == NULL || (ft_strncmp(input, "exit", 4) == 0))
		{
			free(input);
			exit(0);
		}
		pid = fork();
		if (pid == 0)
		{
			config_child_signals();
			cmdv = ft_split(input, ' ');
			process_input(cmdv);
			ft_free_str_arr(cmdv);
			free(input);
			printf("Parent PID in Child: %d\n", getppid());
			printf("Child PID: %d\n", getpid());
			exit(0);
		}
		else
		{
			waitpid(pid, NULL, 0);
			printf("Parent PID (After Fork): %d\n", getpid());
		}
	}
	if (input)
		free(input);
	return (0);
}

#Minishell
##Creating a simple shell
###Processes and file descriptors

#Mandatory part

Libft authorized: Yes
External Functs.:
	✔️ readline
	✔️ rl_clear_history
	✔️ rl_on_new_line
	✔️ rl_replace_line
	✔️ rl_redisplay
	✔️ add_history
	✔️ printf
	✔️ malloc/free
	✔️ write
	✔️ access
	open
	read
	close
	fork
	wait
	waitpid
	wait3
	wait4
	signal
	sigaction
	sigemptyset
	sigaddset
	kill
	exit
	getcwd
	chdir
	stat
	lstat
	fstat
	unlink
	execve
	dup
	dup2
	pipe
	opendir
	readdir
	closedir
	strerror
	perror
	isatty
	ttyname
	ttyslot
	ioctl
	getenv
	tcsetattr
	tcgetattr
	tgetent
	tgetflag
	tgetnum
	tgetstr
	tgoto
	tputs


Shell Requirments:

	display a PROMPT when waitng for a new commmand
	have working history
	search & launch the right executable
		based on the PATH variable
		OR using a relative path
		OR using a absolute path
	avoid using more than ONE GLOBAL VARIABLE to indicate a received signal
		the signal handler won't access your main data struct
		FORBIDDEN: Global Variable must provide the number of received signal. Nother else.
			- using norm type structures in a global scope is forbidden.
	Not interpret UNCLOSED QUOTES or SPECIAL CHARACTERS which are not required by the subject
		- '\' or ';' 
	Handle single quote	
		- should prevent the shell from interpreting the meta characters in the quoted sequence
	Handle double quote
		- should prevent the shell from interpreting the meta characters in a quoted
			- expect for '$'
	Implement redirection
		- '<' should redirect input
		- '>' should redirect output
		- '<< [delimiter]' read the input until the a LINE containing the [delimiter] is seen
			- doesn't have to update the history
		- '>>' should redirect output in append mode
	Implement pipes '|'
		- the output of each command in the pipeline is connect ot the input of the next command via a pipe
	Handle ENVIRONMENT VARIABLES
		- ($ followed by a sequence of characters) which should expand to their values
	Handle '$?'
		- which should expand to the exit status of the most recently executed foreground pipeline
	Interactive mode:
		- ^C : displays a new prompt on a new line 
		- ^D : exits the shell
		- ^\ : does nothing
	Shell must have following BUILTINS
		- echo w/ option -n
		- cd w/ only a relative or absolute path
		- pwd w/ no options
		- export w/ no options
		- unset w/ no options
		- env w/ no options or arguments
		- exit w/ no options
	The readline() function can cause memory leaks
		- Don't have to fix them
		- You're code cannot have memory leaks.
	Stick to the requirements don't worry about any not required
		- take bash as a reference
Resources:

http://hpux.connect.org.uk/hppd/hpux/Gnu/readline-8.2.13/

https://www.linux-magazine.com/Issues/2020/232/Between-the-Lines

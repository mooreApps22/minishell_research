# Minishell 🐚
## Creating a simple shell 🦪
### Processes and file descriptors
## Libft authorized: Yes
## External Functs.:
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
	✔️ open
	✔️ read
	✔️ close
	✔️ fork
	✔️ wait
	✔️ waitpid
	✔️ wait3
	✔️ wait4
	✔️ signal
	✔️ sigaction
	✔️ sigemptyset
	✔️ sigaddset
	✔️ kill
	✔️ exit
	✔️ getcwd
	✔️ chdir
	✔️ stat
	✔️ lstat
	✔️ fstat
	✔️ unlink
	✔️ execve
	✔️ dup
	✔️ dup2
	✔️ pipe
	✔️ opendir
	✔️ readdir
	✔️ closedir
	✔️ strerror
	✔️ perror
	✔️ isatty
	✔️ ttyname
	✔️ ttyslot
	✔️ ioctl
	✔️ getenv
	✔️ tcsetattr
	✔️ tcgetattr
	✔️ tgetent
	✔️ tgetflag
	✔️ tgetnum
	✔️ tgetstr
	✔️ tgoto
	✔️ tputs


## Shell Requirments:

1. Display **prompt** when waiting for a new command
2. Have a working **history**
3. Search Relative or Absolute PATH variable for right execuatble and run it
4. Use **one global variable** to indicate a received signal
 ```
volatile sig_atomic_t	g_signal = 0;
 ```
* Ensure signal handler will not access main data structure
* Only provides the number of recieved signal
5. Not interpret unclosed quotes or metacharacters (unless specified in subject)
6. A single quote should stop the shell from using metacharacter
```
echo '\\'
echo '$'
```
7. A double quote works like a single quote but doesn't work on '$'
8. Implement **redirections**
* **'>' redirects output**
```
date > specs.txt 
hostname > specs.txt 
```
* **'>>' append mode**
```
hostname > specs.txt 
date >> specs.txt 
```
* **'<' redirects input** 
```
vim mylist.txt
sort < mylist.txt
```
* **'<<' append mode (heredoc)**
```
wc -l << EOF
> all
> the
> small
> things
> EOF
```
9. Implement **pipes** (|) 
* Each commands output is the input of the next command
```
ls | wc -c | cat
```
10. Using **environment variables**
* For example: $TERM, $PATH, $USER
* use 'printenv' to see all environment variables
```
echo $USER
```
11. $? should print the **exit status** of the last executed **foreground** pipeline
12. Handle **ctrl-C**, **ctrl-D**, and **ctrl-\\** the same as bash
* This implies in both interactive and non-interactive modes
* In interactive mode the ctrl keys should:
	* **ctrl-C** displays a new prompt on a new line
	* **ctrl-D** exits the shell
	* **ctrl-\\** does nothing
13. The shell must have the following **builtins**: (do not worry about option unless specify)
* echo -n
	* diplay a line of text without trailing newline
        * ```echo -n a b c $'\n'``` to use the newline 
* cd <path> (relative or absolute path)
	* change the working directory
* pwd
	* print working directory
* export
	* add a variable to environment variables
```
export MY_VAR="Hello World"
env
echo $MY_VAR
echo "The value of MY_VAR is: $MY_VAR"
unset MY_VAR
```
* unset
	* removes a variable from the environment variables
* env (no arguments)
	* print all enviroment variables
* exit
	* exit the minishell

## Resources:

http://hpux.connect.org.uk/hppd/hpux/Gnu/readline-8.2.13/

https://www.linux-magazine.com/Issues/2020/232/Between-the-Lines

https://www.gnu.org/software/libc/manual/html_node/Resource-Usage.html

https://www.qnx.com/developers/docs/6.5.0SP1.update/com.qnx.doc.neutrino_lib_ref/s/sigaction_struct.html#:~:text=The%20sigaction%20structure%20specifies%20how,or%20action%20for%20nonqueued%20signals.

https://www.mkssoftware.com/docs/man5/siginfo_t.5.asp

https://www.codequoi.com/en/sending-and-intercepting-a-signal-in-c/

https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf

https://docs.huihoo.com/doxygen/linux/kernel/3.7/arch_2alpha_2include_2asm_2termios_8h_source.htm

https://www.gnu.org/software/termutils/manual/termcap-1.3/html_chapter/termcap_toc.html

https://invisible-island.net/ncurses/man/terminfo.5.html

## Shell Requirments:

	1. Display **prompt** when waiting for a new command
	2. Have a working **history**
	3. Search Relative or Absolute PATH variable for right execuatble and run it
	4. Use **one global variable** to indicate a received signal
	```
	volatile sig_atomic_t	g_signal = 0;
	```
	- Ensure signal handler will not access main data structure
	- Only provides the number of recieved signal
	5. Not interpret unclosed quotes or metacharacters (unless specified in subject)
	6. A single quote should stop the shell from using metacharacter
	```
	echo '\\'
	echo '$'
	```
	7. A double quote works like a single quote but doesn't work on '$'
	8. Implement **redirections**
	- < redirects input
	- > redirects output 
	- << 

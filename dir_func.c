#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
//#include <.h>

/*
	OPENDIR - open a directory

	DIR	*opendir(const char *name);

	returns a pointer the directory stream

	CLOSERDIR - close a directory

	int	closedir(DIR *dirp);

	returns a 0 on success and -1 on failure (sets errno)

	READDIR - read a directory

	struct dirent	*readdir(DIR *dirp);

	struct direct
	{
		ino_t			d_ino;				// inode number
		off_t			d_off;				// not an offset, see below
		unsigned short	d_reclen;			// length of this record
		unsigned char	d_type;				// type of file, not support in all filesystems
		char			d_name[256];		// null-term filename
	};
*/

void	print_file_type(unsigned char d_type)
{
	if (d_type == DT_REG)
			printf("File Type:\tRegular File\n");
	else if (d_type == DT_DIR)
			printf("File Type:\tDirectory\n");
	else if (d_type == DT_LNK)
			printf("File Type:\tSymbolic Link\n");
	else if (d_type == DT_BLK)
			printf("File Type:\tBlock Device\n");
	else if (d_type == DT_CHR)
			printf("File Type:\tCharacter Device\n");
	else if (d_type == DT_FIFO)
			printf("File Type:\tFIFO/pipe\n");
	else if (d_type == DT_SOCK)
			printf("File Type:\tSocket\n");
	else 
			printf("File Type:\tUnknown\n");
}

int	main(int ac, char **av)
{
	DIR				*dir;
	struct dirent	*data;
	int				count;

	if (ac == 2)
	{
		dir = opendir(av[1]);
		if (!dir)	
		{
			perror("opendir");
			exit(EXIT_FAILURE);
		}
		printf("++ %s ++\n", av[1]);
		while ((data = readdir(dir)) != NULL)
		{
			count++;
			printf("Entry: %d\n", count);
			printf("Inode:\t\t%lu\n", data->d_ino);
			printf("Stream @:\t%lu\n", data->d_off);
			printf("Record Length:\t%hu\n", data->d_reclen);
			print_file_type(data->d_type);
			printf("Name:\t\t%s\n", data->d_name);
			printf("-----------------\n");
		}
	}
	printf("Total Entries: %d\n", count);
	
	if (errno != 0 && data == NULL) 
	{
		perror("readdir");
		closedir(dir);
		exit(EXIT_FAILURE);
	}
	closedir(dir);
	return (0);
}

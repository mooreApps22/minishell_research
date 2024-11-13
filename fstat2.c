#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/*
		FSTAT
		
			int	fstat(int fd, struct stat *buf);

			returns info in the for of a struct stat
			
			return 0 on success & -1 on failure

		struct stat
		{
			dev_t		st_dev;		ID of device containing file
			ino_t		st_ino;		inode number
			mode_t		st_mode;	protection
			nlink_t		st_nlink;	number of hard links
			uid_t		st_uid;		user ID of owner
			gid_t		st_gid;		group ID of owner
			dev_t		st_rdev;	device ID (if special file)
			off_t		st_size;	total size, in bytes
			blksize_t	st_blksize;	blocksize for file system I/O
			blkcnt_t	st_blocks;	number of 512B blocks allocated
			time_t		st_atime;	time of last access
			time_t		st_mtime;	time of last modification
			time_t		st_ctime;	time of last status change
		}
*/

int	is_regular_file(int fd)
{
	struct stat	buf;

	if (fstat(fd, &buf) == -1)
	{
		perror("fstat failed");
		return (-1);
	}
	return (S_ISREG(buf.st_mode));
}

int	is_directory(int fd)
{
	struct stat	buf;

	if (fstat(fd, &buf) == -1)
	{
		perror("fstat failed");
		return (-1);
	}
	return (S_ISDIR(buf.st_mode));
}

int	is_terminal(int fd)
{
	struct stat	buf;

	if (fstat(fd, &buf) == -1)
	{
		perror("fstat failed");
		return (-1);
	}
	return (S_ISCHR(buf.st_mode)) && (isatty(fd) != 0);
}

void	print_test(char *heading, int fd)
{
	printf("Testing %s:\n", heading);
	printf("is_regular_file: %d\n", is_regular_file(fd));
	printf("is_directory: %d\n", is_directory(fd));
	printf("is_terminal: %d\n", is_terminal(fd));
	close(fd);
}


void	test_fd(int fd, char *filename, char *heading, char *err)
{
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(err);
		exit(EXIT_FAILURE);
	}
	print_test(heading, fd);
}

void	test_term(int fd, char *heading, char *err)
{
	if (fd == -1)
	{
		perror(err);
		exit(EXIT_FAILURE);
	}
	print_test(heading, fd);
}

int	main(int ac, char **av)
{
	int	reg_fd;
	int	dir_fd;

	reg_fd = open (av[1], O_RDONLY);
	test_fd(reg_fd, av[1], "regular file", "Error opening regular file");
	test_fd(dir_fd, ".", "directory", "Error opening directory");
	test_term(STDIN_FILENO, "terminal", "Terminal error");
	return (0);
}

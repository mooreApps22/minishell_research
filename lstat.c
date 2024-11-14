#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/*
	LSTAT
		
		int	lstat(const char *restrict path, struct stat *restrict buf);

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

void	print_file_type(const struct stat *buf)
{
	if (S_ISREG(buf->st_mode))
		printf("Regular file\n");	
	else if (S_ISDIR(buf->st_mode))
		printf("Directory\n");	
	else if (S_ISLNK(buf->st_mode))
		printf("Symbolic link\n");	
	else
		printf("Other\n");	
}


int	main(int ac, char **av)
{
	struct stat	buf;
	if (ac != 2)
	{
		printf("Usage: %s <pathway>\n", av[0]);
		return (1);
	}
	if (lstat(av[1], &buf) == -1)
	{
		perror("lstat");
		return (1);
	}
	printf("File type: ");
	print_file_type(&buf);
	return (0);
}

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

int	main(int ac, char **av)
{
	struct stat	*buf;
	int			fd;

	buf = malloc(sizeof(struct stat));
	if (!buf)
	{
		perror("buf didn't malloc");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (!fd)
	{
		perror("file didn't open");
		exit(EXIT_FAILURE);
	}
	if (fstat(fd, buf) == 0)
	{
		printf("File Name:	%s\n", av[1]);
		printf("Device ID:	%ld\n", buf->st_dev);
		printf("Inode #:	%ld\n", buf->st_ino);
		printf("Protection:	%u\n", buf->st_mode);
		printf("Hard links:	%ld\n", buf->st_nlink);
		printf("Owner User ID:	%u\n", buf->st_uid);
		printf("Owner Group ID:	%u\n", buf->st_gid);
		printf("Device ID(SF):	%ld\n", buf->st_rdev);
		printf("Total Bytes:	%ld\n", buf->st_size);
		printf("Blk size I/O:	%ld\n", buf->st_blksize);
		printf("512B blks #:	%ld\n", buf->st_blocks);
		printf("Last access:	%ld\n", buf->st_atime);
		printf("Last mod:	%ld\n", buf->st_mtime);
		printf("Last Stat Chg:	%ld\n", buf->st_ctime);
	}
	else
		printf("Error\n");
	close(fd);
	free(buf);
	return (0);
}

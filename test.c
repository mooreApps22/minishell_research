#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_file_type(const struct stat *buf) {
    if (S_ISREG(buf->st_mode))
        printf("Regular file\n");
    else if (S_ISDIR(buf->st_mode))
        printf("Directory\n");
    else if (S_ISLNK(buf->st_mode))
        printf("Symbolic link\n");
    else
        printf("Other\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct stat buf;
    if (lstat(argv[1], &buf) == -1) {
        perror("lstat");
        return EXIT_FAILURE;
    }

    printf("File type: ");
    print_file_type(&buf);

    if (S_ISLNK(buf.st_mode)) {
        char target[100];
        ssize_t len = readlink(argv[1], target, sizeof(target) - 1);
        if (len == -1) {
            perror("readlink");
            return EXIT_FAILURE;
        }
        target[len] = '\0';
        printf("Symbolic link points to: %s\n", target);
    }

    return EXIT_SUCCESS;
}

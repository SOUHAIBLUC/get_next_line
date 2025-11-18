#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int     fd1;
    int     fd2;
    char    *line1;
    char    *line2;

    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    if (fd1 < 0 || fd2 < 0)
    {
        perror("Error opening file");
        return (1);
    }

    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);
    while (line1 != NULL || line2 != NULL)
    {
        if (line1 != NULL)
        {
            printf("File1: %s\n", line1);
            free(line1);
            line1 = get_next_line(fd1);
        }
        if (line2 != NULL)
        {
            printf("File2: %s", line2);
            free(line2);
            line2 = get_next_line(fd2);
        }
    }

    close(fd1);
    close(fd2);
    return (0);
}
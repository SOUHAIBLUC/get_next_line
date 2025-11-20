#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int     fd1;
    char    *line1;

    fd1 = open("file1.txt", O_RDONLY);

    line1 = get_next_line(fd1);
    while (line1 != NULL)
    {
        printf("File1: %s", line1);
        free(line1);
        line1 = get_next_line(fd1);
    
    }

    close(fd1);
    return (0);
}
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("testmytext.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
    printf("fd: %d\n", fd);
    line = get_next_line(fd);
    int i = 0;
    while(line != NULL)
    {
        // printf("%d: ", i);
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    close(fd);
    return (0);
}
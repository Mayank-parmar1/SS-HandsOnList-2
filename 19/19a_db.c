/*
Name : 19a_db.c
Author : Mayank Parmar
Description : Helper program for Exercise 31a. Initializes the 'database' file
              with ticket number = 0. Run this before running 31a.c.
Date : 23rd Oct, 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    struct { int ticket_no; } database;

    database.ticket_no = 0;

    fd = open("database", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) { perror("open"); exit(1); }

    write(fd, &database, sizeof(database));
    close(fd);

    printf("Database initialized with ticket number = 0\n");

    return 0;
}

/*
Sample Output :

mayank@SPIDEY:~/Downloads/SS_HOL2 2/SS_HOL2/19$ ./31a_db
Database initialized with ticket number = 0

*/

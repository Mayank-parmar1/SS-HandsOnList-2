/*
Name : 16.c
Author : Mayank Parmar
Description : Write a program to remove the message queue using msgctl
              with the IPC_RMID command.
Date : 23rd Oct, 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

int main()
{
    key_t key;
    int msgid;

    key   = ftok("progfile", 65);
    if (key == -1) { perror("ftok"); exit(1); }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) { perror("msgget"); exit(1); }

    printf("Message queue ID before removal: %d\n", msgid);

    /* Remove the message queue */
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl IPC_RMID");
        exit(1);
    }

    printf("Message queue removed successfully.\n");

    return 0;
}

/*
Sample Output :

# Compile
mayank@SPIDEY:~/Downloads/SS_HOL2 2/SS_HOL2/16$ gcc 16.c -o 16
mayank@SPIDEY:~/Downloads/SS_HOL2 2/SS_HOL2/16$ touch progfile

# Send a message first (optional):
mayank@SPIDEY:~/Downloads/SS_HOL2 2/SS_HOL2/16$ ./16_sender
Message sent: Hello from sender!

# Check queue:
mayank@SPIDEY:~/Downloads/SS_HOL2 2/SS_HOL2/16$ ipcs -q
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x410f51a4 65536      mayank  666        100          1

# Remove queue:
mayank@SPIDEY:~/Downloads/SS_HOL2 2/SS_HOL2/16$ ./16
Message queue ID before removal: 65536
Message queue removed successfully.

# Verify removal:
mayank@SPIDEY:~/Downloads/SS_HOL2 2/SS_HOL2/16$ ipcs -q
------ Message Queues --------
(empty — queue has been removed)

*/

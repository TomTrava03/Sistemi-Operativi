#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    /*
    Group system calls

    int getpgid(pid_t pid, pid_t pgid);
    pid_t getpgid(pid_t pid);
    */

    if(isChild()) {
        setpdig(0, 0); // group leader
    }
}


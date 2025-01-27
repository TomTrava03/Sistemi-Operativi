#include <time.h> // time.c
#include <stdio.h>

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    /*-----SYSTEM CALLS-----
    interfaccie con cui i programmi accedono all'hardware
    Ritornano -1 per un ERRORE, errno = -1
    
    - GET TIME:
        time_t time(time_t *second);
        char *ctime(const time_t *timeSeconds);
    */
    time_t theTime;
    time_t whatTime = time(&theTime); // seconds since 1/1/1970, epoch date
    printf("Www Mmm dd hh:mm:ss yyyy -> %s", ctime(&whatTime)); // transform into a readable date-time
    /*
    - WORKING DIRECTORY
        int chdir(const char *path);
        char *getcwd(char *buf, size_t sizeBuf);
    */
    char buffer[100];
    getcwd(buffer, 100); // path to working dir -> buffer
    chdir(".."); // changes working dir ==> cd ..
    /*
    - Duplicazione file descriptors
        int dup(int oldfd);
        int dup2(int oldfd, int newfd);
    */
    int fd = open("FILE", O_RDWR);
    int cpy = dup(fd);
    dup(cpy, 22); // copies cpy into fd 22
    /*
    - PERMESSI
        int chown(const char *pathname, uid_t owner, gid_t group);
        int fchown(int, fd, uid_t owner, gid_t group);
        int chmod(cost char *pathname, mode_t mode); 
        int fchmod(int fd, mode_t mode);
    */
    fchown(fd, 1000, 1000); // new owner -> user:group 1000:1000
    chmod("FILE", S_IRUSR|S_IRGRP|S_IROTH); // permission to r/r/r
    /*
    - PROGRAMS EXECUTION: 
    exec + '' :
        * l : lista di argomenti
        * v : vettore (argomento di argomenti)
        * p : PATH per un binario 
        * e : vettore di variabili d ambiente
    */
    char *env[] = {"CIAO", NULL};
    execle("./execle2.out", "par1", "par2", NULL, env);
    /*
    - CALL SHELL
    int system(const char *string);
    */
    int outcome = system("echo ciao");
    printf("OUTCOME = %d\n", outcome);
    /*-----FORKING-----
    // Generazione di NUOVI processi: fork()   
    
    pid_t getpid(); // del processo FIGLIO
    pid_t getppdid(); // del processo PADRE
    
    // Il PADRE ha il PID del FIGLIO dal ritorno di fork()

    pid_t wait(int *status); // Cambio di Stato di un FIGLIO tramite status, PID del FIGLIO
    - WEXITSTATUS  : STATUS
    - WIFCONTINUED : True if SIGCONT
    - WIFEXITED    : True if ENDED OK
    - WIFSIGNALED  : True if ENDED with Unknown Signal
    - WIFSTOPPED   : True if STOPPED
    - WSTOPSIG     : num of Signal that STOPPED
    - WTERMSIG     : num of Signal that ENDED

    ex. while(wait(NULL)>0); // aspetta TUTTI i FIGLI 
    
    pid_t waitpid(pid_t pid, int *status, int options);
        pid =>
        -n : QUALSIASI nel GRUPPO |-n|
        -1 : QUALSIASI
        0  : QUALSIASI nello STESSO GRUPPO
        n  : FIGLIO PID=n
    */
    return 0;
}


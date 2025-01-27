#include <signal.h>

void custom_handler(int);

int main() {
    /*-----SIGNALS-----
    SIGXXX:
        ALRM :
        CHLD : 
        CONT : 
        INT  :
        KILL :
        STOP :
        TERM :
        USR1 :
        USR2 :

    Possono essere PENDING (da gestire) o BLOCKED (da NON comunicare), "software interrupts"
    DEFAULT HANDLER:
        Ignora il S.
        Termina il P.
        Continuare l'esecuzione
        Stop al P.

    Puo essere modificato "custom" tranne per SIGKILL e SIGSTOP

    sighandler_t signal(int signum, sighandler_t handler);
        SIG_DFL : default
        SIG_IGN : ignora
    
    sighandler_t:
        NULL: SIG_DFL
        1: SIG_IGN
        <address>: if handler = *(address)
    */
    signal(SIGINT, SIG_IGN);
    signal(SIGCHLD, SIG_DFL);

    //using a CUSTOM handler
    signal(SIGINT, custom_handler);
    signal(SIGTSTP, custom_handler);

    /*
    Invio SEGNALI :D
    int kill(pid_t pid, int sig);
    $ kill -<signo> <pid_t>
    pid:
        > 0  : PID=pid
        = 0  : Gruppo del P.
        = -1 : EVERY P.
        < -1 : Gruppo di |pid|
    */ 

    int child = fork();
    kill(child, SIGTERM); // send TERM: default handler
    
    /*
    SIGALRM after seconds
    unsigned int alarm(unsigned int seconds); 
    */
    
    alarm(5);
    
    /*
    Mettere in pausa
    */

    pause();

    /*
    "Blocked signals" : ricevuti, ma non gestiti
    Se voglio BLOCCARE un segnale, modifico la SIGNAL MASK del P. :
    
    int sigprocmask(int how, const sigset_t *restrict set, sigset_t *restrict oldset);
    how:
        SIG_BLOCK   : add set to mask
        SIG_UNBLOCK : delete set from mask
        SIG_SETMASK : set = mask
    */

    sigprocmask(SIG_BLOCK, &mod, &old);

    /*
    A "Blocked Signal" that get sent to the P. becomes a "Pending signal"
    
    int sigpending(sigset_t *set);
    */

    // make a Signal pending by blocking it with sigprocmask thensend it with kill

    sigset_t pending_set;
    sigpending(&pending_set);
    if(sigismember(&pending_set, SIGUSR1)) {
        printf("SIGNAL is pending");
    }

    // unblock it sigprocmask

    /*
    
    sigaction() system call

    int sigaction(int signum, const struct sigaction *restrict act, struct sigaction *restrict oldact);

    struct sigaction {
        void (*sa_handler)(int);
        void (*sa_sigaction)(int, siginfo_t *, void *);
        sigset_t sa_mask;
        int sa_flags;
    };
    */

    struct sigaction sa;
    sa.sa_handler = custom_handler;
    
    sigemptyset(&sa.sa_mask); // define an EMPTY mask
    
    sigaction(SIGUSR1, &sa, NULL);
    kill(getpid(), SIGUSR1);

    /*
    Invio Payload(value) con un Signal
    
    int sigqueue(pid_t pid, int sig, const union sigval value);

    union sigval {
        int sigval_int;
        void *sival_ptr;
    };
    */

    /*

    */

    /*

    */
    return 0;
}

void custom_handler(int signum) {
    if(signum == SIGINT) {
        printf("CTRL+C");
    } else if(signum == SIGTSTP) {
        printf("CTRL+Z");
    }
}


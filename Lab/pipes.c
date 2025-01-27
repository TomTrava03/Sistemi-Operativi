int main() {
    /*
    PIPES ANONIME: uniscono 2 processi aventi un ANTENATO COMUNE 'padre'
    2 fd : scrittura e lettura
    */

    // CREAZIONE
    // int pipe(int pipefd[2]); fd[0] : lettura & fd[1] : scrittura
    
    int fd[2], cnt = 0;
    while(pipe(fd) == 0) { // creazione avvenuta
        cnt++;
    }

    // SCRITTURA
    // int write(int fd[1], char *data, int num);
    
    char buf[50];
    int esito = pipe(fd);
    
    int numOfWritten = write(fd[1], "writing", 8);
    
    // LETTURA
    // int read(int fd[0], char *data, int num);
        
    int r = read(fd[0], &buf, 50); // from pipe to buf

    // per avere BIDIREZIONALITA devi creare 2 pipe!

    /*
    PIPE CON NOME / FIFO :D
    Sono INTERPRETATI come FILE, ma sono delle PIPE!
    */

    // CREAZIONE
    // int mkfifo(const char *pathname, mode_t mode);

    char *fifoName = "/tmp/fifo1";
    mkfifo(fifoName, S_IRUSR|S_IWUSR); // Crea se NON esiste!

    int fd;
    char str1[50], *str = "WRITER";

    // SCRITTURA

    fd = open(fifoName, O_WRONLY);    
    write(fd, str2, strlen(str2)+1); // write str2 to fd FIFO
    close(fd);

    // LETTURA
    
    fd = open(fifoName, O_RDONLY);
    read(fd, str1, 50);
    close(fd);

    /*
    Se il P. che vuole LEGGERE si avvale prima della PIPE rimane "bloccato"
    in attesa del P. che deve SCRIVERE
    
    COMUNICAZIONE:
    writer : 
        open(O_WRONLY)
        write
        close(write)
        open(O_RDONLY)
        read
        close(read)

    reader :
        open(O_RDONLY)
        read
        close(read)
        open(O_WRONLY)
        write
        close(write)
    
    echo "Message for PIPE" > /path/nameOfPipe
    */
    return 0;
}


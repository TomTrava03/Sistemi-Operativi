#include <stdio.h>

int main() {
    /*-----FILES-----
    definiti in stdio.h
    APRIRE: 
        FILE *fopen(const char *filename, const char *mode);
        r : Read
        w : Write or Overwrite
        r+: Read and Write
        w+: Read and Write (Create or Overwrite)
        a : Write at END
        a+: Read and Write at END
    CHIUDERE:
        int fclose(FILE *stream);
    LEGGERE:
        int fgetc(FILE *stream); -> UN carattere
        char *fgets(char *str, int n, FILE *stream); -> Legge per n-1 su "str" 
        int fscanf(FILE *stream, const char *format, ...); -> Salva i dati nelle Variabili (...) seguendo "format"
        int feof(FILE *stream); -> EOF ? 1 : 0
    SCRIVERE:
        int fputc(int char, FILE *stream); -> UN carattere
        int fputs(const char *str, FILE *stream); -> "str" to stream, SENZA il NULL 
        int fprintf(); -> Scrive i dati delle Variabili(...) seguendo "format"
        ...
    FLUSH & REWIND: trascrive il FILE dallo *stream
        Quando succede?
        - return o exit()
        - fprintf(); -> per nuova riga
        - int fflush(FILE *stream);
        - void rewind(FILE *stream);
        - fclose();

    FILE-DESCRIPTOR: FD, un INTERO che descrive un FILE, punta alla rispettiva entry nella FILE-TABLE del SO
    APRIRE:
        int open(const har *pathname, int flags[, mode_t mode]);
        flags: interi  ORED
            O_RDONLY, O_WRONLY, O_RDWR: almeno UNO OBBLIHATORIO
            O_CREAT: esiste ? O_EXCL : crea
            O_APPEND: apre in Append
            O_TRUNC: CANCELLA il contenuto

        mode: interi ORed, privilegi
            S_IRUSR, S_IWUSR, S_IXUSR, S_IRWXU, S_IRGRP, ..., S_IROTH
    CHIUDERE:
        int close(int fd);
    LEGGERE & SCRIVERE
        ssize_t read(int fd, void *buf, size_t count); -> legge e salva su "buf" fino a "count" BYTES di dati
        ssize_t write(int fd, const void *buf, size_t count); -> scrive fino a "count" BYTES 
        off_t lseek(int fd, off_t offset, int whence); -> riposizione l offset in a base a "offset" dalla pos. "whence"
        Offset: 
            SEEK_SET: dall INIZIO FILE
            SEEK_CUR: dalla posizione attuale
            SEEK_END: dalla FINE FILE
    
    FILES: CANALI STANDARD I
    in/out/err -> 0/1/2 -> stdin/stdout/stderr & MACRO: STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO
    int fileno(*stream); -> INDICE di uno "stream"
    */

    /*-----PIPING----
    [|]
    ex. gss src.c -o pip.out
    L'output dell'applicazione di SX diventa l'input dell'applicazione di DX
    */
    return 0;
}

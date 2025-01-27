#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    /*
    MESSAGE QUEUE : ID o queue identifier
        - key              : identifica un insieme di risorse CONDIVISIBILI
        - queue identifier : id della coda, generato dal KERNEL

        Le Code sono PERSISTENTI!
    */

    /*  CREAZIONE
        int msgget(key_t key, int msgflg);
            IPC_CREAT : esiste ? ID : CREA
            IPD_EXCL  : esiste ? ID : err
            0xxx      : permessi di accesso alla coda (analoghi ai FILE!)
        return : identificativo della coda
    */

    key_t queueKey = 56;
    int queueId = msgget(queueKey, 0777|O_CREAT|IPC_EXCL);

    /*  OTTENERE key
        key_t ftok(const char *path, int id);
    */
    
    key_t queueKey = ftok("/tmp/unique", 1);

    // COMUNICAZIONE
    /*
        struct msg_buffer {
            long mtype;
            char mtext[100];
        } message;

        il Payload (ex. mtext) puo essere QUALSIASI cosa (struct, ...) o VUOTO
        
    */
    // INVIO MESSAGGI
    // int msgsnd(int msqid, const void *msgp, size_t msgzs, int msgflg);
    
    // RICEVERE MESSAGGI
    // ssize_t msgrcw(int msgid, const void *msgp, size_t msgsz, long , msgtyp, int msgflg);

    return 0;
}




























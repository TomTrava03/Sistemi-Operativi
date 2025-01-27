#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *fun(void *param){
    return (void *)3;
}

int main() {
    
    /*  CREAZIONE
        int pthread_create(
            pthread_t *restrict thread, // id
            const pthread_attr_t *restrict attr, // attributes
            void *(*start_routine)(*void), // func
            void *restrict arg // parameters of func 
        );
    */

    pthread_t t_id;
    int arg = 10;
    pthread_create(&t_id, NULL, fun, (void *)&arg);

    arg = 20; // La memoria e CONDIVISA, cambia il valore ancher per il Thread!

    /*  TERMINAZIONE
        - void pthread_exit(void *retval);
        - return X; // of fun!
        - exit();
        - Cancellanto il Thread con un altro Thread!
    */
    /*  CANCELLAZIONE
        int pthread_cancel(pthread_t thread);
            cancel STATE e cancel TYPE

        Cambiare cancel STATE
        int pthread_setcancelstate(int state, int *oldstate);
            PTHREAD_CANCEL_ENABLE  : default, type del Thread
            PTHREAD_CANCEL_DISABLE : wait fino a PTHREAD_CANCEL_ENABLE
        
        Cambiare cancel TYPE
        int pthread_setcanceltype(int type int *oldtype);
            PTHREAD_CANCEL_DEFERRED     : default, aspetta un cancellation point
            PTHREAD_CANCEL_ASYNCHRONOUS : terminazione di una richiesta
    */

    /*  ASPETTARE UN THREAD
        int pthread_join(pthread_t thread, void ** retval);
    */

    /*
    

        CAMBIARE IL DETACH STATE 
        int pthread_detach(pthread_t thread); // joinable -> detached, NON invertibile
    */

    pthread_join(t_id, &retFromThread);

    /*  ATTRIBUTI

    
    */

    /*  SINCRONIZZAZIONE CON i MUTEX
        CREAZIONE
        int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);

        DISTRUZIONE
        int pthread_mutex_destroy(pthread_mutex_t *mutex);
    */

    pthread_mutex_init(&lock, NULL);
    pthread_mutex_destroy(&lock);

    /*
        BLOCCAGGIO


        SBLOCCAGGIO

    */

    
    return 0;
}



























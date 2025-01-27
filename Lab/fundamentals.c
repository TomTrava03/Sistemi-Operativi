int main() {
    // CASTING
    float a = 3.5;
    int b = (int)a;

    sizeof(int); // quanto occupa il memoria in BYTES

    int *punt:
    int valore = *(punt);
    long location = &valore;
    int *punt = &valore;

    printf(""); // invio su STDOUT
    fprintf(""); // specifica dove inviare

    #ifdef DEBUG
        printf("");
    #endif
    /*
        possono essere usate a GCC : -D NAME=VALUE -> -D DEBUG=0
    */

    struct Book { // Entita', TUTTI i tipi possono essere usati
        char author[50];
        char title[50];
        int bookID;
    } book1, book2;

    union Result { // Vari DATA-TYPES, uno alla volta
        int intero;
        float decimale;
    } res1, res2;
    /*
        union usa la stessa parte di memoria per TUTTI i tipi, 
        ogni volta che si da un valore ad un membro viene sovrascritto quello usato
        precedentemente
    */

    typedef struct Books {
        // ...
    } bookType;

    bookType book1;

    enum State {
        Undef = 9,
        Working = 1,
        Failed = 0
    };

    enum State s = Undef;

    // void exit(int status); termina il processo

    int arr[4] = {2, 0, 2, 1};
    // arr[0] == *arr;

    char *str; // READ-ONLY, hanno len+1 perche' l'ultimo caraterre '\0'
    char string[] = "ciao"; // writeable
    
}















#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#define STUFF_CAPACITY 60

void clean(){
    setbuf(stdin, 0);
    setbuf(stdout, 0);
    setbuf(stderr, 0);
}

void damaged(){
    char * s = (char *)mmap(NULL, STUFF_CAPACITY, PROT_EXEC|PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
    if(s == MAP_FAILED){
        printf("We don't have enough space for you. Please talk to us!!!\n");
        exit(0);
    }
    printf("Just tell me, your %d byte \n", STUFF_CAPACITY);
    fflush(stdout);
    int len = read(STDIN_FILENO, s, STUFF_CAPACITY);
    if(len == 0){
        printf("Nothing? Bye:(");
        exit(0);
    }
    void (*f)() = (void (*)())s;
    f();
}

int main(int argc, char*argv[]){
    clean();
    printf("Once again, wellcome to HCMUS-CTF!!!\n");
    printf("This challenge, I just reuse some existing challenge, to encourage you some points...\n");
    printf("You also learnt it in the class :)");
    fflush(stdout);
    damaged();
    return 0;
}

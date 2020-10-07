#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#define MB (1024*1024)


int main(int argc, char** argv){
    if(argc != 2){
        printf("usage: ./ex2 <int>");
        return 0;
    }
    void* ptr[10];
    size_t size = atoi(argv[1])*MB;
    struct rusage* usage = malloc(sizeof(struct rusage));
    for(int i = 0; i < 10; i++){
        ptr[i] = malloc(size);
        memset(ptr[i], 0, size);
        getrusage(RUSAGE_SELF, usage);
        printf("maximum resident set size: %ld\n", usage->ru_maxrss);
        printf("\n");
        sleep(1);
    }
    return 0;
}

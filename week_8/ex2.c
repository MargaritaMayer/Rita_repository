#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MB (1024*1024)

int main(int argc, char** argv){
    void* ptr[10];
    size_t size = atoi(argv[1])*MB;
    int i;
    for(i = 0; i < 10; i++){
        ptr[i] = malloc(size);  //allocate 10 MB of memory
        ptr[i] = 0; // fill it with zeros
        memset(ptr[i], i, size);
        sleep(1); //sleep for 1 second
    }
    
    
    return 0;
}

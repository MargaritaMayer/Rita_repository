#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#include <sys/stat.h>

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("too little arguments\n");
        return 0;
    }
    int ind = 1;
    int flags = O_WRONLY|O_CREAT;
    if(strcmp(argv[1], "-a")){
        flags = flags|O_APPEND;
        ind = 2;
    }
    int fcnt = argc - ind;
    int fd[fcnt];
    for(int i = ind; i < argc; i++){
        fd[i - ind] = open(argv[i], flags);
    }
    char str[256];
    while(scanf("%s", str) != EOF){
        printf("%s", str);
        for(int i = 0; i < fcnt; i++){
            write(fd[i], str, strlen(str));
        }
    }
    return 0;

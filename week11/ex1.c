#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(){

    struct stat filestat;
    char str[] = "This is a nice day\n";
    /* stat("./ex1.txt", &filestat); */
    int fd = open("./ex1.txt", O_RDWR);
    ftruncate(fd, sizeof(str));
    char* fp = mmap(NULL, sizeof(str), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    memcpy(fp, str, sizeof(str));


    return 0;
}

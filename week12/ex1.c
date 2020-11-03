#include <stdio.h>

int main(){

    FILE* fp = fopen("/dev/random", "r");
    char str[21];
    for(int i = 0; i < 20; i++){
        str[i] = fgetc(fp);
    }
    str[20] = '\0';
    printf("%s\n", str);
    fclose(fp);
    return 0;
}

#include <stdio.h>
#include <unistd.h>

int main(){
    char str[] = "Hello\n";
    for(int i = 0; i < sizeof(str); i++){
        printf("%c", str[i]);
        sleep(1);
    }
    return 0;
}

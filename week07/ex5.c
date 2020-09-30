#include <stdio.h>
#include <malloc.h>

int main(){
	n = 5;
    char **s = malloc(n*sizeof(char*)) ; 
    char foo[] = "Hello World";
    *s = foo;
    printf("*s is %s\n", *s);
    s[0] = foo;
    printf("s[0] is %s\n", s[0]);
    return (0);
}

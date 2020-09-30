#include <stdlib.h>
#include <stdio.h>

int main()
{
    int N = 0;
    printf("N=");
    scanf("%d", &N);
    int *arr = calloc(N,sizeof(int));
    int i;
    for (i = 1; i <= N; i++) {
        *(arr + i) = i-1;
    }
    for (i = 1; i <= N; i++) {
        printf("%d ",*(arr + i));
    }
    free(arr);
}

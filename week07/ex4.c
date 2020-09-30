#include <stdio.h>
#include <malloc.h>
#include <memory.h>

void* f_realloc(void* ptr, size_t old_size, size_t size) {
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    
    
    
     void* arr = malloc(size);
    if (ptr == NULL) {
    //	arr = maloc(size);
        return arr;
    }
    
    //arr = maloc(size);
    
    if (old_size > size) {
        memcpy(arr, ptr, size);
    }
    else {
        memcpy(arr, ptr, old_size);
    }
    free(ptr);
    return arr;
}


int main() {
    int a = 5;
    int b = 8;
    int* arr = f_realloc(NULL, a*sizeof(*arr) , b * sizeof(*arr)); 
    int i;
    printf("My array:\n");

	for (i = 0; i < a; i++) {
		arr[i]=i*i;
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    arr = malloc(a * sizeof(int));
    printf("Please print new elements\n");
    for (i = 0; i < a; ++i) {
        scanf_s("%d", &arr[i]);
    }
    for (i = 0; i < a; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    arr = f_realloc(arr, a * sizeof(*arr), b * sizeof(*arr));
    arr[1] = 13;
    for (i = 0; i < b; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

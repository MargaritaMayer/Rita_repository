#include <stdio.h>
#include <malloc.h>

void* f_realloc(void* ptr, size_t new_size) {
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
       
    
     void* arr = malloc(new_size);
    if (ptr == NULL) {
        return arr;
    }
      
        memcpy(arr, ptr, new_size);
    free(ptr);
    return arr;
}


int main() {
    int a = 5; //first length
    int b = 8; //second length
    int* arr = f_realloc(NULL, a*sizeof(*arr)); 
    int i;
    printf("Our array:\n");

	for (i = 0; i < a; i++) {
		arr[i]=i*i;
        printf("%d ", arr[i]);
    }
    printf("\n");
   
    printf("Please print new five elements\n");
    for (i = 0; i < a; ++i) {
        scanf_s("%d", &arr[i]);
    }
    printf("Our new array:\n");
    for (i = 0; i < a; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    arr = f_realloc(arr, b * sizeof(*arr));
    printf("Our array with new length:\n");
    for (i = 0; i < b; ++i) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    return 0;
}

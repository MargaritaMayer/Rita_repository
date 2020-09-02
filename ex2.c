#include <stdio.h>

void bubble_sort(int n, int * Arr)
{
    int t, i, j;
    for(i = 0; i < n - 1; i++){
    	for (j = 0; j < n - 1; j++){
    		if (Arr[j] > Arr[j+1]){
    			t = Arr[j];
            	Arr[j] = Arr[j+1];
            	Arr[j+1] = t;
			}
		}
	}

}
int main(){
	
    int a[10];
    printf("Please write 10 numbers\n");
    int i;
	for (i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}
	bubble_sort(10, a);
    printf("After sorting:\n");

	for (i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}
	return 0; 
}
 

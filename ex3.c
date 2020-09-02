#include <stdio.h>
#include<stdlib.h> 
struct Node {
	int value;
	struct Node* next;
};

void push(struct Node** head_ref, void *new_data, size_t data_size) 
{ 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    new_node->value  = malloc(data_size); 
    new_node->next = (*head_ref); 
  
    int i; 
    for (i=0; i<data_size; i++) 
        *(char *)(new_node->value + i) = *(char *)(new_data + i); 
  
    (*head_ref)    = new_node; 
} 

void printInt(void *n){
	printf("%d ", *(int *)n);
}
void print_list(struct Node *node, void (*fptr)(void *)) 
{ 
    while (node != NULL) 
    { 
        (*fptr)(node->value); 
        node = node->next; 
    } 
} 
void insert_node(struct Node** head_ref, void *new_data, size_t data_size) 
{ 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    new_node->value  = malloc(data_size); 
    new_node->next = (*head_ref); 
    int i; 
    for (i=0; i<data_size; i++) 
        *(char *)(new_node->value + i) = *(char *)(new_data + i); 
    (*head_ref)    = new_node; 
} 
int main(){
    int i, n;
    printf ("what is the size of linked list?\n");
    scanf("%d", &n);
    int a[n];
    printf ("printf elements\n");

	for (i = 0; i < n; i++){	
		scanf("%d", &a[i]);
	}
	
	struct Node *start = NULL; 
  	for (i = n - 1; i >= 0; i--) 
       push(&start, &a[i], n); 
       
    printf("Created integer linked list is \n"); 
    print_list(start, printInt);
    
    int new_el;
    printf("\nWhat is the element that you want to insert?\n");
    scanf("%d", &new_el);
    printf("After what element?\n");
     int priv_el;
    scanf("%d", &priv_el);
    int j;
    for (i = 0; i < n; i++){
    	if (a[i] == priv_el){
    		for (j = 0; j <= i; j++)
    			printf("%d ", a[j]);
    		printf("%d ", new_el);
    		for (j = i + 1; j < n; j++)
    			printf("%d ", a[j]);
		}    		
	} 
	printf("\nWhat is the element that you want to delete?\n");
    scanf("%d", &new_el);
     for (i = 0; i < n; i++){
    	if (a[i] == priv_el){
    		for (j = 0; j < i; j++)
    			printf("%d ", a[j]);
    		printf("%d ", new_el);
    		for (j = i + 1; j < n; j++)
    			printf("%d ", a[j]);
		}    		
	} 
	return 0; 
}
 

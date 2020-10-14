#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define COUNTER_SIZE 8
struct page{
    int pagen;
    unsigned long counter : COUNTER_SIZE;
};
typedef struct page* page_table;


int lookup(int pagen, page_table paget, int size){
    int flag = 0;
    for(int i = 0; i < size; i++){
        paget[i].counter /= 2;
        if(pagen == paget[i].pagen){
            paget[i].counter += (int)pow(2, COUNTER_SIZE - 1);
            flag = 1;
        }
    }
    return flag;
}

void load_page(int pagen, page_table paget, int size){
    unsigned int minc = (int)pow(2, COUNTER_SIZE) - 1;
    int pagei = 0;
    for(int i = 0; i < size; i++){
        if(paget[i].counter < minc || paget[i].pagen == -1){
            minc = paget[i].counter;
            pagei = i;
        }
    }
    paget[pagei].pagen = pagen;
    paget[pagei].counter = (int)pow(2, COUNTER_SIZE - 1);
}

int main(int argc, char** argv){
    if(argc < 2){
        printf("Usage: ./ex1 <number of page frames> [path to input file]\n");
        return 0;
    }
    int pagefn = atoi(argv[1]);
    FILE* f;
    if(argc < 3){
        f = fopen("input.txt", "r");
    }
    else{
        f = fopen(argv[2], "r");
    }
    page_table paget = malloc(sizeof(struct page) * pagefn);
    for(int i = 0; i < pagefn; i++){
        paget[i].pagen = -1;
        paget[i].counter = 0;
    }
    int hit = 0;
    int miss = 0;
    int entry;
    while(fscanf(f, "%d", &entry)!= EOF){

        if(lookup(entry, paget, pagefn)){
            hit++;
        }
        else{
            miss++;
            load_page(entry, paget, pagefn);
        }

    }
    fclose(f);
    printf("hits: %d\n", hit);
    printf("misses: %d\n", miss);
    float ratio = hit;
    ratio /= miss;
    printf("hits/misses: %f\n", ratio);
    return 0;
}

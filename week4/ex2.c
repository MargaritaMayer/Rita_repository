#include <stdio.h>
#include <stdlib.h>


//If process "should" execute n fork(), then it should firstly executes processes, which "should" execute n-1, n-2, (and so on) fork().
//In the first case (for 3 fork() executions), - 2 ^ 3 = 8 processes are created.
//In the second case (for 5 fork() executions), - 2 ^ 5 = 32 processes are created.


int main(){
    int i = 0;
    //for(i; i < 3; i++){
    for(i; i < 5; i++){
        fork();
    }
    sleep(5);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

//Since several processor cores are running at the same time, 2 data lines are output in an (almost) unpredictable way.

int main() {
	int n = 10;
	pid_t pid = fork();
	if (pid != 0) {
		int a = getpid();
		printf("Hello from parent [%d", a);
		printf("-%d]\n", n);
		
	}
	else {
		int a = getpid();
		printf("Hello from child [%d", a);
		printf("-%d]\n", n);
	}
	return 0;
}

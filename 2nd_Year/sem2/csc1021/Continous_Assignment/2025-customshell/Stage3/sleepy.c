#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
	int number = atoi(argv[1]);
    sleep(number);
    printf("\nFinished background execution. Sleep for %i seconds over.\n", number);
    return 0;
}

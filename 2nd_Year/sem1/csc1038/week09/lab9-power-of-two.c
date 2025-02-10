#include <stdio.h>
#include <stdlib.h>

int is_power_of_two(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);

    if (is_power_of_two(n)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}


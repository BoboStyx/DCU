#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate_decimal(char *binary[], int count, int *result) {
    *result = 0;
    for (int i = 0; i < count; i++) {
        *result = (*result << 1) | (binary[i][0] - '0');
    }
}

int main(int argc, char *argv[]) {
    int binary_digits_count = argc - 1;

    if (binary_digits_count > 8) {
        printf("Too many binary digits entered.\n");
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        if (strlen(argv[i]) != 1 || (argv[i][0] != '0' && argv[i][0] != '1')) {
            printf("Only digits 1 and 0 are permitted.\n");
            return 0;
        }
    }

    int decimal_value;
    calculate_decimal(argv + 1, binary_digits_count, &decimal_value);

    printf("%d\n", decimal_value);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 20

// Define a struct to store item details
typedef struct {
    char item[MAX_NAME_LENGTH + 1];
    unsigned int amount;
    float price;
    int promotion; // 1 for on sale, 0 for no sale
} ShoppingCartItem;

// Function to parse input and populate the array of items
void parse_input(int argc, char *argv[], ShoppingCartItem *cart, int *num_items) {
    int i = 1; // start from the first item argument
    *num_items = 0;

    while (i < argc && *num_items < MAX_ITEMS) {
        strncpy(cart[*num_items].item, argv[i], MAX_NAME_LENGTH);
        cart[*num_items].item[MAX_NAME_LENGTH] = '\0'; // Null terminate the string
        cart[*num_items].amount = (unsigned int)atoi(argv[i + 1]);
        cart[*num_items].price = atof(argv[i + 2]);
        cart[*num_items].promotion = atoi(argv[i + 3]);

        *num_items += 1;
        i += 4; // Move to the next set of item data
    }
}

// Function to calculate the total price, applying discounts as needed
float calculate_total(const ShoppingCartItem *cart, int num_items) {
    float total = 0.0;

    for (int i = 0; i < num_items; i++) {
        if (cart[i].promotion == 1) {
            // Apply "buy 2, get 1 free" rule for items on sale
            unsigned int payable_amount = (cart[i].amount / 3) * 2 + (cart[i].amount % 3);
            total += payable_amount * cart[i].price;
        } else {
            // Regular pricing for non-promotional items
            total += cart[i].amount * cart[i].price;
        }
    }

    return total;
}

int main(int argc, char *argv[]) {
    if ((argc - 1) % 4 != 0) {
        fprintf(stderr, "Invalid number of arguments.\n");
        return 1;
    }

    ShoppingCartItem cart[MAX_ITEMS];
    int num_items = 0;

    // Parse the command-line arguments
    parse_input(argc, argv, cart, &num_items);

    // Calculate and print the total price
    float total = calculate_total(cart, num_items);
    printf("%.2f\n", total);

    return 0;
}

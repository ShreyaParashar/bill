#include <stdio.h>
#include "billing.h"

void addItemAndDisplayBill(char item_names[][50], float item_prices[], int item_quantities[], int *item_count) {
    if (*item_count >= MAX_ITEMS) {
        printf("Cannot add more items. Maximum limit reached.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", item_names[*item_count]);

    printf("Enter item price: ");
    scanf("%f", &item_prices[*item_count]);

    printf("Enter item quantity: ");
    scanf("%d", &item_quantities[*item_count]);

    (*item_count)++;

    // Display bill logic
    printf("Bill updated with the new item.\n\n");
}

void addMoreItemsToBill(char item_names[][50], float item_prices[], int item_quantities[], int *item_count) {
    if (*item_count >= MAX_ITEMS) {
        printf("Cannot add more items. Maximum limit reached.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", item_names[*item_count]);

    printf("Enter item price: ");
    scanf("%f", &item_prices[*item_count]);

    printf("Enter item quantity: ");
    scanf("%d", &item_quantities[*item_count]);

    (*item_count)++;

    printf("Item added to the bill.\n\n");
}

void displayTotalAmount(float bill_no_tax, float tax) {
    printf("Total Amount without Tax: %.2f\n", bill_no_tax);
    printf("GST Charges: Rs %.2f\n", tax);
    printf("Total Amount with Tax: %.2f\n\n", bill_no_tax + tax);
}

void paymentSummary(float total_amount) {
    float amount_paid;
    printf("Enter amount paid by customer: ");
    scanf("%f", &amount_paid);
    printf("Payment Summary\n");
    printf("Total Bill: %.2f\n", total_amount);
    printf("Total Amount Paid: %.2f\n", amount_paid);
    printf("Amount Returned: %.2f\n\n", amount_paid - total_amount);
}

void printBill(char item_names[][50], float item_prices[], int item_quantities[], int item_count) {
    if (item_count == 0) {
        printf("No items in the bill to print.\n");
        return;
    }

    int registration_num; // Assuming this value will be populated elsewhere
    printf("------------------------------------\n");
    printf("            BILL\n");
    printf("------------------------------------\n");
    printf("Registration number: %d\n", registration_num);
    printf("ITEM               QUANTITY        PRICE\n");
    for (int i = 0; i < item_count; i++) {
        float price_of_one_item = item_prices[i];
        float total_price_of_item = price_of_one_item * item_quantities[i];
        printf("%d) %-15s %-10d Rs%.2f (Rs%.2f each)\n", i + 1, item_names[i], item_quantities[i], total_price_of_item, price_of_one_item);
    }
    printf("\n");
}

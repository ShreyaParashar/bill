#include <stdio.h>
#include "menu.h"
#include "billing.h"

int main() {
    int choice;
    int registration_num;
    float bill_no_tax = 0.0f;
    float tax = 0.0f;

    char item_names[MAX_ITEMS][50];
    float item_prices[MAX_ITEMS];
    int item_quantities[MAX_ITEMS];
    int item_count = 0;

    // Print main menu and get user choice
    do {
        printMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterRegistrationNumber(&registration_num);
                break;
            case 2:
                addItemAndDisplayBill(item_names, item_prices, item_quantities, &item_count);
                break;
            case 3:
                displayTotalAmount(bill_no_tax, tax);
                break;
            case 4:
                paymentSummary(bill_no_tax + tax);
                break;
            case 5:
                addMoreItemsToBill(item_names, item_prices, item_quantities, &item_count);
                break;
            case 6:
                printBill(item_names, item_prices, item_quantities, item_count);
                break;
            case 7:
                printf("Thank you! Visit again!!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);

    return 0;
}

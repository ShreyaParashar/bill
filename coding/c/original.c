#include <stdio.h>
#include <string.h>

// Maximum number of items
#define MAX_ITEMS 50

// Function prototypes
void printMainMenu();
void enterRegistrationNumber(int *);
void addItemAndDisplayBill(char[][50], float[], int[], int[]);
void addMoreItemsToBill(char[][50], float[], int[], int[]);
void displayTotalAmount(float, float);
void paymentSummary(float);
void printBill(char[][50], float[], int[], int);


int main() 
{
    int choice;
    int registration_num;
    float bill_no_tax = 0.0f;
    float tax = 0.0f;

    char item_names[MAX_ITEMS][50];
    float item_prices[MAX_ITEMS];
    int item_quantities[MAX_ITEMS];
    int item_count = 0;

    // Print main menu and get user choice
    
    do 
    {
        printMainMenu();
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


void printMainMenu() 
{
    printf("------------------------------------\n");
    printf("            MAIN MENU\n");
    printf("------------------------------------\n");
    printf("Press 1 to enter customer registration number\n");
    printf("Press 2 to Add Items and display the Bill \n");
    printf("Press 3 to display Total Amount \n");
    printf("Press 4 for Payment Summary \n");
    printf("Press 5 to Add More Items to the Bill\n");
    printf("Press 6 to Print Bill\n");
    printf("Press 7 to Exit\n\n");
}


void enterRegistrationNumber(int *registration_num) 
{
    printf("Enter customer registration number: ");
    scanf("%d", registration_num);
    printf("Registration number is %d\nYou can now add items to the bill.\n\n", *registration_num);
}


void addItemAndDisplayBill(char item_names[][50], float item_prices[], int item_quantities[], int *item_count) 
{
    if (*item_count >= MAX_ITEMS) 
    {
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


void addMoreItemsToBill(char item_names[][50], float item_prices[], int item_quantities[], int *item_count) 
{
    if (*item_count >= MAX_ITEMS) 
    {
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


void displayTotalAmount(float bill_no_tax, float tax) 
{
    bill_no_tax = item_prices [*item_count];
    printf("Total Amount without Tax: %.2f\n", bill_no_tax);
    printf("GST Charges: Rs %.2f\n", tax);
    printf("Total Amount with Tax: %.2f\n\n", bill_no_tax + tax);
}


void paymentSummary(float total_amount) 
{
    float amount_paid;
    printf("Enter amount paid by customer: ");
    scanf("%f", &amount_paid);
    printf("Payment Summary\n");
    printf("Total Bill: %.2f\n", total_amount);
    printf("Total Amount Paid: %.2f\n", amount_paid);
    printf("Amount Returned: %.2f\n\n", amount_paid - total_amount);
}


void printBill(char item_names[][50], float item_prices[], int item_quantities[], int item_count) 
{
    if (item_count == 0) 
    {
        printf("No items in the bill to print.\n");
        return;
    }
    int registration_num;
    printf("------------------------------------\n");
    printf("            BILL\n");
    printf("------------------------------------\n");
    printf("Registration number: %d\n", registration_num);
    printf("ITEM               QUANTITY        PRICE\n");
    for (int i = 0; i < item_count; i++) 
    {
        float price_of_one_item = item_prices[i];
        float total_price_of_item = price_of_one_item * item_quantities[i];
        printf("%d) %-15s %-10d Rs%.2f (Rs%.2f each)\n", i + 1, item_names[i], item_quantities[i], total_price_of_item, price_of_one_item);
    }
    printf("\n");

}

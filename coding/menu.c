#include <stdio.h>
#include "menu.h"

void printMainMenu() {
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

void enterRegistrationNumber(int *registration_num) {
    printf("Enter customer registration number: ");
    scanf("%d", registration_num);
    printf("Registration number is %d\nYou can now add items to the bill.\n\n", *registration_num);
}

#ifndef BILLING_H
#define BILLING_H

#define MAX_ITEMS 50

void addItemAndDisplayBill(char[][50], float[], int[], int[]);
void addMoreItemsToBill(char[][50], float[], int[], int[]);
void displayTotalAmount(float, float);
void paymentSummary(float);
void printBill(char[][50], float[], int[], int);

#endif /* BILLING_H */

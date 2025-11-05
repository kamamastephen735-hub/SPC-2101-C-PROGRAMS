/*
Name STEPHEN M KAMAMA 
Reg no CT100/G/26235/25
COURSE BSC IT 
DESCRIPTION TRANSACTIONS IN A FILE NAMED SALES.YXT
*/

#include <stdio.h>

int main() {
    FILE *file;
    double transaction;
    double totalSales = 0.0;
    int transactionCount = 0;
    
    // Open file for reading
    file = fopen("sales.txt", "r");
    
    if (file == NULL) {
        printf("Error opening sales.txt file!\n");
        return 1;
    }
    
    printf("Reading sales transactions...\n");
    
    // Read all transactions from the file
    while (fscanf(file, "%lf", &transaction) == 1) {
        totalSales += transaction;
        transactionCount++;
        printf("Transaction %d: $%.2f\n", transactionCount, transaction);
    }
    
    // Close the file properly
    fclose(file);
    
    // Display results
    printf("\n--- Daily Sales Summary ---\n");
    printf("Total Transactions: %d\n", transactionCount);
    printf("Total Sales: $%.2f\n", totalSales);
    
    return 0;
}
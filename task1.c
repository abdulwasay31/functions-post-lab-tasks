#include <stdio.h>

void welcome() {
    
    printf("       Welcome to Simple ATM System     \n");
   
}

void displayAmount(float amount) {
    printf("Withdrawal Amount: Rs. %.2f\n", amount);
}

float getWithdrawalLimit() {
    return 50000.0;
}

float calculateBalance(float currentBalance, float withdrawalAmount) {
    return currentBalance - withdrawalAmount;
}

int checkWithdrawal(float currentBalance, float withdrawalAmount, float maxLimit) {
    if (withdrawalAmount > 0 && withdrawalAmount <= currentBalance && withdrawalAmount <= maxLimit) {
        return 1;
    }
    return 0;
}

int main() {
    float balance = 100000.0;
    float amount, maxLimit, newBalance;
    int isValid;

    welcome();

    printf("Current Account Balance: Rs. %.2f\n", balance);

    maxLimit = getWithdrawalLimit();
    printf("Maximum Withdrawal Limit: Rs. %.2f\n", maxLimit);

    printf("\nEnter the amount you want to withdraw: ");
    scanf("%f", &amount);

    displayAmount(amount);

    isValid = checkWithdrawal(balance, amount, maxLimit);

    if (isValid == 1) {
        newBalance = calculateBalance(balance, amount);
        balance = newBalance;
        printf("\nTransaction Successful!\n");
        printf("Remaining Balance: Rs. %.2f\n", balance);
    } else {
        printf("\nTransaction Failed!\n");
        if (amount <= 0) {
            printf("Reason: Amount must be greater than zero.\n");
        } else if (amount > balance) {
            printf("Reason: Insufficient balance.\n");
        } else if (amount > maxLimit) {
            printf("Reason: Amount exceeds maximum withdrawal limit.\n");
        }
        printf("Current Balance remains: Rs. %.2f\n", balance);
    }

    printf("\nThank you for using our ATM!\n");
    return 0;
}

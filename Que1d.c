#include <stdio.h>

void deposit(float* balance, float amount) {
    *balance += amount;
    printf("Deposited: %.2f\n", amount);
}

void withdraw(float* balance, float amount) {
    if (amount > *balance) {
        printf("Insufficient funds!\n");
    } else {
        *balance -= amount;
        printf("Withdrew: %.2f\n", amount);
    }
}

int main() {
    float balance = 1000.0;
    int choice;
    float amount;

    do {
        printf("\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                deposit(&balance, amount);
                break;
            case 2:
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                withdraw(&balance, amount);
                break;
            case 3:
                printf("Balance: %.2f\n", balance);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}

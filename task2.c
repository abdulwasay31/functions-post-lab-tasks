#include <stdio.h>

void welcome() {

    printf("     Welcome to Simple Shopping System      \n");
  
}

void showMenu() {
    printf("1. Laptop          - Rs. 75000\n");
    printf("2. Smartphone      - Rs. 35000\n");
    printf("3. Headphones      - Rs.  4500\n");
    printf("4. Keyboard        - Rs.  2500\n");
    printf("5. Mouse           - Rs.  1200\n");
   
}

float getProductPrice(int choice) {
    if (choice == 1) {
        return 75000.0;
    } else if (choice == 2) {
        return 35000.0;
    } else if (choice == 3) {
        return 4500.0;
    } else if (choice == 4) {
        return 2500.0;
    } else if (choice == 5) {
        return 1200.0;
    } else {
        return 0.0;
    }
}

float calculateItemPrice(float unitPrice, int quantity) {
    return unitPrice * quantity;
}

float calculateSubtotal(float currentSubtotal, float itemTotal) {
    return currentSubtotal + itemTotal;
}

float calculateDiscount(float subtotal) {
    if (subtotal >= 50000) {
        return subtotal * 0.10;
    } else if (subtotal >= 20000) {
        return subtotal * 0.05;
    } else {
        return 0.0;
    }
}

float calculateFinalBill(float subtotal, float discount) {
    return subtotal - discount;
}

void displayReceipt(float subtotal, float discount, float finalBill) {
    
    printf("Subtotal          : Rs. %.2f\n", subtotal);
    printf("Discount          : Rs. %.2f\n", discount);
    
    printf("Final Payable     : Rs. %.2f\n", finalBill);

    printf("Thank you for shopping with us!\n");
}

int wantToContinue() {
    char choice;
    printf("\nDo you want to buy more items? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int choice, quantity;
    float unitPrice, itemTotal, subtotal = 0.0;
    float discount, finalBill;
    int continueShopping = 1;

    welcome();

    while (continueShopping == 1) {
        showMenu();

        printf("Enter product number (1-5): ");
        scanf("%d", &choice);

        unitPrice = getProductPrice(choice);

        if (unitPrice == 0.0) {
            printf("Invalid product selection!\n");
        } else {
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            if (quantity <= 0) {
                printf("Quantity must be greater than zero!\n");
            } else {
                itemTotal = calculateItemPrice(unitPrice, quantity);
                subtotal = calculateSubtotal(subtotal, itemTotal);

                printf("Item Total: Rs. %.2f\n", itemTotal);
                printf("Current Subtotal: Rs. %.2f\n", subtotal);
            }
        }

        continueShopping = wantToContinue();
    }

    if (subtotal > 0) {
        discount = calculateDiscount(subtotal);
        finalBill = calculateFinalBill(subtotal, discount);
        displayReceipt(subtotal, discount, finalBill);
    } else {
        printf("\nNo items purchased. Goodbye!\n");
    }

    return 0;
}

#include <stdio.h>

int main() {
    // starting stock in liters
    float petrol = 100.0;
    float diesel = 150.0;
    float cng = 200.0;

    int choice, refillType;
    float liters;

    printf("=== Fuel Station Management System ===\n");

    while (1) {
        printf("\nAvailable Stock:\n");
        printf("1. Petrol: %.2f liters\n", petrol);
        printf("2. Diesel: %.2f liters\n", diesel);
        printf("3. CNG: %.2f liters\n", cng);

        printf("\nMenu:\n");
        printf("1. Sell Petrol\n");
        printf("2. Sell Diesel\n");
        printf("3. Sell CNG\n");
        printf("4. Refill Stock\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("\nExiting system...\n");
            break;
        }

        switch (choice) {

            // Selling Petrol, Diesel, CNG
            case 1:
            case 2:
            case 3:
                printf("Enter liters required: ");
                scanf("%f", &liters);

                if (choice == 1) {
                    if (liters <= petrol) {
                        petrol -= liters;
                        printf("Petrol filled successfully!\n");
                    } else {
                        printf("Not enough Petrol available!\n");
                    }
                }

                else if (choice == 2) {
                    if (liters <= diesel) {
                        diesel -= liters;
                        printf("Diesel filled successfully!\n");
                    } else {
                        printf("Not enough Diesel available!\n");
                    }
                }

                else if (choice == 3) {
                    if (liters <= cng) {
                        cng -= liters;
                        printf("CNG filled successfully!\n");
                    } else {
                        printf("Not enough CNG available!\n");
                    }
                }
                break;

            // Refill stock
            case 4:
                printf("\nWhich fuel to refill?\n");
                printf("1. Petrol\n2. Diesel\n3. CNG\n");
                printf("Enter type: ");
                scanf("%d", &refillType);

                printf("Enter liters to add: ");
                scanf("%f", &liters);

                switch (refillType) {
                    case 1:
                        petrol += liters;
                        printf("Petrol stock updated.\n");
                        break;
                    case 2:
                        diesel += liters;
                        printf("Diesel stock updated.\n");
                        break;
                    case 3:
                        cng += liters;
                        printf("CNG stock updated.\n");
                        break;
                    default:
                        printf("Invalid fuel type!\n");
                }
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

        // Stop system automatically if all fuel ends
        if (petrol <= 0 && diesel <= 0 && cng <= 0) {
            printf("\nAll fuel types are finished! Closing station...\n");
            break;
        }
    }

    return 0;

}

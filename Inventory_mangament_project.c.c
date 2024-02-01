#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    char name[50];
    float price;
    int quantity;
};

struct Product inventory[MAX_PRODUCTS];
int productCount = 0;

void displayMenu();
void addProduct();
void displayInventory();
void updateProduct();
void deleteProduct();
void saveToFile();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                saveToFile();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n=== Inventory Management System ===\n");
    printf("1. Add Product\n");
    printf("2. Display Inventory\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Save to File\n");
    printf("0. Exit\n");
}

void addProduct() {
    if (productCount < MAX_PRODUCTS) {
        printf("Enter product details:\n");

        printf("Name: ");
        scanf("%s", inventory[productCount].name);

        printf("Price: ");
        scanf("%f", &inventory[productCount].price);

        printf("Quantity: ");
        scanf("%d", &inventory[productCount].quantity);

        printf("Product added successfully!\n");

        productCount++;
    } else {
        printf("Inventory is full. Cannot add more products.\n");
    }
}

void displayInventory() {
    if (productCount > 0) {
        printf("\n=== Inventory ===\n");
        printf(" %-20s %-10s %-10s\n", "Name", "Price", "Quantity");

        for (int i = 0; i < productCount; i++) {
            printf(" %-20s %-10.2f %-10d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
        }
    } else {
        printf("Inventory is empty.\n");
    }
}

void updateProduct() {
    char searchName[50];
    int found = 0;

    printf("Enter the name of the product to update: ");
    scanf("%s", searchName);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("Enter updated quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("Product updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    }
}

void deleteProduct() {
    char deleteName[50];
    int deleteIndex = -1;

    printf("Enter the name of the product to delete: ");
    scanf("%s", deleteName);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, deleteName) == 0) {
            deleteIndex = i;
            break;
        }
    }

    if (deleteIndex != -1) {
        for (int i = deleteIndex; i < productCount - 1; i++) {
            inventory[i] = inventory[i + 1];
        }

        productCount--;
        printf("Product deleted successfully!\n");
    } else {
        printf("Product not found.\n");
    }
}

void saveToFile() {
    FILE *file = fopen("inventory.txt", "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%s %.2f %d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }

    fclose(file);
    

    printf("Inventory saved to file.\n");
}

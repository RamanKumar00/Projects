#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[100];
    char author[100];
    int id;
    int is_available;
} Book;

Book library[MAX_BOOKS];
int num_books = 0;

void addBook() {
    if (num_books < MAX_BOOKS) {
        printf("Enter book title: ");
        scanf(" %[^\n]", library[num_books].title);
        printf("Enter author name: ");
        scanf(" %[^\n]", library[num_books].author);
        library[num_books].id = num_books + 1;
        library[num_books].is_available = 1;
        num_books++;
        printf("Book added successfully!\n");
    } else {
        printf("Library is full. Cannot add more books.\n");
    }
}

void displayBooks() {
    printf("ID\tTitle\t\tAuthor\t\tAvailability\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < num_books; ++i) {
        printf("%d\t%-15s\t%-15s\t%s\n", library[i].id, library[i].title, library[i].author, (library[i].is_available ? "Available" : "Not Available"));
    }
    printf("----------------------------------------------\n");
}

void borrowBook() {
    int bookId;
    printf("Enter the ID of the book you want to borrow: ");
    scanf("%d", &bookId);

    if (bookId >= 1 && bookId <= num_books) {
        if (library[bookId - 1].is_available) {
            library[bookId - 1].is_available = 0;
            printf("Book \"%s\" borrowed successfully!\n", library[bookId - 1].title);
        } else {
            printf("Book \"%s\" is not available for borrowing.\n", library[bookId - 1].title);
        }
    } else {
        printf("Invalid book ID.\n");
    }
}

void returnBook() {
    int bookId;
    printf("Enter the ID of the book you want to return: ");
    scanf("%d", &bookId);

    if (bookId >= 1 && bookId <= num_books) {
        if (!library[bookId - 1].is_available) {
            library[bookId - 1].is_available = 1;
            printf("Book \"%s\" returned successfully!\n", library[bookId - 1].title);
        } else {
            printf("This book is already available in the library.\n");
        }
    } else {
        printf("Invalid book ID.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
    
}

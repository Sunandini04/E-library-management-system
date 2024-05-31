#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store book information
struct Book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

// Function prototypes
void addBook(struct Book library[], int *count);
void displayBooks(struct Book library[], int count);
void listBooksByAuthor(struct Book library[], int count);
void listTotalBooks(int count);

int main() {
    struct Book library[100];
    int choice, count = 0;

    while (1) {
        printf("\n\n********###### WELCOME TO E-LIBRARY #####********\n");
        printf("\n1. Add book information\n");
        printf("2. Display book information\n");
        printf("3. List all books of given author\n");
        printf("4. List the count of books in the library\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                displayBooks(library, count);
                break;
            case 3:
                listBooksByAuthor(library, count);
                break;
            case 4:
                listTotalBooks(count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}

// Function to add a new book to the library
void addBook(struct Book library[], int *count) {
    printf("Enter book title: ");
    scanf("%s", library[*count].title);

    printf("Enter author name: ");
    scanf("%s", library[*count].author);

    printf("Enter number of pages: ");
    scanf("%d", &library[*count].pages);

    printf("Enter price: ");
    scanf("%f", &library[*count].price);

    (*count)++;
    printf("Book added successfully!\n");
}

// Function to display all books in the library
void displayBooks(struct Book library[], int count) {
    printf("List of books in the library:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Author: %s, Pages: %d, Price: $%.2f\n",
               library[i].title, library[i].author, library[i].pages, library[i].price);
    }
}

// Function to list all books by a given author
void listBooksByAuthor(struct Book library[], int count) {
    char author[50];
    printf("Enter author name: ");
    scanf("%s", author);

    printf("Books by author %s:\n", author);
    for (int i = 0; i < count; i++) {
        if (strcmp(author, library[i].author) == 0) {
            printf("Title: %s, Pages: %d, Price: $%.2f\n",
                   library[i].title, library[i].pages, library[i].price);
        }
    }
}

// Function to list the total number of books in the library
void listTotalBooks(int count) {
    printf("Total number of books in the library: %d\n", count);
}


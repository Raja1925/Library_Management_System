#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "book.h"

void loadBooksFromFile(Book **head, char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    int id, year;
    char title[100], author[100], status[20];
    while (fscanf(file, "%d \"%[^\"]\" \"%[^\"]\" %d %s", &id, title, author, &year, status) == 5) {
        addBook(head, id, title, author, year, status);
    }
    fclose(file);
    printf("Books loaded successfully from file.\n");
}

void saveBooksToFile(Book *head, char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error writing to file!\n");
        return;
    }
    Book *temp = head;
    while (temp) {
        fprintf(file, "%d \"%s\" \"%s\" %d %s\n", temp->bookID, temp->title, temp->author, temp->publicationYear, temp->status);
        temp = temp->next;
    }
    fclose(file);
    printf("Library records saved successfully.\n");
}

int isDuplicate(Book *head, int bookID) {
    while (head) {
        if (head->bookID == bookID) return 1;
        head = head->next;
    }
    return 0;
}

void addBook(Book **head, int bookID, char *title, char *author, int publicationYear, char *status) {
    if (isDuplicate(*head, bookID)) {
        printf("Error: Book ID %d already exists!\n", bookID);
        return;
    }

    Book *newBook = (Book*)malloc(sizeof(Book));
    newBook->bookID = bookID;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->publicationYear = publicationYear;
    strcpy(newBook->status, status);
    newBook->next = NULL;

    if (*head == NULL || (*head)->bookID > bookID) {
        newBook->next = *head;
        *head = newBook;
        return;
    }

    Book *current = *head;
    while (current->next && current->next->bookID < bookID) {
        current = current->next;
    }
    newBook->next = current->next;
    current->next = newBook;

    // printf("Book %d Added successfully.\n", bookID);
}

void removeBook(Book **head, int bookID) {
    Book *temp = *head, *prev = NULL;
    while (temp && temp->bookID != bookID) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("Book not found.\n");
        return;
    }
    if (!prev)
        *head = temp->next;
    else
        prev->next = temp->next;
    free(temp);
    printf("Book %d removed successfully.\n", bookID);
}

Book* searchBook(Book *head, int bookID) {
    while (head) {
        if (head->bookID == bookID) return head;
        head = head->next;
    }
    return NULL;
}

void updateBookStatus(Book *head, int bookID, char *newStatus) {
    Book *book = searchBook(head, bookID);
    if (!book) {
        printf("Book not found.\n");
        return;
    }
    strcpy(book->status, newStatus);
    printf("Book %d status updated successfully.\n", bookID);
}

void displayBooks(Book *head) {
    if (!head) {
        printf("No books found.\n");
        return;
    }
    while (head) {
        printf("%d %s %s %d %s\n", head->bookID, head->title, head->author, head->publicationYear, head->status);
        head = head->next;
    }
}

void freeBookList(Book **head) {
    Book *temp;
    while (*head) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

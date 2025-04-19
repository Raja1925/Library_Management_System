#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

void loadBooksFromFile(Book **head, char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return;
    int bookID, year;
    char title[100], author[100], status[20];
    while (fscanf(file, "%d "%[^"]" "%[^"]" %d %s\n", &bookID, title, author, &year, status) == 5) {
        addBook(head, bookID, title, author, year, status);
    }
    fclose(file);
    printf("Books loaded successfully from file.\n");
}

void saveBooksToFile(Book *head, char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) return;
    Book *temp = head;
    while (temp) {
        fprintf(file, "%d "%s" "%s" %d %s\n", temp->bookID, temp->title, temp->author, temp->publicationYear, temp->status);
        temp = temp->next;
    }
    fclose(file);
}

void addBook(Book **head, int bookID, char *title, char *author, int year, char *status) {
    Book *newBook = malloc(sizeof(Book));
    newBook->bookID = bookID;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->publicationYear = year;
    strcpy(newBook->status, status);
    newBook->next = NULL;

    if (*head == NULL || strcmp(title, (*head)->title) < 0) {
        newBook->next = *head;
        *head = newBook;
        return;
    }

    Book *current = *head;
    while (current->next && strcmp(title, current->next->title) > 0)
        current = current->next;

    newBook->next = current->next;
    current->next = newBook;
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
    if (prev) prev->next = temp->next;
    else *head = temp->next;
    free(temp);
    printf("Book %d removed successfully.\n", bookID);
}

Book* searchBook(Book *head, int bookID) {
    while (head && head->bookID != bookID)
        head = head->next;
    return head;
}

void updateBookStatus(Book *head, int bookID, char *newStatus) {
    Book *book = searchBook(head, bookID);
    if (book) {
        strcpy(book->status, newStatus);
        printf("Book %d status updated successfully.\n", bookID);
    } else {
        printf("Book not found.\n");
    }
}

void displayBooks(Book *head) {
    if (!head) {
        printf("No books found.\n");
        return;
    }
    printf("ID\tTitle\tAuthor\tYear\tStatus\n");
    while (head) {
        printf("%d\t%s\t%s\t%d\t%s\n", head->bookID, head->title, head->author, head->publicationYear, head->status);
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
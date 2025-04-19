#ifndef BOOK_H
#define BOOK_H

typedef struct Book {
    int bookID;
    char title[100];
    char author[100];
    int publicationYear;
    char status[20];
    struct Book *next;
} Book;

void loadBooksFromFile(Book **head, char *filename);
void saveBooksToFile(Book *head, char *filename);
void addBook(Book **head, int bookID, char *title, char *author, int publicationYear, char *status);
void removeBook(Book **head, int bookID);
Book* searchBook(Book *head, int bookID);
void updateBookStatus(Book *head, int bookID, char *newStatus);
void displayBooks(Book *head);
void freeBookList(Book **head);

#endif

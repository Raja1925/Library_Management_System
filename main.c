#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

int main() {
    Book *head = NULL;
    loadBooksFromFile(&head, "library.txt");
    displayBooks(head);

    int choice, id, year;
    char title[100], author[100], status[20];

    while (1) {
        printf("\n1. Add Book\n2. Remove Book\n3. Search Book\n4. Update Status\n5. Display Books\n6. Save & Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter Book ID: "); scanf("%d", &id); getchar();
                printf("Enter Title: "); fgets(title, sizeof(title), stdin); title[strcspn(title, "\n")] = 0;
                printf("Enter Author: "); fgets(author, sizeof(author), stdin); author[strcspn(author, "\n")] = 0;
                printf("Enter Publication Year: "); scanf("%d", &year); getchar();
                printf("Enter Status (Available/Borrowed): "); scanf("%s", status);
                addBook(&head, id, title, author, year, status);
                break;
            case 2:
                printf("Enter Book ID to remove: "); scanf("%d", &id);
                removeBook(&head, id);
                break;
            case 3:
                printf("Enter Book ID to search: "); scanf("%d", &id);
                Book *b = searchBook(head, id);
                if (b) {
                    printf("Book Found:\nID: %d\nTitle: %s\nAuthor: %s\nYear: %d\nStatus: %s\n", b->bookID, b->title, b->author, b->publicationYear, b->status);
                } else {
                    printf("Book not found.\n");
                }
                break;
            case 4:
                printf("Enter Book ID: "); scanf("%d", &id);
                printf("Enter new status: "); scanf("%s", status);
                updateBookStatus(head, id, status);
                break;
            case 5:
                displayBooks(head);
                break;
            case 6:
                saveBooksToFile(head, "library.txt");
                freeBookList(&head);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

# Library Management System (C Project)
---
## Description
This project is a command-line-based Library Management System developed in C using singly linked lists and file handling. It allows users to manage book records with features to add, update, search, delete, and display books. Data is persisted in a text file (library.txt).
---

---
## Features
- Add a new book (auto-sorted by *Book Title* but i have changed it into : sorted by *Book ID*)
- Display all books
- Search a book by Book ID
- Update book availability status
- Remove a book
- Save and load books to/from library.txt
---

---
## File Structure

LibraryManagement/
│
├── main.c            # Menu-driven main program
├── book.c            # Book-related logic (load, save, add, remove, update, etc.)
├── book.h            # Header file for book operations
├── library.c         # Additional core logic or UI-related functions
├── library.h         # Header file for library module
├── library.txt       # Text file storing book data persistently
├── library.exe       # Executable file generated after compiling
├── Makefile          # Makefile for building the project
└── README.md         # Documentation and usage instructions
---

---
## How to Compile and Run

# Option-1 --  If You have make installed in your system :- 

### 1. Navigate to the Project Directory:
Replace "file_location" with the actual path of the folder on your system:

    cd "file_location"\RajaKumarSingh_2101793_CEC_TBL2_M2_06-04-25\LibraryManagement


### 2. Compile the Project:
    make

This will generate the executable library.exe.

### 3. Run the Program:
    ./library or ./library.exe


# Option-2 -- If You do not have make installed in your system then :-

### 1. Navigate to the Project Folder/Directory using command prompt(cmd) or PowerShell.

### 2. Run the '.exe' file using :-
        .\library.exe

### 3. If you get an error or nothing appears, try running from 'cmd.exe' instead of PowerShell :
        cmd /c .\library.exe
---

---
## Notes
- Ensure library.txt is in the same directory as the executable.
- All changes to books (add/update/remove) are saved to the file after each operation.
- Input is validated to prevent duplicate Book IDs and maintain sorted order by *Book Title*.
- Proper memory management is implemented to avoid leaks.
---
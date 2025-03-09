# Library Management System

## Overview

This Library Management System is developed in C++ using Object-Oriented Programming (OOP) principles. It allows students, faculty, and librarians to interact with the library system efficiently. The project demonstrates key OOP concepts such as encapsulation, inheritance, and polymorphism while ensuring smooth management of books and users.

## Features

- Role-based access control (Students, Faculty, Librarians)

- Unique usernames for users

- Library management by librarians

- Book borrowing, returning, and reserving

- Fine calculation for overdue books

- Persistent data storage using file I/O

- One-copy-per-book rule

## Class Structure

### 1. `Book` Class

Attributes:

- `Title`, `Author`, `Year`, `ISBN`
- `Availability` (0 = unavailable, 1 = available, 2 = reserved)
- `owner` (tracks who borrowed the book)
- `reserved_by` (tracks who reserved the book)

### 2. `User` Class

Attributes:

- `Name`, `Password`

#### `Student` (Inherits from `User`)

- Borrow a book (Max: 3 books for 15 days, ₹10/day fine for overdue books)
- Return a book
- Reserve a book (Max: 3 reservations)
- Check and clear fines
- Check taken books
- View borrowing history

#### `Faculty` (Inherits from `User`)

- Borrow a book (Max: 5 books for 30 days, no fines but restrictions on overdue books)
- Return a book
- Reserve a book (Max: 3 reservations)
- Check taken books
- View borrowing history

### 3. `Librarian` (Inherits from `User`)

- Add a book
- Remove a book
- Add/Remove a Student or Faculty
- Add a Librarian
- View the library catalog (Books with authors and availability status)

### 4. `Account` Class

- Tracks borrowed books
- Tracks fines (for students) and reserved books

### 5. `Library` Class

- Stores all `Students`, `Faculty`, `Librarians`, and `Books` privately
- Centralized control for all functionalities
- Handles data persistence with `save_data()` and `load_data()` to `library_data.txt`

## System Constraints

- Each username must be unique.
- Only one copy of each book exists.
- Fines follow the defined calculation rules.
- Users can reserve up to 3 books at a time.

## Current Users

### Students

- **Usernames**: S1-S5
- **Passwords**: StudPass1-StudPass5

### Faculty

- **Usernames**: F1-F4
- **Passwords**: FacPass1-FacPass4

### Librarian

- **Username**: Indranil

- **Password**: LibPass1



- `main.cpp`: The main entry point of the program.

- `main.exe`: Compiled executable for running the program.

- `library_data.txt`: Stores persistent library data.

## How to Run

1. Compile the program using a C++ compiler:
   ```sh
    g++ -o main.exe main.cpp
   ```
2. Run the executable:
   ```sh
   ./main.exe
   ```

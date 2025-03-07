#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include <ctime>
#include <iostream>
#include "User.h"
#include "Account.h"
#include "Book.h"
#include "Library.h"

// Forward declaration of Library to prevent circular dependency
class Library;

class Student : public User {
public:
    Account acc;

    Student(std::string name, std::string password);

    void borrow(std::string b, std::time_t l, Library *lib);
    void clear_fine(int pay);
    void return_book(std::string book, std::time_t l, Library *lib);
    void check_fine(std::time_t l);
    void no_of_books();
    void show_books_borrowed();
    void check_history();

private:
    std::time_t get_current_date();
    int days_between(std::time_t start, std::time_t end);
};

#endif // STUDENT_H

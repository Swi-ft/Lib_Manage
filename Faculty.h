#ifndef FACULTY_H
#define FACULTY_H

#include <vector>
#include <string>
#include "User.h"
#include "Account.h"
#include "Library.h"
#include "Book.h"

class Library;

class Faculty : public User {
public:
    Account acc;

    Faculty(std::string name, std::string password);

    void borrow(std::string book, std::time_t l, Library *lib);
    void return_book(std::string book, Library *lib);
    void no_of_books();
    void show_books_borrowed();

private:
    std::time_t get_current_time();
    int days_between(std::time_t start, std::time_t end);
};

#endif // FACULTY_H

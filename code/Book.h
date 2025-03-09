#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    std::string title, author, ISBN;
    int year;
    int avail;
    std::string owner, reserved_by;

    Book(std::string title, std::string author, int year, std::string ISBN);
    Book(std::string title, std::string author, int year, std::string ISBN, int avail);
    Book(std::string title, std::string author, int year, std::string ISBN, int avail, std::string owner);
    Book(std::string title, std::string author, int year, std::string ISBN, int avail, std::string owner, std::string reserved_by);
};

#endif // BOOK_H

#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    std::string title, author, ISBN;
    int year;
    int avail;

    Book(std::string title, std::string author, int year, std::string ISBN);
    Book(std::string title, std::string author, int year, std::string ISBN, int avail);
};

#endif // BOOK_H

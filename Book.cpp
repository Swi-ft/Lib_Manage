#include "Book.h"

Book::Book(std::string title, std::string author, int year, std::string ISBN)
    : title(title), author(author), year(year), ISBN(ISBN), avail(1) {}

Book::Book(std::string title, std::string author, int year, std::string ISBN, int avail)
    : title(title), author(author), year(year), ISBN(ISBN), avail(avail) {}

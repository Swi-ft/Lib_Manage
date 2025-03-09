#include "Book.h"

Book::Book(std::string title, std::string author, int year, std::string ISBN)
    : title(title), author(author), year(year), ISBN(ISBN), avail(1), owner(""), reserved_by("") {}

Book::Book(std::string title, std::string author, int year, std::string ISBN, int avail)
    : title(title), author(author), year(year), ISBN(ISBN), avail(avail), owner(""), reserved_by("") {}

Book::Book(std::string title, std::string author, int year, std::string ISBN, int avail, std::string owner)
    : title(title), author(author), year(year), ISBN(ISBN), avail(avail), owner(owner), reserved_by("") {}

Book::Book(std::string title, std::string author, int year, std::string ISBN, int avail, std::string owner, std::string reserved_by)
    : title(title), author(author), year(year), ISBN(ISBN), avail(avail), owner(owner), reserved_by(reserved_by) {}
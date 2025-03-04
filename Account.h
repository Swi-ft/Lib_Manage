#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include <ctime>
#include "Book.h"

class Account {
public:
    std::vector<Book *> books;
    std::vector<std::time_t> borrow_date;
    int fine;

    Account();

    void add_book(Book *b);
    void push_book(Book *b, std::time_t curr_date);
    int check_fine(std::time_t current_date);
};

#endif // ACCOUNT_H

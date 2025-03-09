#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include <ctime>
#include "Book.h"

class Account {
public:
    std::vector<Book *> books;
    std::vector<std::time_t> borrow_date;
    std::vector<Book *> borrow_history_books;
    std::vector<std::time_t> borrow_history_taken_time;
    std::vector<std::time_t> borrow_history_return_time;
    int reserved;
    int fine;

    Account();
    Account(int fine, int reserved);

    void add_book(Book *b);
    void push_book(Book *b, std::time_t curr_date);
    int check_fine(std::time_t current_date);
    void push_book_history(Book *b, std::time_t taken, std::time_t returned);
    void check_history();
};

#endif // ACCOUNT_H

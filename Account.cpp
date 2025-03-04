#include "Account.h"
#include<iostream>

Account::Account() {
    fine = 0;
}

void Account::add_book(Book *b) {
    books.push_back(b);
    borrow_date.push_back(std::time(nullptr)); // Store current time
}

void Account::push_book(Book *b, std::time_t curr_date) {
    books.push_back(b);
    borrow_date.push_back(curr_date);
}

int Account::check_fine(std::time_t current_date) {
    if (!books.empty()) {
        int x = 0;
        int n = books.size();
        for (int i = 0; i < n; i++) {
            double days = std::difftime(current_date, borrow_date[i]) / (60 * 60 * 24);
            if (days > 15) {
                x += 150 + static_cast<int>(10 * (days - 15));
            }
        }
        return x + fine;
    }
    return fine;
}

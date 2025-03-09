#include "Account.h"
#include<iostream>

Account::Account() {
    fine = 0;
    reserved = 0;
}
Account::Account(int fine, int reserved){
    this->fine = fine;
    this->reserved = reserved;
}

void Account::add_book(Book *b) {
    books.push_back(b);
    borrow_date.push_back(std::time(nullptr));
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
            int days = (int) (std::difftime(current_date, borrow_date[i]) / (60 * 60 * 24));
            if (days > 15) {
                x = x + (10 * (days - 15));
            }
        }
        return x + fine;
    }
    return fine;
}

void Account::push_book_history(Book *b, std::time_t taken, std::time_t returned){
    borrow_history_books.push_back(b);
    borrow_history_taken_time.push_back(taken);
    borrow_history_return_time.push_back(returned);
}

void Account::check_history(){
    int n = borrow_history_books.size();
    for(int i =0;i<n;i++){
        std::cout << borrow_history_books[i]->title << " taken on " << borrow_history_taken_time[i] << " returned on " << borrow_history_return_time[i] << "\n";
    }
}

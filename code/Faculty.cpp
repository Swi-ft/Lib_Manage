#include "Faculty.h"
#include <iostream>
#include <algorithm>

Faculty::Faculty(std::string name, std::string password)
    : User(name, password), acc() {}

void Faculty::borrow(std::string book, std::time_t l, Library *lib) {
    Book *b = lib->get_book(book);
    if (b != nullptr) {
        if (this->acc.books.size() >= 5) {
            std::cout << "Can't borrow book (5 books already borrowed)" << std::endl;
        } else if (this->acc.books.empty()) {
            if (b->avail == 1) {
                this->acc.books.push_back(b);
                this->acc.borrow_date.push_back(l);
                b->avail = 0;
                b->owner = this->name;
                std::cout << "Book " << b->title << " Taken by " << this->name << "!" << std::endl;
            }
            else if(b->avail == 2 && (b->reserved_by == this->name)){
                this->acc.books.push_back(b);
                this->acc.borrow_date.push_back(l);
                b->avail = 0;
                b->owner = this->name;
                std::cout << "Book " << b->title << " Taken by " << this->name << "!" << std::endl;
                this->acc.reserved--;
                b->reserved_by = "";
            }
            else {
                std::cout << "Book not Available" << std::endl;
            }
        } else if (days_between(l, *std::min_element(this->acc.borrow_date.begin(), this->acc.borrow_date.end())) > 30) {
            std::cout << "Can't borrow book (Return book(s) borrowed 30 days or more back)" << std::endl;
        } else {
            if (b->avail == 1) {
                this->acc.books.push_back(b);
                this->acc.borrow_date.push_back(get_current_time());
                b->avail = 0;
                b->owner = this->name;
                std::cout << "Book " << b->title << " Taken by " << this->name << "!" << std::endl;
            }
            else if(b->avail == 2 && (b->reserved_by ==  this->name)){
                this->acc.books.push_back(b);
                this->acc.borrow_date.push_back(get_current_time());
                b->avail = 0;
                b->owner = this->name;
                std::cout << "Book " << b->title << " Taken by " << this->name << "!" << std::endl;
                this->acc.reserved--;
                b->reserved_by = "";
            }
            else {
                std::cout << "Book not Available" << std::endl;
            }
        }
    }
}

void Faculty::check_history(){
    this->acc.check_history();
}

void Faculty::return_book(std::string book, Library *lib, std::time_t l) {
    Book *b = lib->get_book(book);
    if (b != nullptr) {
        auto it = std::find(this->acc.books.begin(), this->acc.books.end(), b);
        if (it == this->acc.books.end()) {
            std::cout << "Wrong Book Name!" << std::endl;
        } else {
            int index = std::distance(this->acc.books.begin(), it);
            this->acc.books.erase(it);
            this->acc.push_book_history(b, *(this->acc.borrow_date.begin() + index), l);
            this->acc.borrow_date.erase(this->acc.borrow_date.begin() + index);
            if(b->avail == 0){
                b->avail = 1;
            }
            b->owner = "";
            std::cout << "Returned " << b->title << " successfully!" << std::endl;
        }
    } else {
        std::cout << "Wrong Book Name!" << std::endl;
    }
}

void Faculty::no_of_books() {
    std::cout << this->acc.books.size() << std::endl;
}

void Faculty::show_books_borrowed() {
    int n = this->acc.books.size();
    if (n == 0) {
        std::cout << "No Books Borrowed" << std::endl;
    } else {
        for (int i = 0; i < n; i++) {
            std::cout << (i + 1) << ". " << this->acc.books[i]->title << " ";
        }
        std::cout << std::endl;
    }
}


void Faculty::show_lib_pub(Library* lib){
    lib->view_library_public();
}

void Faculty::reserve_book(std::string s, Library* lib){
    Book* b = lib->get_book(s);
    int x = this->acc.reserved;
    if(x >= 2){
        std::cout << "You have already reserved 3 books. You can't reserved anymore books!\n";
    }
    else{
        if(b != nullptr){
            if(b->avail == 1 || b->avail == 0){
                std::cout << b->title << " has been resereved\n";
                this->acc.reserved++;
                b->avail = 2;
                b->reserved_by = this->name;
            }
            else if(b->avail == 2){
                std::cout << "This book has already been reserved!\n";
            }
        }
    }
}



std::time_t Faculty::get_current_time() {
    return std::time(nullptr);
}

int Faculty::days_between(std::time_t start, std::time_t end) {
    return std::difftime(end, start) / (60 * 60 * 24);
}

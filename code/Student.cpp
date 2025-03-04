#include "Student.h"
#include <algorithm>
#include <iostream>

Student::Student(std::string name, std::string password)
    : User(name, password), acc() {}

void Student::borrow(std::string b, std::time_t l, Library *lib) {
    int y = this->acc.check_fine(get_current_date());
    if (this->acc.books.size() >= 3) {
        std::cout << "Can't borrow book (3 books already borrowed)" << std::endl;
    } else if (y > 0) {
        std::cout << "Can't borrow book (Please pay fine first)" << std::endl;
    } else {
        Book *book = lib->get_book(b);
        if (book != nullptr) {
            if (book->avail == 1) {
                this->acc.books.push_back(book);
                this->acc.borrow_date.push_back(l);
                book->avail = 0;
                std::cout << "Book " << book->title << " taken by " << this->name << "!" << std::endl;
            } else {
                std::cout << "Book not Available" << std::endl;
            }
        } else {
            std::cout << "Wrong Book Name!" << std::endl;
        }
    }
}

void Student::clear_fine(int pay) {
    std::time_t l = get_current_date();
    int x = this->acc.check_fine(l);
    if (pay <= x) {
        this->acc.fine -= pay;
    } else {
        std::cout << "Payment amount larger than Total fine! Your current fine is " << x << std::endl;
    }
}

void Student::return_book(std::string book, std::time_t l, Library *lib) {
    Book *b = lib->get_book(book);
    if (b != nullptr) {
        auto it = std::find(this->acc.books.begin(), this->acc.books.end(), b);
        if (it == this->acc.books.end()) {
            std::cout << "Wrong Book Name!" << std::endl;
        } else {
            int index = std::distance(this->acc.books.begin(), it);
            int days = days_between(this->acc.borrow_date[index], l);

            if (days > 15) {
                this->acc.fine += (10 * (days - 15) + 150);
            }

            this->acc.books.erase(it);
            this->acc.borrow_date.erase(this->acc.borrow_date.begin() + index);
            std::cout << "Returned " << b->title << " successfully!" << std::endl;
            b->avail = 1;
        }
    } else {
        std::cout << "Wrong Book Name!" << std::endl;
    }
}

void Student::check_fine(std::time_t l) {
    int x = this->acc.check_fine(l);
    std::cout << "Your total fine is: " << x << " units" << std::endl;
}

void Student::no_of_books() {
    std::cout << "Total books borrowed: " << this->acc.books.size() << std::endl;
}

void Student::show_books_borrowed() {
    int n = this->acc.books.size();
    if (n == 0) {
        std::cout << "No Books Borrowed" << std::endl;
    } else {
        for (int i = 0; i < n; i++) {
            std::cout << (i + 1) << ". " << this->acc.books[i]->title << std::endl;
        }
    }
}

std::time_t Student::get_current_date() {
    return std::time(nullptr);
}

int Student::days_between(std::time_t start, std::time_t end) {
    return std::difftime(end, start) / (60 * 60 * 24);
}

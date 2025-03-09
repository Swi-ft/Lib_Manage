#include "Library.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

Book *Library::get_book(std::string title) {
    for (Book *book : books) {
        if (book->title == title) {
            return book;
        }
    }
    std::cout << "Book Doesn't Exist!" << std::endl;
    return nullptr;
}

Librarian *Library::get_librarian(std::string name) {
    for (Librarian *lib : librarians) {
        if (lib->name == name) {
            return lib;
        }
    }
    std::cout << "User Doesn't Exist!" << std::endl;
    return nullptr;
}

Student *Library::get_student(std::string name) {
    for (Student *student : students) {
        if (student->name == name) {
            return student;
        }
    }
    std::cout << "User Doesn't Exist" << std::endl;
    return nullptr;
}

Faculty *Library::get_faculty(std::string name) {
    for (Faculty *fac : faculty) {
        if (fac->name == name) {
            return fac;
        }
    }
    std::cout << "User Doesn't Exist" << std::endl;
    return nullptr;
}

int Library::verify_student(std::string name, std::string password) {
    for (Student *student : students) {
        if (student->name == name) {
            if (student->password == password) {
                std::cout << "Successfully Logged In" << std::endl;
                return 1;
            } else {
                std::cout << "Entered Wrong Password!" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "Entered Wrong Name!" << std::endl;
    return 0;
}

int Library::verify_faculty(std::string name, std::string password) {
    for (Faculty *fac : faculty) {
        if (fac->name == name) {
            if (fac->password == password) {
                std::cout << "Successfully Logged In" << std::endl;
                return 1;
            } else {
                std::cout << "Entered Wrong Password!" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "Entered Wrong Name!" << std::endl;
    return 0;
}

int Library::verify_librarian(std::string name, std::string password) {
    for (Librarian *lib : librarians) {
        if (lib->name == name) {
            if (lib->password == password) {
                std::cout << "Successfully Logged In" << std::endl;
                return 1;
            } else {
                std::cout << "Entered Wrong Password!" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "Entered Wrong Name!" << std::endl;
    return 0;
}

void Library::add_book(Book *b) {
    books.push_back(b);
}

void Library::add_student(Student *s) {
    students.push_back(s);
}

void Library::add_librarian(Librarian *l) {
    librarians.push_back(l);
}

void Library::add_faculty(Faculty *f) {
    faculty.push_back(f);
}


void Library::view_library(){
    for(Book *book : books){
        if(book->avail == 1){
            std::cout << book->title << " by " << book->author << " is " <<"Available\n";
        }
        else{
            std::cout << book->title << " by " << book->author << " is " <<"Owned by : " << book->owner << "\n";
        }
    }
}


void Library::view_library_public(){
    for(Book *book : books){
        if(book->avail == 1){
            std::cout << book->title << " by " << book->author << " is " <<"Available to borrow\n";
        }
        else if(book->avail == 0){
            std::cout << book->title << " by " << book->author << " is " <<"Not Available but can be reserved" << "\n";
        }
        else{
            std::cout << book->title << " by " << book->author << " is " <<"Not Available and can't be reserved" << "\n";
        }
    }
}



void Library::remove_book(std::string title) {
    auto it = std::remove_if(books.begin(), books.end(), [&](Book *book) {
        return book->title == title;
    });
    if (it != books.end()) {
        books.erase(it, books.end());
        std::cout << "Successfully removed " << title << std::endl;
    } else {
        std::cout << "Book not found" << std::endl;
    }
}

void Library::remove_student(std::string name) {
    auto it = std::remove_if(students.begin(), students.end(), [&](Student *student) {
        return student->name == name;
    });
    if (it != students.end()) {
        students.erase(it, students.end());
        std::cout << "Removed Student " << name << std::endl;
    } else {
        std::cout << "User Doesn't Exist" << std::endl;
    }
}

void Library::remove_faculty(std::string name) {
    auto it = std::remove_if(faculty.begin(), faculty.end(), [&](Faculty *fac) {
        return fac->name == name;
    });
    if (it != faculty.end()) {
        faculty.erase(it, faculty.end());
        std::cout << "Removed Faculty " << name << std::endl;
    } else {
        std::cout << "User Doesn't Exist" << std::endl;
    }
}

void Library::show_avail_books() {
    int count = 1;
    for (Book *book : books) {
        if (book->avail == 1) {
            std::cout << count << ". " << book->title << " ";
            count++;
        }
    }
    std::cout << std::endl;
}

void Library::show_avail_books(std::string name) {
    int count = 1;
    for (Book *book : books) {
        if (book->avail == 1) {
            std::cout << count << ". " << book->title << " ";
            count++;
        }
        else if(book->avail == 2 && (book->reserved_by == name)){
            std::cout << count << ". " << book->title << " ";
            count++;
        }
    }
    std::cout << std::endl;
}


void Library::save_data() {
    std::ofstream file("library_data.txt");
    if (!file) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }
    file << "Books\n";
    for (Book *b : books) {
        file << b->title << "," << b->author << "," << b->ISBN  << "," << b->year << ","<< b->avail << "," << b->owner << "," << b->reserved_by <<"\n";
    }
    file << "Students\n";
    for (Student *s : students) {
        Account acc = s->acc;
        file << s->name << "," << s->password << "," << acc.fine << "," << acc.reserved;

        auto &borrowedBooks = acc.books;
        auto &borrowDates = acc.borrow_date;

        file << "," << borrowedBooks.size();
        for (size_t i = 0; i < borrowedBooks.size(); i++) {
            file << "," << borrowedBooks[i]->title << "," << borrowDates[i];
        }
        int x = acc.borrow_history_books.size();
        file << "," << x;
        for (int i = 0; i < x; i++) {
            file << "," << acc.borrow_history_books[i]->title << "," << acc.borrow_history_taken_time[i] << "," << acc.borrow_history_return_time[i];
        }
        file << "\n";
    }
    file << "Faculty\n";
    for (Faculty *f : faculty) {
        Account acc = f->acc;
        file << f->name << "," << f->password << "," << acc.reserved;

        auto &borrowedBooks = acc.books;
        auto &borrowDates = acc.borrow_date;

        file << "," << borrowedBooks.size();
        for (size_t i = 0; i < borrowedBooks.size(); i++) {
            file << "," << borrowedBooks[i]->title << "," << borrowDates[i];
        }
        int x = acc.borrow_history_books.size();
        file << "," << x;
        for (int i = 0; i < x; i++) {
            file << "," << acc.borrow_history_books[i]->title << "," << acc.borrow_history_taken_time[i] << "," << acc.borrow_history_return_time[i];
        }
        file << "\n";
    }
    file << "Librarians\n";
    for (Librarian *l : librarians) {
        file << l->name << "," << l->password << "\n";
    }
    file.close();
    std::cout << "Thank you for using LMS\n";
}

void Library::load_data() {
    std::ifstream file("library_data.txt");
    if (!file) {
        std::cerr << "No previous data found. Starting fresh.\n";
        return;
    }

    std::string line, section;
    while (getline(file, line)) {
        if (line == "Books") section = "Books";
        else if (line == "Students") section = "Students";
        else if (line == "Faculty") section = "Faculty";
        else if (line == "Librarians") section = "Librarians";
        else {
            std::stringstream ss(line);
            std::string name, id, password, owner, reserved_by;
            int year, reserved;
            int avail;
            if (section == "Books") {
                std::string author, isbn;
                getline(ss, name, ',');
                getline(ss, author, ',');
                getline(ss, isbn, ',');
                ss >> year;
                ss.ignore();
                ss >> avail;
                if(avail == 1){
                    books.push_back(new Book(name, author, year, isbn, avail));
                    ss.ignore();
                    ss.ignore();
                }
                else if(avail == 2){
                    ss.ignore();
                    getline(ss, owner, ',');
                    getline(ss, reserved_by, ',');
                    books.push_back(new Book(name, author, year, isbn, avail, owner, reserved_by));
                }
                else{
                    ss.ignore();
                    getline(ss, owner, ',');
                    books.push_back(new Book(name, author, year, isbn, avail, owner));
                }
            } 
            else if (section == "Faculty") {
                getline(ss, name, ',');
                getline(ss, password, ',');
                ss >> reserved;
                ss.ignore();
                Faculty *facultyMember = new Faculty(name, password);
                int numBorrowed, histBorrowed;
                ss >> numBorrowed;
                ss.ignore();

                for (int i = 0; i < numBorrowed; i++) {
                    std::string bookTitle;
                    std::time_t borrowDate;
                    getline(ss, bookTitle, ',');
                    ss >> borrowDate;
                    ss.ignore();
                    Book *borrowedBook = get_book(bookTitle);
                    if (borrowedBook) {
                        facultyMember->acc.books.push_back(borrowedBook);
                        facultyMember->acc.borrow_date.push_back(borrowDate);
                    }
                }
                ss >> histBorrowed;
                ss.ignore();

                for (int i = 0; i < histBorrowed; i++) {
                    std::string bookTitle;
                    std::time_t borrowDate;
                    std::time_t returnDate;
                    getline(ss, bookTitle, ',');
                    ss >> borrowDate;
                    ss.ignore();
                    ss >> returnDate;
                    Book *borrowedBook = get_book(bookTitle);
                    if (borrowedBook) {
                        facultyMember->acc.push_book_history(borrowedBook, borrowDate, returnDate);
                    }
                }
                facultyMember->acc.reserved = reserved;
                if (section == "Faculty") {
                    faculty.push_back(facultyMember);
                }
            }
            else if (section == "Students") {
                int fineAmount;
                getline(ss, name, ',');
                getline(ss, password, ',');
                ss >> fineAmount;
                ss.ignore();
                ss >> reserved;
                ss.ignore();
                Student *S = new Student(name, password);
                int numBorrowed, histBorrowed;
                ss >> numBorrowed;
                ss.ignore();

                for (int i = 0; i < numBorrowed; i++) {
                    std::string bookTitle;
                    std::time_t borrowDate;
                    getline(ss, bookTitle, ',');
                    ss >> borrowDate;
                    ss.ignore();
                    Book *borrowedBook = get_book(bookTitle);
                    if (borrowedBook) {
                        S->acc.books.push_back(borrowedBook);
                        S->acc.borrow_date.push_back(borrowDate);
                    }
                }

                ss >> histBorrowed;
                ss.ignore();

                for (int i = 0; i < histBorrowed; i++) {
                    std::string bookTitle;
                    std::time_t borrowDate;
                    std::time_t returnDate;
                    getline(ss, bookTitle, ',');
                    ss >> borrowDate;
                    ss.ignore();
                    ss >> returnDate;
                    Book *borrowedBook = get_book(bookTitle);
                    if (borrowedBook) {
                        S->acc.push_book_history(borrowedBook, borrowDate, returnDate);
                    }
                }

                S->acc.fine = fineAmount;
                S->acc.reserved = reserved;
                if (section == "Students") {
                    students.push_back(S);
                }
            }
            else if (section == "Librarians") {
                getline(ss, name, ',');
                getline(ss, password, ',');
                librarians.push_back(new Librarian(name, this, password));
            }
        }
    }

    file.close();
    std::cout << "Welcome to the LMS App\n";
}

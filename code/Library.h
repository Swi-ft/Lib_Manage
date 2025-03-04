#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"
#include "Account.h"
#include "Student.h"
#include "Faculty.h"
#include "Librarian.h"

class Library {
private:
    std::vector<Book *> books;
    std::vector<Student *> students;
    std::vector<Faculty *> faculty;
    std::vector<Librarian *> librarians;

public:
    Book *get_book(std::string title);
    Librarian *get_librarian(std::string name);
    Student *get_student(std::string name);
    Faculty *get_faculty(std::string name);

    int verify_student(std::string name, std::string password);
    int verify_faculty(std::string name, std::string password);
    int verify_librarian(std::string name, std::string password);

    void add_book(Book *b);
    void add_student(Student *s);
    void add_librarian(Librarian *l);
    void add_faculty(Faculty *f);

    void remove_book(std::string title);
    void remove_student(std::string name);
    void remove_faculty(std::string name);

    void show_avail_books();

    void save_data();
    void load_data();
};

#endif // LIBRARY_H

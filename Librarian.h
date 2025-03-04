#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <iostream>
#include <string>
#include "User.h"
#include "Library.h"
#include "Student.h"
#include "Faculty.h"
#include "Book.h"

// Forward declarations
class Library;
class Student;
class Faculty;

class Librarian : public User {
private:
    Library *lib;

public:

    Librarian(const std::string name, Library *lib, const std::string password);
    void add_student(const std::string x, const std::string password);
    void add_librarian();
    void add_faculty(const std::string x, const std::string password);
    void add_librarian(const std::string x, const std::string password);
    void add_book(const std::string title, const std::string author, int year, const std::string ISBN);

    void remove_student(const std::string x);
    void remove_faculty(const std::string x);
    void remove_book(const std::string x);

    Student *get_student(const std::string x);
    Faculty *get_faculty(const std::string x);
};

#endif // LIBRARIAN_H

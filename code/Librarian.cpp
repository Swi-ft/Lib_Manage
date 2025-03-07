#include "Librarian.h"
#include <iostream>
#include <algorithm>

Librarian::Librarian(std::string name, Library *lib, std::string password)
    : User(name, password), lib(lib) {}

void Librarian::add_student(std::string x, std::string password) {
    Student *s = lib->get_student(x);
    if (s == nullptr) {
        Student *d = new Student(x, password);
        lib->add_student(d);
        std::cout << "Added Student " << x << std::endl;
    }
    else{
        std::cout << "Name already exists " << std::endl;
    }
}

void Librarian::add_librarian() {
    lib->add_librarian(this);
    std::cout << "Added Librarian " << this->name << std::endl;
}

void Librarian::add_faculty(std::string x, std::string password) {
    Faculty *s = lib->get_faculty(x);
    if (s == nullptr) {
        Faculty *d = new Faculty(x, password);
        lib->add_faculty(d);
        std::cout << "Added Faculty " << x << std::endl;
    }
    else{
        std::cout << "Name already exists "<< std::endl;
    }
}

void Librarian::add_librarian(std::string x, std::string password) {
    Librarian *l = lib->get_librarian(x);
    if (l == nullptr) {
        Librarian *ll = new Librarian(x,lib ,password);
        lib->add_librarian(ll);
        std::cout << "Added Librarian " << x << std::endl;
    }
    else{
        std::cout << "Name already exists " << std::endl;
    }
}

void Librarian::add_book(std::string title, std::string author, int year, std::string ISBN) {
    Book *l = lib->get_book(title);
    if (l == nullptr) {
        Book *ll = new Book(title, author, year, ISBN);
        lib->add_book(ll);
        std::cout << "Added Book " << title << std::endl;
    }
    else{
        std::cout << "Book already exists " << std::endl;
    }
}

void Librarian::remove_student(std::string x) {
    lib->remove_student(x);
}

void Librarian::remove_faculty(std::string x) {
    lib->remove_faculty(x);
}

void Librarian::remove_book(std::string x) {
    lib->remove_book(x);
}

Student *Librarian::get_student(std::string x) {
    return lib->get_student(x);
}

Faculty *Librarian::get_faculty(std::string x) {
    return lib->get_faculty(x);
}

void Librarian::view_library(){
    lib->view_library();
}
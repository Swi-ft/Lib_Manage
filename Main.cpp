#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
#include "User.h"
#include "Account.h"
#include "Book.h"
#include "Library.h"
#include "Faculty.h"
#include "Student.h"
#include "Librarian.h"
#include "User.cpp"
#include "Account.cpp"
#include "Book.cpp"
#include "Library.cpp"
#include "Faculty.cpp"
#include "Student.cpp"
#include "Librarian.cpp"
using namespace std;

std::time_t get_current_date()
{
    return std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

void runApp(Library *lib);
void studentApp(Library *lib, Student *s);
void facultyApp(Library *lib, Faculty *f);
void libApp(Library *lib, Librarian *l);

int main()
{
    Library *lib = new Library();
    lib->load_data();
    runApp(lib);
    lib->save_data();
    return 0;
}

void runApp(Library *lib)
{
    int type;
    std::cout << "Are you a 1.Student 2.Faculty 3.Librarian or 4.Close App?" << std::endl;
    std::cin >> type;
    std::cin.ignore(); // Clear buffer

    std::string name, password;
    if (type == 1 || type == 2 || type == 3)
    {
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Password: ";
        std::getline(std::cin, password);
    }
    
    if (type == 1 && lib->verify_student(name, password))
    {
        Student *stud = lib->get_student(name);
        studentApp(lib, stud);
    }
    else if (type == 2 && lib->verify_faculty(name, password))
    {
        Faculty *fac = lib->get_faculty(name);
        facultyApp(lib, fac);
    }
    else if (type == 3 && lib->verify_librarian(name, password))
    {
        Librarian *l = lib->get_librarian(name);
        libApp(lib, l);
    }
    else if (type == 4)
    {
        return;
    }
    else
    {
        std::cout << "Enter Valid Command." << std::endl;
        runApp(lib);
    }
}

void studentApp(Library *lib, Student *s)
{
    int next;
    std::cout << "1. Borrow a Book, 2. Return a Book, 3. Check Fines, 4. Clear Fines, 5. Check Books, 6. Log-Out?" << std::endl;
    std::cin >> next;
    std::cin.ignore();
    if (next == 1)
    {
        std::string book;
        lib->show_avail_books();
        std::cout << "Enter Book name: ";
        std::getline(std::cin, book);
        s->borrow(book, get_current_date(), lib);
    }
    else if (next == 2)
    {
        std::string book;
        s->show_books_borrowed();
        std::cout << "Enter Book name: ";
        std::getline(std::cin, book);
        s->return_book(book, get_current_date(), lib);
    }
    else if (next == 3)
    {
        s->check_fine(get_current_date());
    }
    else if (next == 4) {
        int amount;
        std::cout << "Enter Amount: ";
        while (!(std::cin >> amount)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a valid integer: ";
        }
        s->clear_fine(amount); 
    }
    else if (next == 5)
    {
        s->show_books_borrowed();
    }
    else if (next == 6)
    {
        runApp(lib);
        return;
    }
    else
    {
        std::cout << "Enter Valid Command." << std::endl;
    }
    studentApp(lib, s);
}

void facultyApp(Library *lib, Faculty *f)
{
    int next;
    std::cout << "1. Borrow a Book, 2. Return a Book, 3. Check Books, 4. Log-Out?" << std::endl;
    std::cin >> next;
    std::cin.ignore();
    if (next == 1)
    {
        std::string book;
        lib->show_avail_books();
        std::cout << "Enter Book name: ";
        std::getline(std::cin, book);
        f->borrow(book, get_current_date(), lib);
    }
    else if (next == 2)
    {
        std::string book;
        f->show_books_borrowed();
        std::cout << "Enter Book name: ";
        std::getline(std::cin, book);
        f->return_book(book, lib);
    }
    else if (next == 3)
    {
        f->show_books_borrowed();
    }
    else if (next == 4)
    {
        runApp(lib);
        return;
    }
    else
    {
        std::cout << "Enter Valid Command." << std::endl;
    }
    facultyApp(lib, f);
}

void libApp(Library *lib, Librarian *l)
{
    int next;
    std::cout << "1. Add Book, 2. Remove Book, 3. Add Student, 4. Remove Student, 5. Add Faculty, 6. Remove Faculty, 7. Add Librarian, 8. Log-Out?" << std::endl;
    std::cin >> next;
    std::cin.ignore();
    if (next == 1)
    {
        std::string name, password, title, author, isbn;
        int year;
        std::cout << "Enter Book Title: ";
        std::getline(std::cin, title);
        std::cout << "Enter Author: ";
        std::getline(std::cin, author);
        std::cout << "Enter Year: ";
        while (!(std::cin >> year)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a valid Year: ";
        }
        std::cout << "Enter ISBN: ";
        std::cin >> isbn;
        std::cin.ignore();
        l->add_book(title, author, year, isbn);
    }
    else if (next == 2)
    {
        std::string title;
        lib->show_avail_books();
        std::cout << "Enter Book name: ";
        std::getline(std::cin, title);
        l->remove_book(title);
    }
    else if (next == 3)
    {   
        std::string name, password;
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Password: ";
        std::getline(std::cin, password);
        l->add_student(name, password);
    }
    else if(next == 4){
        std::string name;
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);
        l->remove_student(name);
    }
    else if (next == 5)
    {   
        std::string name, password;
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Password: ";
        std::getline(std::cin, password);
        l->add_faculty(name, password);
    }
    else if(next == 6){
        std::string name;
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);
        l->remove_faculty(name);
    }
    else if (next == 7)
    {   
        std::string name, password;
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Password: ";
        std::getline(std::cin, password);
        l->add_librarian(name, password);
    }
    else if(next == 8){
        runApp(lib);
        return;
    }
    else{
        std::cout << "Enter Valid Command." << std::endl;
    }
    libApp(lib, l);
}

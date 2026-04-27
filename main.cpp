#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include "Book.h"
#include "User.h"
#include "Library.h"
#include "Customer.h"
#include "Librarian.h"

int main()
{
    Library libr(100);
    Librarian librarian(100, "admin", "admin123");

    librarian.addCustomer(101, "Yousef", "yousef1");
    librarian.addCustomer(102, "Reda" , "reda2");
    librarian.addCustomer(103, "Taha", "taha3");
    librarian.addCustomer(104, "Mostafa", "sasa4");
    librarian.addCustomer(105, "Adham", "adham5");

    libr.addBooks(book("Harry Potter", "JK Rowling", "Fantasy"));
    libr.addBooks(book("The idiot brain", "Dean Burnett", "Science"));
    libr.addBooks(book("Oliver Twist", "Charles Dickens", "fiction"));
    libr.addBooks(book("Great expectations", "Charles Dickens", "fiction"));
    libr.addBooks(book("The Hobbit", "Tolkien", "Fantasy"));

    login(libr, librarian);

    return 0;
}
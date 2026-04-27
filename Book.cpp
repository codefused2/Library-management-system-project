#include "Book.h"

book::book()
{
    title = "None";
    author = "None";
    category = "None";
    is_borrowed = false;
}

book::book(string t, string a, string c)
{
    title = t;
    author = a;
    category = c;
    is_borrowed = false;
}

void book::setTitle(string t) { title = t; }
void book::setAuthor(string a) { author = a; }
void book::setCategory(string c) { category = c; }
void book::setIsBorrowed(bool b) { is_borrowed = b; }

string book::getTitle() const { return title; }
string book::getAuthor() const { return author; }
string book::getCategory() const { return category; }
bool book::isBorrowed() const { return is_borrowed; }
#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include "Book.h"
using namespace std;

class Library{
private:
    book* Books;
    int bookcount;
    int capacity;
public:
    Library(int MAX_BOOKS);
    ~Library();
    void addBooks(const book&b);
    void removeBooks(const string&title);
    void searchByTitle(const string&title);
    void searchByAuthor(const string&author);
    void searchByCategory(const string&category);
    void displayBorrowedBooks();
    void displayNonBorrowed();
    int getBookCount();
    book* getAvailableBook(string title, string author, string category);
};

#endif

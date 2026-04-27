#include "Library.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

Library::Library(int MAX_BOOKS) : capacity(MAX_BOOKS), bookcount(0)
{
    Books = new book[capacity];
}

Library::~Library(){
    delete[]Books;
}

void Library::addBooks(const book&b){
    if(bookcount >= capacity) throw overflow_error("Library is full cannot add more books");
    Books[bookcount++] = b;
}

void Library::removeBooks(const string&title){
    book* newBooks = new book[capacity];
    int counter = 0;
    for(int i=0 ; i<bookcount ; i++){
        if(Books[i].getTitle() != title){
            newBooks[counter] = Books[i];
            counter++;
        }
    }
    delete[] Books;
    Books = newBooks;
    bookcount = counter;
}

void Library::searchByTitle(const string&title){
    bool found = false;
    string lowTitle = title;
    transform(lowTitle.begin(), lowTitle.end(), lowTitle.begin(), ::tolower);
    cout << "\n--- Search results for title: " << title << " ---" << endl;
    for(int i=0 ; i<bookcount ; i++){
        string lowOgTitle = Books[i].getTitle();
        transform(lowOgTitle.begin(), lowOgTitle.end(), lowOgTitle.begin(), ::tolower);
        if(Books[i].getTitle() == title || lowOgTitle == lowTitle){
            cout << "Title: " << Books[i].getTitle() 
                 << " | Author: " << Books[i].getAuthor() 
                 << " | Category: " << Books[i].getCategory() << endl;
            found = true;
        }
    }
    if (!found) cout << "Sorry, book is not found" << endl;
}

void Library::searchByAuthor(const string&author){
    bool found = false;
    string lowAuthor = author;
    transform(lowAuthor.begin(), lowAuthor.end(), lowAuthor.begin(), ::tolower);
    cout << "\n--- Search results for author: " << author << " ---" << endl;
    for(int i=0 ; i<bookcount ; i++){
        string lowOgAuthor = Books[i].getAuthor();
        transform(lowOgAuthor.begin(), lowOgAuthor.end(), lowOgAuthor.begin(), ::tolower);
        if(Books[i].getAuthor() == author || lowOgAuthor == lowAuthor){
            cout << "Title: " << Books[i].getTitle() 
                 << " | Author: " << Books[i].getAuthor() 
                 << " | Category: " << Books[i].getCategory() << endl;
            found = true;
        }
    }
    if (!found) cout << "Sorry, book is not found" << endl;
}

void Library::searchByCategory(const string&category){
    bool found = false;
    string lowCategory = category;
    transform(lowCategory.begin(), lowCategory.end(), lowCategory.begin(), ::tolower);
    cout << "\n--- Search results for category: " << category << " ---" << endl;
    for(int i=0 ; i<bookcount ; i++){
        string lowOgCategory = Books[i].getCategory();
        transform(lowOgCategory.begin(), lowOgCategory.end(), lowOgCategory.begin(), ::tolower);
        if(Books[i].getCategory() == category || lowOgCategory == lowCategory){
            cout << "Title: " << Books[i].getTitle() 
                 << " | Author: " << Books[i].getAuthor() 
                 << " | Category: " << Books[i].getCategory() << endl;
            found = true;
        }
    }
    if (!found) cout << "Sorry, book is not found" << endl;
}

void Library::displayBorrowedBooks(){
    cout << "\n--- Borrowed books ---" << endl;
    bool found = false;
    for(int i=0 ; i < bookcount ; i++){
        if(Books[i].isBorrowed()){
            cout << "Title: " << Books[i].getTitle() 
                 << " | Author: " << Books[i].getAuthor() 
                 << " | Category: " << Books[i].getCategory() << endl;
            found = true;
        }
    }
    if(!found) cout << "No borrowed books found." << endl;
}

void Library::displayNonBorrowed(){
    cout << "\n--- Available books ---" << endl;
    bool found = false;
    for(int i=0 ; i < bookcount ; i++){
        if(!Books[i].isBorrowed()){
            cout << "Title: " << Books[i].getTitle() 
                 << " | Author: " << Books[i].getAuthor() 
                 << " | Category: " << Books[i].getCategory() << endl;
            found = true;
        }
    }
    if(!found) cout << "No available books found." << endl;
}

int Library::getBookCount() { return bookcount; }

book* Library::getAvailableBook(string title, string author, string category)
{
    string lowTitle = title;
    string lowAuthor = author;
    string lowCategory = category;

    transform(lowTitle.begin(), lowTitle.end(), lowTitle.begin(), ::tolower);
    transform(lowAuthor.begin(), lowAuthor.end(), lowAuthor.begin(), ::tolower);
    transform(lowCategory.begin(), lowCategory.end(), lowCategory.begin(), ::tolower);

    for (int i = 0; i < bookcount; i++)
    {
        string lowOgTitle = Books[i].getTitle();
        string lowOgAuthor = Books[i].getAuthor();
        string lowOgCategory = Books[i].getCategory();

        transform(lowOgTitle.begin(), lowOgTitle.end(), lowOgTitle.begin(), ::tolower);
        transform(lowOgAuthor.begin(), lowOgAuthor.end(), lowOgAuthor.begin(), ::tolower);
        transform(lowOgCategory.begin(), lowOgCategory.end(), lowOgCategory.begin(), ::tolower);

        if ((Books[i].getTitle() == title || lowOgTitle == lowTitle) &&
            (Books[i].getAuthor() == author || lowOgAuthor == lowAuthor) &&
            (Books[i].getCategory() == category || lowOgCategory == lowCategory) &&
            !Books[i].isBorrowed()) return &Books[i];
    }
    cout << "Sorry, this book is not available right now!" << endl;
    return nullptr;
}
#include "Customer.h"
#include <iostream>

Customer::Customer(): User(0, "", ""), borrowedCount(0){}

Customer::Customer(int id, const string& name, const string& pass): User(id, name, pass), borrowedCount(0){}

void Customer::available_books(Library& libr) {
    libr.displayNonBorrowed();
}

void Customer::search_by_title(Library& libr, const string& title) {
    libr.searchByTitle(title);
}

void Customer::search_by_author(Library& libr, const string& author) {
    libr.searchByAuthor(author);
}

void Customer::search_by_category(Library& libr, const string& category) {
    libr.searchByCategory(category);
}

bool Customer::borrow_book(Library& libr, const string& title, const string& author, const string& category){
    if (borrowedCount >= 5) throw overflow_error("you can't borrow more than 5 books.\n");

    for (int i = 0; i < borrowedCount; i++) {
        if (borrowedBooks[i].getTitle() == title) {
            cout << "you already have " << title << ".\n";
            return false;
        }
    }
    book* availableBook = libr.getAvailableBook(title, author, category);
    if (!availableBook) {
        return false;
    }
    
    availableBook->setIsBorrowed(true);
    libr.removeBooks(title);

    book b(title, author, category);
    b.setIsBorrowed(true);
    borrowedBooks[borrowedCount++] = b;

    cout << "Borrowed: " << title << "\n";
    return true;
}

bool Customer::return_book(Library& libr, const string& title) {
    int idx = -1;
    for (int i = 0; i < borrowedCount; i++) {
        if (borrowedBooks[i].getTitle() == title) {
            idx = i;
            break;
        }
    }
    if (idx < 0) {
        cout << "You have not borrowed " << title << ".\n";
        return false;
    }
    borrowedBooks[idx].setIsBorrowed(false);
    libr.addBooks(borrowedBooks[idx]);

    for (int j = idx; j + 1 < borrowedCount; j++) {
        borrowedBooks[j] = borrowedBooks[j + 1];
    }
    borrowedCount--;

    cout << "returned: " << title << "\n";
    return true;
}

void Customer::view_borrowed_books() const {
    cout << "\n--- My borrowed books ---" << endl;
    if (borrowedCount == 0) {
        cout << "You have no borrowed books." << endl;
        return;
    }
    for (int i = 0; i < borrowedCount; i++) {
        const book& b = borrowedBooks[i];
        cout << "Title: " << b.getTitle() 
             << " | Author: " << b.getAuthor() 
             << " | Category: " << b.getCategory() << endl;
    }
}

int Customer::get_borrowed_count() const {
    return borrowedCount;
}

void Customer::show_customer_info() const {
    cout << "\n--- Customer Information ---" << endl;
    cout << "User ID: " << getUserId() << endl;
    cout << "Username: " << getUsername() << endl;
    cout << "Borrowed: " << borrowedCount << "/5" << endl;
    cout << "------------------------" << endl;
    view_borrowed_books();
}
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Book.h"
#include "Library.h"
using namespace std;

class Customer : public User {
private:
    book borrowedBooks[5];
    int  borrowedCount;

public:
    Customer();
    Customer(int id, const string& name, const string& pass);

    void available_books(Library& libr);
    void search_by_title(Library& libr, const string& title);
    void search_by_author(Library& libr, const string& author);
    void search_by_category(Library& libr, const string& category);

    bool borrow_book(Library& libr, const string& title, const string& author, const string& category);
    bool return_book(Library& libr, const string& title);
    void view_borrowed_books() const;
    int get_borrowed_count() const;
    void show_customer_info() const;
};

#endif

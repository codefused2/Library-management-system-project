#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "User.h"
#include "Customer.h"
#include "Library.h"
#include "Book.h"
using namespace std;

class Librarian : public User
{
private:
    Customer* customers;
    int customerCount, maxCustomers;

public:
    Librarian(int id, string name, string pass, int maxCust = 100);
    ~Librarian();

    bool addCustomer(int id, string name, string pass);
    bool removeCustomer(int id);
    void viewCustomerData(int id);
    void addBook(Library &libr, book b);
    void removeBook(Library &libr, string title);
    void viewAllBooks(Library &libr);
    void viewBorrowedBooks(Library &libr);
    void viewNonBorrowedBooks(Library &libr);
    void searchByTitle(Library &libr, string title);
    void searchByAuthor(Library &libr, string author);
    void searchByCategory(Library &libr, string category);
    int getCustomerCount() const;
    Customer &getSpecificCust(int index);
};

bool librarianOptions(Library &libr, Librarian &librarian);
bool customerOptions(Library &libr, Customer &customer);
void login(Library &libr, Librarian &librarian);

#endif

#include "Librarian.h"
#include <iostream>
#include <stdexcept>

Librarian::Librarian(int id, string name, string pass, int maxCust) : User(id,name,pass)
{
    customers = new Customer[maxCust];
    customerCount = 0;
    maxCustomers = maxCust;
}

Librarian::~Librarian() {delete[] customers;}

bool Librarian::addCustomer(int id, string name, string pass)
{
    if (customerCount >= maxCustomers) throw overflow_error("Library is full, cannot add new customer");
    customers[customerCount] = Customer(id, name, pass);
    customerCount++;
    return true;
}

bool Librarian::removeCustomer(int id)
{
    bool customerFound = false;
    int newCustomerCount = 0;
    Customer* newCustomers = new Customer[maxCustomers];
    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].getUserId() != id)
        {
            newCustomers[newCustomerCount] = customers[i];
            newCustomerCount++;
        }
        else customerFound = true;
    }

    delete[] customers;
    customers = newCustomers;
    customerCount = newCustomerCount;

    if (customerFound)
    {
        cout << "Customer removed successfully!" << endl;
        return true;
    }
    else
    {
        cout << "Customer not found" << endl;
        return false;
    }
}

void Librarian::viewCustomerData(int id)
{
    bool found = false;
    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].getUserId() == id)
        {
            cout << "\n--- Customer Details ---" << endl;
            customers[i].show_customer_info();
            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "Customer not found" << endl;
    }
}

void Librarian::addBook(Library &libr, book b)
{
    libr.addBooks(b);
    cout << "Book added successfully!" << endl;
}

void Librarian::removeBook(Library &libr, string title)
{
    libr.removeBooks(title);
    cout << "Book removed successfully!" << endl;
}

void Librarian::viewAllBooks(Library &libr)
{
    cout << "\n--- Library's books ---" << endl;
    libr.displayBorrowedBooks();
    libr.displayNonBorrowed();
}

void Librarian::viewBorrowedBooks(Library &libr) {libr.displayBorrowedBooks();}

void Librarian::viewNonBorrowedBooks(Library &libr) {libr.displayNonBorrowed();}

void Librarian::searchByTitle(Library &libr, string title) {libr.searchByTitle(title);}

void Librarian::searchByAuthor(Library &libr, string author) {libr.searchByAuthor(author);}

void Librarian::searchByCategory(Library &libr, string category) {libr.searchByCategory(category);}

int Librarian::getCustomerCount() const {return customerCount;}

Customer &Librarian::getSpecificCust(int index) {return customers[index];}

bool librarianOptions(Library &libr, Librarian &librarian)
{
    int option;
    while (true)
    {
        int id;
        string title, author, category, name, password;

        cout << "\n=== LIBRARIAN MENU ===" << endl;
        cout << "1-Add book\n2-Remove book\n3-View all books\n4-View borrowed books\n5-View non borrowed books\n6-Add customer" << endl;
        cout << "7-Remove customer\n8-View customer data\n9-Search by title\n10-Search by author\n11-Search by category\n12-Back to login\n0-Logout\n" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cin.ignore();
        cout << "\n";

        if (option == 1)
        {
            cout << "===== Add Book =====" << endl;
            cout << "Enter the book's name: ";
            getline(cin, title);
            cout << "Enter book's author: ";
            getline(cin, author);
            cout << "Enter book's category: ";
            cin >> category;
            try {librarian.addBook(libr, book(title,author,category));}
            catch(overflow_error& error)
            {
                cout << error.what() << endl;
            }
        }
        else if (option == 2)
        {
            cout << "===== Remove Book =====" << endl;
            cout << "Enter the book's name: ";
            getline(cin, title);
            libr.removeBooks(title);
        }
        else if (option == 3)
        {
            cout << "===== All Books =====" << endl;
            librarian.viewAllBooks(libr);
        }
        else if (option == 4)
        {
            cout << "===== Borrowed Books =====" << endl;
            librarian.viewBorrowedBooks(libr);
        }
        else if (option == 5)
        {
            cout << "===== Available Books =====" << endl;
            librarian.viewNonBorrowedBooks(libr);
        }
        else if (option == 6)
        {
            cout << "===== Add Customer =====" << endl;
            cout << "Enter customer's name: ";
            getline(cin, name);
            cout << "Enter customer's id: ";
            cin >> id;
            cout << "Enter customer's password: ";
            cin >> password;
            try {librarian.addCustomer(id, name, password);}
            catch(overflow_error& error)
            {
                cout << error.what() <<endl;
                cout << "Customer added successfully to the library!" << endl;
            }
        }
        else if (option == 7)
        {
            cout << "===== Remove Customer =====" << endl;
            cout << "Enter customer's id: ";
            cin >> id;
            librarian.removeCustomer(id);
        }
        else if (option == 8)
        {
            cout << "===== Customer Data =====" << endl;
            cout << "Enter customer's id: ";
            cin >> id;
            librarian.viewCustomerData(id);
        }
        else if (option == 9)
        {
            cout << "===== Search By Title =====" << endl;
            cout << "Enter the book's name: ";
            getline(cin, title);
            librarian.searchByTitle(libr, title);
        }
        else if (option == 10)
        {
            cout << "===== Search By Author =====" << endl;
            cout << "Enter book's author: ";
            getline(cin, author);
            librarian.searchByAuthor(libr, author);
        }
        else if (option == 11)
        {
            cout << "===== Search By Category =====" << endl;
            cout << "Enter book's category: ";
            cin >> category;
            librarian.searchByCategory(libr, category);
        }
        else if (option == 12) {return true;}
        else if (option == 0)
        {
            cout << "Logged out" << endl;
            break;
        }
        else cout << "Invalid input" << endl;
    }
    return false;
}

bool customerOptions(Library &libr, Customer &customer)
{
    int option;
    while (true)
    {
        string title, author, category;

        cout << "\n=== CUSTOMER MENU ===" << endl;
        cout << "1-View available books\n2-Search by title\n3-Search by author\n4-Search by category\n5-Borrow a book\n6-Return a book" << endl;
        cout << "7-View borrowed books\n8-Show customer info\n9-Back to login\n0-Logout\n" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cin.ignore();
        cout << "\n";

        if (option == 1)
        {
            cout << "===== Available Books =====" << endl;
            customer.available_books(libr);
        }
        else if (option == 2)
        {
            cout << "===== Search By Title =====" << endl;
            cout << "Enter book's name: ";
            getline(cin, title);
            customer.search_by_title(libr, title);
        }
        else if (option == 3)
        {
            cout << "===== Search By Author =====" << endl;
            cout << "Enter the author's name: ";
            getline(cin, author);
            customer.search_by_author(libr, author);
        }
        else if (option == 4)
        {
            cout << "===== Search By Category =====" << endl;
            cout << "Enter the category: ";
            getline(cin, category);
            customer.search_by_category(libr, category);
        }
        else if (option == 5)
        {
            cout << "===== Borrow a Book =====" << endl;
            cout << "Enter book's name: ";
            getline(cin, title);
            cout << "Enter the author's name: ";
            getline(cin, author);
            cout << "Enter the category: ";
            getline(cin, category);
            try {customer.borrow_book(libr, title, author, category);}
            catch(overflow_error& error)
            {
                cout << error.what() << endl;
            }
        }
        else if (option == 6)
        {
            cout << "===== Return a Book =====" << endl;
            cout << "Enter book's name: ";
            getline(cin, title);
            customer.return_book(libr, title);
        }
        else if (option == 7)
        {
            cout << "===== My Borrowed Books =====" << endl;
            customer.view_borrowed_books();
        }
        else if (option == 8)
        {
            cout << "===== Customer Information =====" << endl;
            customer.show_customer_info();
        }
        else if (option == 9) {return true;}
        else if (option == 0)
        {
            cout << "Logged out" << endl;
            break;
        }
        else cout << "Invalid input" << endl;
    }
    return false;
}

void login(Library &libr, Librarian &librarian)
{
    cout << "\n=== LIBRARY LOGIN ===" << endl;
    cout << "Welcome to our library :)\n" << endl;
    while (true) {
        bool librarianFound = false;
        bool customerFound = false;
        string password, username;
        cout << "Please enter your username: ";
        getline(cin, username);
        cout << "Please enter your password: ";
        cin >> password;
        cin.ignore();
        cout << "\n";

        if (librarian.login(username, password))
        {
            cout << "---------------------------------" << endl;
            cout << "      Welcome admin!" << endl;
            cout << "---------------------------------" << endl;
            bool backToLogin = librarianOptions(libr, librarian);
            librarianFound = true;
            if (backToLogin)
            {
                login(libr, librarian);
                return;
            }
            else return;
        }
        for (int i = 0; i < librarian.getCustomerCount(); i++)
        {
            if (librarian.getSpecificCust(i).login(username, password))
            {
                cout << "---------------------------------" << endl;
                cout << "      Welcome " << username << "!" << endl;
                cout << "---------------------------------" << endl;
                bool backToLogin = customerOptions(libr, librarian.getSpecificCust(i));
                customerFound = true;
                if (backToLogin)
                {
                    login(libr, librarian);
                    return;
                }

                else return;
            }
        }
        if (!librarianFound && !customerFound) cout << "Invalid username or password, please try again!" << endl;
    }
}

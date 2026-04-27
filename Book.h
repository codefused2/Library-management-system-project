#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class book
{
private:
    string title;
    string author;
    string category;
    bool is_borrowed;

public:
    book();
    book(string t, string a, string c);

    void setTitle(string t);
    void setAuthor(string a);
    void setCategory(string c);
    void setIsBorrowed(bool b);

    string getTitle() const;
    string getAuthor() const;
    string getCategory() const;
    bool isBorrowed() const;
};

#endif

# Library-management-system-project

1-About the project: 
This is a C++ project that uses OOP to simulate a library management 
system.  
The user can be a: 
- librarian who can: Add/remove a book - Add/remove a customer  - View any customer’s data  - Search for a book.
- customer who can:  borrow/return a book - Search for books  - View his borrowed books.
  
This was implemented using 5 classes which are: 
- book class: stores information about a book.
- User class: essential for the login system and the base class for librarian and customer classes.
- Library class: manages everything about the library books by providing the display, search, adding a book, and removing a book 
methods. 
- Customer class: Inherits the user class and allows the customer to use the library features.
- Librarian class: Inherits the user class and manages both books and customers.
  
In addition to the five classes we used three functions: 
- librarianOptions: allows the librarian to choose any of the options displayed in front of him and executes the chosen option.
- customerOptions: has the same functionality of librarianOptions, but it’s for the customer
- login: executes the login system We used exception handling to prevent overflows by including <stdexcept>, and we made sure the search is case sensitive by including <cctype> and <algorithm>.
  
2-How to use: 
Once you run the program, you are asked to enter a username and a password, you can login as a librarian or a customer. 

- Librarian login: 
Username: admin  
Password: admin123

- Customer login:
Customer 1: 
Username: Yousef 
Password: yousef1

Customer 2: 
Username: Reda 
Password: reda2

Customer 3: 
Username: Taha 
Password: taha3 

Customer 4:
Username: Mostafa 
Password: sasa4

Customer 5: 
Username: Adham 
Password: adham5 
After logging into the system, an options menu will appear to you 
depending on whether you are a librarian or a customer, all you have to 
do is choosing an option and follow the prompts.

3- My role:
Team leader, Librarian class and librarianOptions function implementation. 

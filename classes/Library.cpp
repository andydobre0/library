#include"../header_files/Library.h"
#include"../header_files/functions.h"

Library::Library(const std::string &filename) : filename(filename) {loadLibrary();}

void Library::loadLibrary(){
    std::ifstream inFile(filename);
    if(!inFile){
        std::cerr << "Error " << filename << std::endl;
        return;
    }
    int id;
    std::string title;
    std::string author;
    long long isbn;
    bool available;
    std::string availableStr;
    std::string line;

    while(std::getline(inFile, line)){
        std::stringstream ss(line);
        std::string idStr, isbnStr;
        getline(ss, idStr, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, isbnStr, ',');
        getline(ss, availableStr);

        
        available = (std::stoi(availableStr) == 1);
        // std::cout << idStr << " | " << title << " | " << author << " | " << isbnStr << " | " << available << std::endl;
        Book book(std::stoi(idStr), title, author, std::stoll(isbnStr), available);
        library.push_back(book);
    }
}

void Library::saveLibrary() const{
    std::ofstream outFile(filename);
    if(!outFile){
        std::cerr << "Error openning " << filename << std::endl;
        return;
    }

    for(const auto &book : library){
        outFile << book.getId() << ", "
                << book.getTitle() << ", "
                << book.getAuthor() << ", "
                << book.getISBN() << ", "
                << book.isAvailable() << "\n";
    }
}

void Library::addBook(const Book &book){
    library.push_back(book);
    saveLibrary();
}

void Library::addBookToLibrary(){
    int id;
    std::string title;
    std::string author;
    long long isbn;

    std::cout << "Enter id: "; std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter title: "; std::getline(std::cin, title);
    std::cout << "Enter author name: "; std::getline(std::cin, author);
    std::cout << "Enter ISBN: "; std::cin>>isbn;

    Book book(id, title, author, isbn);

    this->addBook(book);
}

void Library::removeBook(int id){
    library.erase(
        std::remove_if(library.begin(), library.end(),
        [id](const Book &book){return book.getId() == id;}),
        library.end()
    );
    saveLibrary();
}

void Library::removeFromLibrary(){
    int id;
    std::cout << "Enter id of the book you'd wish to remove: "; std::cin >> id;
    std::cin.ignore();
    this->removeBook(id);
}

void Library::showAllBooks(){
    for(auto &element : this->library){
        element.printBook();
    }
}

void Library::searchByTitle(){
    std::string title;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"Enter book name you are looking for: "; std::getline(std::cin, title);

    bool found = false;
    for(auto &book : library){
        std::string lowerBookTitle = toLower(book.getTitle());
        std::string lowerTitle = toLower(title);
        if(lowerBookTitle.compare(lowerTitle) == 0){
            book.printBook();
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Book was not found in the library.\n";
    }
}

void Library::borrowBook(int bookId){
    auto it = std::find_if(library.begin(), library.end(), [bookId](const Book& book){
        return book.getId() == bookId;
    });

    if(it != library.end() && it->isAvailable()){
        it->changeAvailability(false);
        clearConsole();
        std::cout << "Book borrowed succesfuly\n";
        saveLibrary();
    }
    else{
        clearConsole();
        std::cout << "Book not available\n";
        }

}

void Library::returnBook(int bookId){
    auto it = std::find_if(library.begin(), library.end(), [bookId](const Book& book){
        return book.getId() == bookId;
    });

    if(it != library.end() && !it->isAvailable()){
        it->changeAvailability(true);
        std::cout << "Book returned succesfuly\n";
        saveLibrary();
    }
    else
        std::cout << "This book wasn't borrowed\n";
}

void Library::generateReport() {
    std::cout << "Borrowed Books Report:\n";
    for (const auto& book : library) {
            std::cout << "Book ID: " << book.getId()
                      << (book.isAvailable() ? " - Available for borrowing" : " - Borrowed") << std::endl;

    }
}

void Library::adminMenu(){
    bool running = true;
    while(running){
    int choice;
    std::cout << "Choose what you want to do:\n";
    std::cout << "1. Add book\n";
    std::cout << "2. Remove book\n";
    std::cout << "3. Search book\n";
    std::cout << "4. List all books\n";
    std::cout << "5. Generate report\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter a choice number: ";
    std::cin >> choice;
    std::vector<Book> foundBooks;
    clearConsole();

    switch(choice){
        case 1:
            clearConsole();
            addBookToLibrary();
            break;
        case 2:
            removeFromLibrary();
            break;
        case 3:
            searchByTitle();
            break;
        case 4:
            showAllBooks();
            break;
        case 5:
            generateReport();
            break;
        case 6:
            running = false;
            std::cout << "bye\n";
            break;
        default:
            std::cout<<"invalid option, please try again.\n";
    }
}
}

void Library::clientMenu(){
    bool running = true;
    while (running)
    {
        int choice;
        std::cout << "1. See all books\n";
        std::cout << "2. Borrow a book\n";
        std::cout << "3. Return a book\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: "; std::cin >> choice; std::cin.ignore();

        int bookId;

        switch (choice)
        {
        case 1:
            clearConsole();
            showAllBooks();
            break;
        case 2:
            clearConsole();
            std::cout << "Enter id of the book you'd like to borrow: "; std::cin>>bookId; std::cin.ignore();
            borrowBook(bookId);
            break;
        case 3:
            clearConsole();
            std::cout << "Enter id of the book you'd like to return: "; std::cin>>bookId; std::cin.ignore();
            returnBook(bookId);
            break;
        case 4:
            running = false;
            std::cout << "Goodbye.\n";
            break;
        default:
            std::cout<<"invalid option\n";
        }
    }
}
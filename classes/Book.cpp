#include "../header_files/Book.h"
#include<iostream>

Book::Book(int id, const std::string &title, const std::string &author, const long long &ISBN, bool val)
    : bookId(id), bookTitle(title), bookAuthor(author), ISBN(ISBN), available(val){};

Book::Book(int id, const std::string &title, const std::string &author, const long long &ISBN)
    : bookId(id), bookTitle(title), bookAuthor(author), ISBN(ISBN), available(true){};

int Book::getId() const{
    return this->bookId;
}

std::string Book::getTitle() const{
    return this->bookTitle;
}

std::string Book::getAuthor() const{
    return this->bookAuthor;
}

long Book::getISBN() const{
    return this->ISBN;
}

bool Book::isAvailable() const{
    return this->available;
}

void Book::changeAvailability(bool val){
    this->available = val;
    
}

void Book::printBook(){
    std::cout << '"' << this->getId() << ", " << toLower(this->getTitle()) << ", " << toLower(this->getAuthor()) << (available ? ", available" : ", not available") <<'"'<< std::endl;
}
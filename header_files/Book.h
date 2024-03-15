#ifndef BOOK_H
#define BOOK_H

#include"../header_files/functions.h"
#include<string>

class Book{
    int bookId;
    std::string bookTitle;
    std::string bookAuthor;
    long long ISBN;
    bool available;

    public:
        Book(int bookId, const std::string &bookTitle, const std::string &author, const long long &ISBN);
        Book(int bookId, const std::string &bookTitle, const std::string &author, const long long &ISBN, bool);
        int getId() const;
        std::string getTitle() const;
        std::string getAuthor() const;
        long getISBN() const;
        bool isAvailable() const;
        void changeAvailability(bool);

        void printBook();
};

#endif
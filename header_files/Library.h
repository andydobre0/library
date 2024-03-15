#ifndef LIBRARY_H
#define LIBRARY_H

#include<vector>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include"Book.h"
#include<cctype>
#include<cstring>
#include<unordered_map>


class Library
{
private:
    std::vector<Book> library;
    std::string filename;

public:
    Library(const std::string &filename);
    void loadLibrary();
    void saveLibrary() const;
    void addBook(const Book &book);
    void addBookToLibrary();
    void removeBook(int id);
    void removeFromLibrary();
    void searchByTitle();
    void showAllBooks();
    void adminMenu();
    void clientMenu();

    void borrowBook(int bookId);
    void returnBook(int bookId);
    void generateReport();
};



#endif
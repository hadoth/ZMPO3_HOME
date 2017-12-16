#include "Book.h"

unsigned int Book::moveCount = 0;
unsigned int Book::copyCount = 0;
unsigned int Book::newCount = 0;

Book::Book(const char *title, const char *author, unsigned int pageCount) {
    this->title = CharUtils::copy(title);
    this->author = CharUtils::copy(author);
    this->pageCount = pageCount;
    newCount++;
}

Book::Book(const Book &bookToCopy) {
    this->title = CharUtils::copy(bookToCopy.title);
    this->author = CharUtils::copy(bookToCopy.author);
    this->pageCount = bookToCopy.pageCount;
    copyCount++;
}

Book::Book(Book &&bookToMove) {
    this->title = bookToMove.title;
    this->author = bookToMove.author;
    this->pageCount = bookToMove.pageCount;

    bookToMove.title = {0};
    bookToMove.author = {0};
    bookToMove.pageCount = 0;
    moveCount++;
}

Book::~Book() {
    if (this->title != nullptr) {
        delete[] this->title;
    }
    if (this->author != nullptr) {
        delete[] this->author;
    }
}

Book& Book::operator=(const Book &anotherBook) {
    this->title = CharUtils::copy(anotherBook.title);
    this->author = CharUtils::copy(anotherBook.author);
    this->pageCount = anotherBook.pageCount;
    copyCount++;
    return *this;
}

Book& Book::operator=(Book &&anotherBook) {
    if (this->title != nullptr) {
        delete[] this->title;
    }
    if (this->author != nullptr) {
        delete[] this->author;
    }
    this->title = anotherBook.title;
    this->author = anotherBook.author;
    this->pageCount = anotherBook.pageCount;

    anotherBook.title = {0};
    anotherBook.author = {0};
    anotherBook.pageCount = 0;
    moveCount++;
    return *this;
}

std::ostream& operator<<(std::ostream &o, const Book &book) {
    o << book.getTitle() << "; " << book.getAuthor() << " ("
      << book.getPageCount() << " s.)";
    return o;
}

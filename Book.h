#ifndef ZMPO3_HOME_BOOK_H
#define ZMPO3_HOME_BOOK_H

#include "utils/CharUtils.h"
#include <ostream>

class Book {
private:
    const char *title;
    const char *author;
    unsigned int pageCount;
    static unsigned int copyCount;
    static unsigned int moveCount;
    static unsigned int newCount;

public:
    Book(const char *title, const char *author, unsigned int pageCount);
    Book(const Book& bookToCopy);
    Book(Book&& bookToMove);
    ~Book();
    Book& operator =(const Book& anotherBook);
    Book& operator =(Book&& anotherBook);
    inline const char * getTitle()const { return this->title;}
    inline void setTitle(char* const title) { this->title = CharUtils::copy(title);}
    inline const char * getAuthor()const { return this->author;}
    inline void setAuthor(char* const author) {this->title = CharUtils::copy(author);}
    inline unsigned int getPageCount()const { return this->pageCount;}
    inline void setPageCount(unsigned int pageCount) {this->pageCount = pageCount;}
    inline static unsigned int getCopyCount() { return copyCount;}
    inline static unsigned int getMoveCount() { return moveCount;}
    inline static unsigned int getNewCount() { return newCount;}
    inline static void resetCounters() {copyCount = 0; moveCount = 0; newCount = 0;}
    friend std::ostream& operator<<(std::ostream& o, const Book& book);
};

#endif //ZMPO3_HOME_BOOK_H
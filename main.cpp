#include <iostream>
#include <vector>
#include "utils/CharUtils.h"
#include "Book.h"
#include "utils/Comparator.h"
#include "utils/SortUtils.h"

void printList(std::vector<Book>& bookList) {
    std::cout << "PRINTING" << std::endl;
    for (unsigned int index = 0; index < bookList.size(); index++) {
        std::cout << bookList.at(index) << std::endl;
    }
}

int main() {
    std::cout << "Char length test: " << CharUtils::charLength("123") << std::endl;

    auto left = "z";
    auto right = "a";
    std::cout << "Char comparator test: " << left << " " << right << " " << CharUtils::compare(left, right) << std::endl;

    Book book1("Władca Pierścieni", "J.R.R. Tolkien", 127);
    Book book2("Symfonia C++", "Jerzy Grębosz", 345);
    Book book3("Mastering React Native", "Eric Masiello, Jacob Friedmann", 234);
    Book book4("Modern C++ programming cookbook", "Marius Bancila", 765);
    Book book5("Bez skrupułów", "Tom Clancy", 555);
    Book book6("Milczenie owiec", "Thomas Harris", 600);
    Book book7("Zielona mila", "Stephen King", 999);
    Book book8("Początek", "Dan Brown", 5674);
    Book book9("Na krańce świata", "Norman Davies", 848);
    Book book10("Kolekcja nietypowych zdarzeń", "Tom Hanks", 12);

    std::cout << "Title comparator test: " << ComparatorUtils::bookTitleComparator(book1, book2) << std::endl;
    std::cout << "Title comparator test: " << ComparatorUtils::bookTitleComparator(book1, book1) << std::endl;
    std::cout << "Title comparator test: " << ComparatorUtils::bookTitleComparator(book2, book1) << std::endl;
    std::cout << "Author comparator test: " << ComparatorUtils::bookAuthorComparator(book1, book3) << std::endl;
    std::cout << "Author comparator test: " << ComparatorUtils::bookAuthorComparator(book1, book1) << std::endl;
    std::cout << "Author comparator test: " << ComparatorUtils::bookAuthorComparator(book3, book1) << std::endl;
    std::cout << "PageCount comparator test: " << ComparatorUtils::bookPageCountComparator(book2, book1) << std::endl;
    std::cout << "PageCount comparator test: " << ComparatorUtils::bookPageCountComparator(book1, book1) << std::endl;
    std::cout << "PageCount comparator test: " << ComparatorUtils::bookPageCountComparator(book1, book2) << std::endl;

    std::cout << "Move count: " << Book::getMoveCount() << std::endl;
    std::cout << "Copy count: " << Book::getCopyCount() << std::endl;
    std::cout << "New count: " << Book::getNewCount() << std::endl;
    Book::resetCounters();

    std::vector<Book> bookList;
    bookList.reserve(10);

    bookList.push_back(book1);
    bookList.push_back(book2);
    bookList.push_back(book3);
    bookList.push_back(book4);
    bookList.push_back(book5);
    bookList.push_back(book6);
    bookList.push_back(book7);
    bookList.push_back(book8);
    bookList.push_back(book9);
    bookList.push_back(book10);

    printList(bookList);

    std::cout << "Move count: " << Book::getMoveCount() << std::endl;
    std::cout << "Copy count: " << Book::getCopyCount() << std::endl;
    std::cout << "New count: " << Book::getNewCount() << std::endl;

    std::cout << "------*****-----" << std::endl;
    Book::resetCounters();
    std::cout << "Counters reset" << std::endl;
    std::cout << "------*****-----" << std::endl;

    std::cout << "Move count: " << Book::getMoveCount() << std::endl;
    std::cout << "Copy count: " << Book::getCopyCount() << std::endl;
    std::cout << "New count: " << Book::getNewCount() << std::endl;

    std::cout << "------*****-----" << std::endl;

    SortUtils::bubbleSort(bookList, ComparatorUtils::bookPageCountComparator);

    std::cout << "SORTING:" << std::endl;
    std::cout << "\tby page count" << std::endl;
    std::cout << "Move count: " << Book::getMoveCount() << std::endl;
    std::cout << "Copy count: " << Book::getCopyCount() << std::endl;
    std::cout << "New count: " << Book::getNewCount() << std::endl;
    printList(bookList);
    Book::resetCounters();
    std::cout << "RESET COUNTERS" << std::endl;
    std::cout << "------*****-----" << std::endl;

    SortUtils::bubbleSort(bookList, ComparatorUtils::bookAuthorComparator);

    std::cout << "SORTING:" << std::endl;
    std::cout << "\tby author" << std::endl;
    std::cout << "Move count: " << Book::getMoveCount() << std::endl;
    std::cout << "Copy count: " << Book::getCopyCount() << std::endl;
    std::cout << "New count: " << Book::getNewCount() << std::endl;
    printList(bookList);
    Book::resetCounters();
    std::cout << "RESET COUNTERS" << std::endl;
    std::cout << "------*****-----" << std::endl;

    SortUtils::bubbleSort(bookList, ComparatorUtils::bookTitleComparator);

    std::cout << "SORTING:" << std::endl;
    std::cout << "\tby title" << std::endl;
    std::cout << "Move count: " << Book::getMoveCount() << std::endl;
    std::cout << "Copy count: " << Book::getCopyCount() << std::endl;
    std::cout << "New count: " << Book::getNewCount() << std::endl;
    printList(bookList);
    Book::resetCounters();
    std::cout << "RESET COUNTERS" << std::endl;
    std::cout << "------*****-----" << std::endl;

    return 0;
}
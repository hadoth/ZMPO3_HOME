#include "Comparator.h"

int ::ComparatorUtils::bookTitleComparator(Book& left, Book& right) {
    return CharUtils::compare(left.getTitle(), right.getTitle());
}

int ::ComparatorUtils::bookAuthorComparator(Book& left, Book& right) {
    return CharUtils::compare(left.getAuthor(), right.getAuthor());
}

int ::ComparatorUtils::bookPageCountComparator(Book& left, Book& right) {
    return left.getPageCount() - right.getPageCount();
}

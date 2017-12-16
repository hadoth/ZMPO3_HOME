#ifndef ZMPO3_HOME_COMPARATOR_H
#define ZMPO3_HOME_COMPARATOR_H

#include "CharUtils.h"
#include "../Book.h"

namespace ComparatorUtils {
    template <typename T> using comparator = int (*)(T&,T&);
    int bookTitleComparator(Book& left, Book& right);
    int bookAuthorComparator(Book& left, Book& right);
    int bookPageCountComparator(Book& left, Book& right);
}


#endif //ZMPO3_HOME_COMPARATOR_H

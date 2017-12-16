#ifndef ZMPO3_HOME_CHARUTILS_H
#define ZMPO3_HOME_CHARUTILS_H

namespace CharUtils {
    unsigned int charLength(const char *letters);
    const char* copy(const char *lettersToCopy);
    int compare(const char *left, const char *right);
    char toLowerCase(const char charToCheck);
}


#endif //ZMPO3_HOME_CHARUTILS_H

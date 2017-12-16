#include "CharUtils.h"

unsigned int ::CharUtils::charLength(const char *letters) {
    unsigned int index = 0;
    while (letters[index] != 0) {
        index++;
    }
    return ++index;
}

const char *::CharUtils::copy(const char *lettersToCopy) {
    auto length = charLength(lettersToCopy);
    auto result = new char[length];
    for (int index = 0; index < length; index++) {
        result[index] = lettersToCopy[index];
    }
    return result;
}

char ::CharUtils::toLowerCase(const char charToCheck) {
    if (charToCheck >= 65 && charToCheck <=90) {
        return charToCheck + 32;
    } else {
        return charToCheck;
    }
}

int ::CharUtils::compare(const char *left, const char *right) {
    auto index = 0;

    while (left[index] != 0 || right[index] != 0) {
        if (toLowerCase(left[index]) < toLowerCase(right[index])) {
            return -(index + 1);
        }
        if (toLowerCase(left[index]) > toLowerCase(right[index])) {
            return index + 1;
        }
        if (left[index] > right[index]) {
            return -(index + 1);
        }
        if (left[index] < right[index]) {
            return index + 1;
        }

        index++;
    }

    if (left[index] == 0 && right[index] == 0) {
        return 0;
    }
    if (left[index] == 0) {
        return -(index + 1);
    }

    return index + 1;
}
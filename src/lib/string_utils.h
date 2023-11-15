#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include <stdio.h>
#include <stdlib.h>
typedef char *string;

// function declarations
size_t length(string);
size_t count_words(string, char);
string trim_left(string);
string trim_right(string);
string trim(string);
string copy(string, string, char);
string *split(string, char, int *);
string *tokenize(string, int *);
string concatenate(string str1, string str2);
#endif
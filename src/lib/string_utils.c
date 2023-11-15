#include "string_utils.h"

size_t length(string buffer)
{
    size_t counter = 0;
    while (buffer[counter] != '\0' && buffer[counter] != '\n')
        counter++;
    return counter;
}

string trim_left(string buffer)
{
    while (buffer[0] == ' ' && buffer[0] != '\0' && buffer[0] != '\n')
        buffer++;
    return buffer;
}

string trim_right(string buffer)
{
    if (buffer[0] == '\0')
        return "";
    size_t new_buffer_length;
    string splited_words, last_char;
    for (last_char = buffer + length(buffer) - 1; last_char >= buffer && *last_char == ' '; --last_char)
        ;
    new_buffer_length = last_char - buffer + 1;
    if (new_buffer_length == 0)
        return "";
    splited_words = malloc(new_buffer_length);
    for (size_t i = 0; i < new_buffer_length; i++)
        splited_words[i] = buffer[i];
    splited_words[new_buffer_length] = '\0';
    return splited_words;
}

string trim(string buffer)
{
    return trim_left(trim_right(buffer));
}

size_t count_words(string buffer, char delimiter)
{
    string current_char, next_char;
    size_t counter = 0;
    current_char = buffer;
    next_char = buffer + 1;
    while (*current_char != '\0' && *current_char != '\n')
    {
        if ((*current_char != delimiter) && (*next_char == '\0' || *next_char == delimiter))
            counter++;
        current_char++;
        next_char++;
    }
    return counter;
}

string copy(string str_to, string str_from, char delimiter)
{
    string copy_str = str_to;
    while (*str_to++ = *str_from++)
        if (*str_from == delimiter)
            break;
    *str_to = 0;
    return copy_str;
}

string *split(string buffer, char delimiter, int *argc)
{

    size_t words_counter = count_words(buffer, delimiter);
    if (words_counter == 0)
        return NULL;
    string *splited_words = malloc(sizeof(string) * words_counter);
    size_t index = 0, word_length;
    string word_start, word_end;
    while (*buffer)
    {
        if (*buffer == delimiter)
        {
            buffer++;
            continue;
        }
        word_start = word_end = buffer;
        while (*word_end != delimiter && *word_end != '\0')
            word_end++;
        word_length = (size_t)(word_end - word_start);
        splited_words[index] = malloc((word_length + 1) * sizeof(char));
        for (int i = 0; i < word_length; i++)
            splited_words[index][i] = word_start[i];
        splited_words[index][word_length] = '\0';
        buffer = word_end;
        index++;
    }
    *argc = index;
    return splited_words;
}

string *tokenize(string buffer, int *argc)
{
    return split(buffer, ' ', argc);
}

string concatenate(string str1, string str2)
{
    string result;
    result = malloc((length(str1) + length(str2) + 1) * sizeof(char));
    int i = 0;
    while (result[i++] = *str1++);
    i--;
    while (result[i++] = *str2++);
    result[i] = 0;
    return result;
}
#ifndef STRING_H_DEF
#define STRING_H_DEF

typedef char* string_t;

/*
Replaces the next occurence of c with null,
updates the string at str to point just after
and returns a pointer to the newly formed token */
string_t string_tokenize(string_t *str, char c);

#endif


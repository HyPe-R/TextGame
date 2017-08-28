#include "includes.h"
#include "string.h"

string_t string_tokenize(string_t *str, char c) {
	if(!str) return NULL;
	string_t s = *str, s2 = *str;
	while(*s != c && *s) s++;
	if(!*s) *str = NULL;
	else {
		*s = 0;
		*str = s+1;
	}
	return s2;
}


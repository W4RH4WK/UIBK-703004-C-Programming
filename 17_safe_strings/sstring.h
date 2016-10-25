#ifndef __SSTRING_H_
#define __SSTRING_H_

#include <stdlib.h>

struct String;
typedef struct String String;

String* String_from_c_str(const char* s);

String* String_from_string(const String* s);

String* String_from_array(const char* s, size_t size);

void String_destroy(String* this);

int String_print(const String* this);

size_t String_size(const String* this);

char String_get(const String* this, size_t index);

char String_set(String* this, size_t index, char v);

void String_toupper(String* this);

void String_tolower(String* this);

#endif

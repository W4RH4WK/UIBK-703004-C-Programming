#include "sstring.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct String {
	char* data;
	size_t size;
};

String* String_from_c_str(const char* s) {
	return String_from_array(s, strlen(s));
}

String* String_from_string(const String* s) {
	return String_from_array(s->data, s->size);
}

String* String_from_array(const char* s, size_t size) {
	String* this = malloc(sizeof(String));
	if (this == NULL) {
		return NULL;
	}

	this->data = malloc(size);
	if (this->data == NULL) {
		free(this);
		return NULL;
	}

	memcpy(this->data, s, size);
	this->size = size;

	return this;
}

void String_destroy(String* this) {
	free(this->data);
	free(this);
}

int String_print(const String* this) {
	return write(STDOUT_FILENO, this->data, this->size);
}

char String_get(const String* this, size_t index) {
	if (index >= this->size) {
		return 0;
	}
	return this->data[index];
}

char String_set(const String* this, size_t index, char v) {
	if (index >= this->size) {
		return 0;
	}
	char old = this->data[index];
	this->data[index] = v;
	return old;
}

size_t String_size(const String* this) {
	return this->size;
}

void String_toupper(String* this) {
	for (size_t i = 0; i < this->size; ++i) {
		this->data[i] = toupper(this->data[i]);
	}
}

void String_tolower(String* this) {
	for (size_t i = 0; i < this->size; ++i) {
		this->data[i] = tolower(this->data[i]);
	}
}

#include "sstring.h"

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct String {
	size_t size;
	char* data;
};

String* String_from_c_str(const char* s) {
	return String_from_array(s, strlen(s));
}

String* String_from_string(const String* s) {
	return String_from_array(s->data, s->size - 1);
}

String* String_from_array(const char* s, size_t size) {
	if (size == SIZE_MAX) {
		return NULL;
	}

	String* this = malloc(sizeof(String));
	if (this == NULL) {
		return NULL;
	}

	this->data = malloc(size + 1);
	if (this->data == NULL) {
		free(this);
		return NULL;
	}

	memcpy(this->data, s, size);
	this->data[size] = '\0';
	this->size = size + 1;

	return this;
}

void String_destroy(String* this) {
	free(this->data);
	free(this);
}

int String_print(const String* this) {
	return write(STDOUT_FILENO, this->data, this->size - 1);
}

char String_get(const String* this, size_t index) {
	if (index >= this->size - 1) {
		return 0;
	}
	return this->data[index];
}

char String_set(const String* this, size_t index, char v) {
	if (index >= this->size - 1) {
		return 0;
	}
	char old = this->data[index];
	this->data[index] = v;
	return old;
}

size_t String_size(const String* this) {
	return this->size;
}

size_t String_length(const String* this) {
	return this->size - 1;
}

void String_toupper(String* this) {
	for (size_t i = 0; i < this->size - 1; ++i) {
		this->data[i] = toupper(this->data[i]);
	}
}

void String_tolower(String* this) {
	for (size_t i = 0; i < this->size - 1; ++i) {
		this->data[i] = tolower(this->data[i]);
	}
}

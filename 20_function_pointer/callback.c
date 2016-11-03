#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* In this example we deal with a set of 5 people, each consists of name and
 * age. Apart from a print function, two *callbacks* are provided. These two
 * callback functions allow one to compare two people either by name, or by
 * age.
 *
 * We utilize the `qsort` function of the standard library to sort our array of
 * people, either by name, or by age, depending on what callback function is
 * used with `qsort`.
 *
 * This is necessary because `qsort` does not know how to compare person, it
 * only knows how to move chunks of memory around. Whenever it wants to compare
 * two entries, the callback function is utilized.
 */

#define PEOPLE_NUM 5

struct Person {
	const char name[64];
	int age;
};
typedef struct Person Person;

void Person_print(const Person* this) {
	printf("%p %s(%d)", (void*) this, this->name, this->age);
}

int Person_cmp_name(const void* x, const void* y) {
	return strncmp(((Person*) x)->name, ((Person*) y)->name, 64);
}

int Person_cmp_age(const void* x, const void* y) {
	return ((Person*) x)->age - ((Person*) y)->age;
}

int main(void) {
	Person people[PEOPLE_NUM] = {
		{ "Person 2", 23 },
		{ "Person 3", 21 },
		{ "Person 4", 18 },
		{ "Person 1", 20 },
		{ "Person 5", 28 },
	};

	/* qsort(people, PEOPLE_NUM, sizeof(Person), Person_cmp_name); */
	qsort(people, PEOPLE_NUM, sizeof(Person), Person_cmp_age);

	for (size_t i = 0; i < PEOPLE_NUM; ++i) {
		Person_print(&people[i]);
		printf("\n");
	}

	return EXIT_SUCCESS;
}

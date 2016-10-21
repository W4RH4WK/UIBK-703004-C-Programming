#include <stdio.h>
#include <stdlib.h>

/* Structs are very important and ease readability a lot. They are used to
 * group data together.
 */
struct Person {
	char *firstname;
	char *lastname;
	int age;
	float height;
};

/* We can use a typedef so we don't have to write `struct Person`, but can
 * write `Person`.
 */
typedef struct Person Person;

/* A print function can be handy. Note the function name and that we take a
 * pointer since we don't want the whole struct to be coppied.
 *
 * Taking a pointer would give us the option to also modify data, which should
 * not be done by a print function. To ensure the data is not modified we make
 * it const.
 */
void Person_print(const Person* this);

int main(void) {

	/* Let's setup a person by setting its *fields* one by one. */
	Person alex;
	alex.firstname = "Alex";
	alex.lastname = "Someone";
	alex.age = 25;
	alex.height = 177.8;

	/* We can use a initializer list as we would for arrays, but we can use
	 * designated initializers.
	 */
	Person fry = {
		.firstname = "Philip",
		.lastname = "Fry",
		.age = 1025,
		.height = 180.4,
	};

	Person_print(&alex);

	printf("\n");

	Person_print(&fry);

	return EXIT_SUCCESS;
}

void Person_print(const Person* this) {

	printf("Name: %s %s\n", (*this).firstname, (*this).lastname);

	/* Typing (*this). is annoying and looks horrible, because of this there is
	 * a shorthand.
	 */

	printf("Body: %d years at %g cm\n", this->age, this->height);

}

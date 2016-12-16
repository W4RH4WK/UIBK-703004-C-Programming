#include <stdio.h>
#include <stdlib.h>

/* This is a small, simplified example showing how polymorphism can be realized
 * with function pointers. The unified interface `IAnimal` can represent any
 * animal. An implementation for cats and ducks is provided.
 */

/* Unified interface for all animals. */
struct IAnimal {
	int num_legs;
	void (*make_sound)(void);
};
typedef struct IAnimal IAnimal;

/* cat stuff */
void Animal_cat_sound(void) {
	printf("Meow");
}

/* duck stuff */
void Animal_duck_sound(void) {
	printf("Quack");
}

/* creating a cat */
IAnimal Animal_new_cat(void) {
	return (IAnimal) {
		.num_legs = 4,
		.make_sound = Animal_cat_sound,
	};
}

/* creating a duck */
IAnimal Animal_new_duck(void) {
	return (IAnimal) {
		.num_legs = 2,
		.make_sound = Animal_duck_sound,
	};
}

int main(void) {
	IAnimal animals[5];

	animals[0] = Animal_new_cat();
	animals[1] = Animal_new_duck();
	animals[2] = Animal_new_cat();
	animals[3] = Animal_new_duck();
	animals[4] = Animal_new_cat();

	for (int i = 0; i < 5; ++i) {
		printf("Animal Nr. %d has %d legs and ", i, animals[i].num_legs);
		animals[i].make_sound();
		printf("s\n");
	}

	return EXIT_SUCCESS;
}

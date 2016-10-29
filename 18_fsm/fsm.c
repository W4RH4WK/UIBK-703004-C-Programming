/* Finite State Machine */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

enum State {
	State_Start,
	State_First,
	State_Second,
	State_Final,
};
typedef enum State State;

State State_Start_fun(void) {
	puts("Starting State");
	return State_First;
}

State State_First_fun(void) {
	puts("First State");
	return State_Second;
}

State State_Second_fun(void) {
	puts("Second State");
	return State_Final;
}

int main(void) {
	State s = State_Start;

	while (s != State_Final) {
		switch (s) {
			case State_Start:  s = State_Start_fun();  break;
			case State_First:  s = State_First_fun();  break;
			case State_Second: s = State_Second_fun(); break;
			case State_Final:                          break;

			default:
				fprintf(stderr, "Unknown State");
				return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}

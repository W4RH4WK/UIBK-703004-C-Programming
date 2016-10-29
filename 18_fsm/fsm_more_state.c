#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

enum StateLabel {
	StateLabel_Start,
	StateLabel_Increment,
	StateLabel_Final,
};
typedef enum StateLabel StateLabel;

struct State {
	StateLabel label;
	int counter;
};
typedef struct State State;

void State_Start(State* state) {
	state->counter = 0;
	state->label = StateLabel_Increment;
}

void State_Increment(State* state) {
	if (state->counter < 10) {
		++state->counter;
	} else {
		state->label = StateLabel_Final;
	}
}

int main(void) {
	State s = { .label = StateLabel_Start };

	while (s.label != StateLabel_Final) {
		switch (s.label) {
			case StateLabel_Start:     State_Start(&s);     break;
			case StateLabel_Increment: State_Increment(&s); break;
			case StateLabel_Final:                          break;

			default:
				fprintf(stderr, "Unknown State");
				return EXIT_FAILURE;
		}
	}

	printf("counter: %d\n", s.counter);

	return EXIT_SUCCESS;
}

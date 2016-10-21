#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/* One can easily declare multi-dimensional arrays... */
	int mutli_array[3][6];

	/* ... and fill it with some values... */
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 6; ++j) {
			mutli_array[i][j] = 13 * i + j;
		}
	}

	/* ... and print it row by row */
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 6; ++j) {
			printf("%d ", mutli_array[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	/* Alternatively it can be initialized directly. */
	int another_multi_array[3][3] = { { 1, 2, 3 },
	                                  { 4, 5, 6 },
	                                  { 7, 8, 9 } };

	/* After all the first level is just an array of pointers, and the second
	 * level an array of integers.
	 *
	 *     [ int*, int*, int* ]
	 *          |     |     `----> [ 1, 2, 3 ]
	 *          |     |
	 *          |     `----------> [ 4, 5, 6 ]
	 *          |
	 *          `----------------> [ 7, 8, 9 ]
	 *
	 */

	/* Depending on your usecase the array *rows* can be scattered over memory,
	 * hence a *linearized* array can yield better performance. Row and column
	 * index can be emulated.
	 */
	{
		const int num_rows = 5;
		const int num_cols = 4;

		int linearized[num_rows * num_cols];

		for (int r = 0; r < num_rows; ++r) {
			for (int c = 0; c < num_cols; ++c) {
				linearized[r * num_cols + c] = r * num_cols + c;
			}
		}

		for (int r = 0; r < num_rows; ++r) {
			for (int c = 0; c < num_cols; ++c) {
				printf("%3d ", linearized[r * num_cols + c]);
			}
			printf("\n");
		}
	}

	printf("\n");

	/* One could also use a single loop index by utilizing integer division and
	 * modulo.
	 */
	{
		const int num_rows = 5;
		const int num_cols = 4;

		int multi[num_rows][num_cols];

		for (int i = 0; i < num_rows * num_cols; ++i) {
			multi[i / num_cols][i % num_cols] = i;
		}

		for (int i = 0; i < num_rows * num_cols; ++i) {
			printf("%3d ", multi[i / num_cols][i % num_cols]);
			if (i % num_cols == num_cols - 1) {
				printf("\n");
			}
		}
	}

	return EXIT_SUCCESS;
}

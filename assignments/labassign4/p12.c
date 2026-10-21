#include <stdio.h>
#include <stdlib.h>

/*
 * ALGORITHM - DRYCODE14 
 *
 * START
 *   Read m (number of questions) and n (number of students).
 *   If m or n is not positive, report invalid input and stop.
 *
 *   Declare correctAnswers[0 ... m-1].
 *   For item = 0 to m-1:
 *       Read correctAnswers[item].
 *
 *   Declare scores[0 ... n-1].
 *   For student = 0 to n-1:
 *       scores[student] = 0
 *       For item = 0 to m-1:
 *           Read response
 *           If response equals correctAnswers[item]:
 *               scores[student] = scores[student] + 1
 *
 *   For student = 0 to n-1:
 *       Print student number and scores[student] out of m.
 * STOP
 *
 * Input format: m n, then m answer characters for the key, followed by m
 * response characters for each student. Answers can be any single character
 * (for example, A, B, C, or D); comparison is case-sensitive.
 */

int main(void)
{
	int m, n;

	// Get the number of test items and students before allocating arrays.
	printf("Enter number of items and students: ");
	if (scanf("%d %d", &m, &n) != 2 || m <= 0 || n <= 0) {
		printf("Invalid input: both counts must be positive integers.\n");
		return 1;
	}

	// The answer key stores one character for each test item.
	char *correctAnswers = malloc((size_t)m * sizeof(*correctAnswers));

	// Each element stores the total correct answers for one student.
	int *scores = calloc((size_t)n, sizeof(*scores));
	if (correctAnswers == NULL || scores == NULL) {
		printf("Unable to allocate memory.\n");
		free(correctAnswers);
		free(scores);
		return 1;
	}

	// Read the answer key first, as required before evaluating students.
	printf("Enter the %d correct answers: ", m);
	for (int item = 0; item < m; item++) {
		if (scanf(" %c", &correctAnswers[item]) != 1) {
			printf("Could not read the answer key.\n");
			free(correctAnswers);
			free(scores);
			return 1;
		}
	}

	// Read and grade each student's complete set of responses in turn.
	for (int student = 0; student < n; student++) {
		printf("Enter the %d responses for student %d: ", m, student + 1);
		for (int item = 0; item < m; item++) {
			char response;
			if (scanf(" %c", &response) != 1) {
				printf("Could not read student responses.\n");
				free(correctAnswers);
				free(scores);
				return 1;
			}

			// Award one point when this response matches the answer key.
			if (response == correctAnswers[item]) {
				scores[student]++;
			}
		}
	}

	// Print the number correct for every student after grading is complete.
	printf("\nResults (score out of %d):\n", m);
	for (int student = 0; student < n; student++) {
		printf("Student %d: %d\n", student + 1, scores[student]);
	}

	free(correctAnswers);
	free(scores);
	return 0;
}

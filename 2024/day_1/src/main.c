
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int i = 0;
	int gigaarray[2][1000] = {0};
	char str[15];
	FILE *file;

	if (argc < 2) {
        printf("Missing input file.\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL) {
        printf("Couldn't read %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// Store the text file in the gigaarray
	while (fgets(str, 15, file)) {
		char *saveptr1;
		char *line;

		line = strtok_r(str, "\n", &saveptr1);
		while (line != NULL) {
			char *word;
			int j = 0;

			word = strtok(str, " ");
			while (word != NULL) {
				gigaarray[j][i] = atoi(word);
				word = strtok(NULL, " ");
				j++;
			}
			line = strtok_r(NULL, "\n", &saveptr1);
		}
		i++;
	}

	for (i = 0; i < 1000; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", gigaarray[j][i]);
		}
		printf("\n");
	}

	printf("Done\n");

	return EXIT_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file;

	file = fopen("input.txt", "r");

	int gigaarray[2][1000] = {0};

	int i = 0;
	char str[15];
	
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

	return 0;
}

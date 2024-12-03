
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int i = 0;
	int giga_array[2][1000] = {0};
	char str[15];
	FILE *file_fp;

	if (argc < 2) {
        printf("Missing input file.\n");
		exit(EXIT_FAILURE);
	}

	file_fp = fopen(argv[1], "r");

	if (file_fp == NULL) {
        printf("Couldn't read %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
    
	printf("Reading file... ");

	// Store the text file in the giga_array
	while (fgets(str, 15, file_fp)) {
		char *saveptr1;
		char *line;

		line = strtok_r(str, "\n", &saveptr1);
		while (line != NULL) {
			char *word;
			int j = 0;

			word = strtok(str, " ");
			while (word != NULL) {
				giga_array[j][i] = atoi(word);
				word = strtok(NULL, " ");
				j++;
			}
			line = strtok_r(NULL, "\n", &saveptr1);
		}
		i++;
	}
	printf("Done\n");

    int count_array[10];
    int temp_array[1000];

	printf("Radix sort the array... ");
    for (int k = 0; k < 2; k++) {
        for (i = 0; i < 5; i++) {
            memset(count_array,0, sizeof(count_array));
            
            for (int j = 0; j < 1000; j++) {
                count_array[(giga_array[k][j] / (int)pow(10, i)) % 10]++;
            }
        
            // Add the number together
            for (int j = 0; j < 9; j++) {
                count_array[j + 1] += count_array[j];
            }

            for (int j = 999; j >= 0; j--) {
                temp_array[--count_array[(giga_array[k][j] / (int)pow(10, i)) % 10]] = giga_array[k][j];
            }

            memcpy(giga_array[k], temp_array, sizeof(giga_array[k]));
        }
    }
	printf("Done\n");

    int total_diff = 0;
	printf("Calulating diff... ");
    for (i = 0; i < 1000; i++) {
        total_diff += abs(giga_array[0][i] - giga_array[1][i]);
    }
	printf("Done\n");

	printf("Total: %d\n",total_diff);

	return EXIT_SUCCESS;
}

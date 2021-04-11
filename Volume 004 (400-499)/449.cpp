/* @JUDGE_ID: 19899RK 449 C++ "By Anadan" */ 
// Majoring in Scales
// Accepted (0.090 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

const char major_scales[12][7][3] = {
	{"C",  "D",  "E",  "F",  "G",  "A",  "B" },
	{"Db", "Eb", "F",  "Gb", "Ab", "Bb", "C" },
	{"D",  "E",  "F#", "G",  "A",  "B",  "C#"},
	{"Eb", "F",  "G",  "Ab", "Bb", "C",  "D" },
	{"E",  "F#", "G#", "A",  "B",  "C#", "D#"},
	{"F",  "G",  "A",  "Bb", "C",  "D",  "E" },
	{"Gb", "Ab", "Bb", "Cb", "Db", "Eb", "F" },
	{"G",  "A",  "B",  "C",  "D",  "E",  "F#"},
	{"Ab", "Bb", "C",  "Db", "Eb", "F",  "G" },
	{"A",  "B",  "C#", "D",  "E",  "F#", "G#"},
	{"Bb", "C",  "D",  "Eb", "F",  "G",  "A" },
	{"B",  "C#", "D#", "E",  "F#", "G#", "A#"}
};

int main(){
	int scale, i, k;
	char key[3], start[3], updown[5], interval[8];

	while (scanf("%s", key) == 1){
		printf("Key of %s\n", key);
		for (scale = 0; strcmp(major_scales[scale][0], key); ++scale);

		while (scanf("%s %s %[^;\n]", start, updown, interval) == 3){
			for (i = 0; i < 7; ++i) if (strcmp(major_scales[scale][i], start) == 0) break;
			if (i < 7){
				if (interval[2] == 'C') k = 1;
				else if (interval[2] == 'I') k = 2;
				else if (interval[2] == 'U') k = 3;
				else if (interval[2] == 'F') k = 4;
				else if (interval[2] == 'X') k = 5;
				else if (interval[2] == 'V') k = 6;
				else if (interval[2] == 'T') k = 7;
				if (updown[0] == 'D') k = -k;
				i = (i + k + 7) % 7;
				printf("%s: %s %s > %s\n", start, updown, interval, major_scales[scale][i]);
			}
			else printf("%s: invalid note for this key\n", start);

			if (getchar() == '\n') break;
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

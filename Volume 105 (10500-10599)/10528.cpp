/* @JUDGE_ID: 19899RK 10528 C++ "By Anadan" */ 
// Major Scales
// Accepted (0.014 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

const char notes[12][3] = {
	"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
};
const int major[12] = { 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 };

int main(){
	int i, j, out;
	char nt[3], mask[12];

	while (1){
		memset(mask, 0, sizeof(mask));
		while ((i = getchar()) != '\n'){
			if (i < 'A' || i > 'G') continue;
			nt[0] = i;
			i = nt[1] = getchar();
			if (i == 'N') break;
			if (i != '#' && (i < 'A' || i > 'G')) nt[1] = 0;
			else nt[2] = 0;

			for (j = 0; strcmp(notes[j], nt); ++j);
			mask[j] = 1;

			if (i == '\n') break;
		}

		if (i == 'N') break;

		out = 0;
		for (i = 0; i < 12; ++i){
			for (j = 0; j < 12; ++j){
				if (major[j] == 0 && mask[(i + j) % 12] == 1) break;
			}

			if (j == 12){
				if (out) putchar(' '); else out = 1;
				printf("%s", notes[i]);
			}
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

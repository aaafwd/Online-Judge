/* @JUDGE_ID: 19899RK 386 C++ "By Anadan" */
// Perfect Cubes
// Accepted (0.460 seconds using as much as 384 kbytes)

#include <stdio.h>
#define MAX 200

int main(){
	long a, b, c, d, rest1, rest2, cubes[MAX+1];
	for (a = 0L; a <= MAX; a++) cubes[a] = a*a*a;

	for (a = 6L; a <= MAX; a++){
		for (b = 2L; b < a; b++){
			rest1 = cubes[a] - cubes[b];
			for (c = b; cubes[c] < rest1; c++){
				rest2 = rest1 - cubes[c];
				for (d = c; cubes[d] < rest2; d++);
				if (cubes[d] == rest2)
					printf("Cube = %ld, Triple = (%ld,%ld,%ld)\n", a, b, c, d);
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

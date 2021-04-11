/* @JUDGE_ID: 19899RK 253 C++ "By Anadan" */
// Cube painting
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i, j;
	char str1[7], str2[7];
	char solves[24][7] = {
		"012345", "031425", "043215", "024135",
		"152304", "135024", "103254", "120534",
		"215043", "201453", "240513", "254103",
		"310542", "351402", "345012", "304152",
		"402351", "430521", "453201", "425031",
		"542310", "534120", "513240", "521430"
	};

	while (scanf("%6s%6s\n", str1, str2) == 2){
		for (i = 0; i < 24; i++){
			for (j = 0; j < 6; j++){
				if (str1[j] != str2[solves[i][j]-'0']) break;
			}
			if (j == 6) break;
		}
		if (i < 24) printf("TRUE\n");
		else printf("FALSE\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

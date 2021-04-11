/* @JUDGE_ID: 19899RK 401 C++ "By Anadan" */
// Palindromes
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char Reverse1[22] = "AEHIJLMOSTUVWXYZ12358";
char Reverse2[22] = "A3HILJMO2TUVWXY51SEZ8";

int isPalindrome(const char *p){
	int i = strlen(p), j;
	for (j = 0; j < (i >> 1); j++){
		if (p[j] != p[i-j-1]) return 0;
	}
	return 1;
}

char getReverse(char ch){
	int i;
	for (i = 0; i < 21; i++) if (ch == Reverse1[i]) return Reverse2[i];
	return 0;
}

int isMirrored(const char *p){
	int i = strlen(p), j;

	if ((i & 1) && (p[i >> 1] != getReverse(p[i >> 1]))) return 0;
	for (j = 0; j < (i >> 1); j++){
		if (p[j] != getReverse(p[i-j-1])) return 0;
	}
	return 1;
}

int main(){
	char str[1024];
	while (scanf("%s\n",str) > 0){
		printf("%s -- is ", str);
		if (isPalindrome(str)){
			if (isMirrored(str))
				printf("a mirrored palindrome.\n\n");
			else	printf("a regular palindrome.\n\n");
		}else{
			if (isMirrored(str))
				printf("a mirrored string.\n\n");
			else	printf("not a palindrome.\n\n");
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

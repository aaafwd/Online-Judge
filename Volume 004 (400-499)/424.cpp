/* @JUDGE_ID: 19899RK 424 C++ "By Anadan" */
// Integer Inquiry
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char nums[101][101], res[103];
int index = 0;

char *_strrev(char *s){
	char tmp;
	int i, len = strlen(s);
	for (i = 0; i < (len >> 1); i++){
		tmp = s[i];
		s[i] = s[len-1-i];
		s[len-1-i] = tmp;
	}
	return s;
}

int main(){
	char *p;
	int i, j, cur, toi = 0;

	for (i = 0; i < 101; i++) for (j = 0; j < 101; j++) nums[i][j] = 0;
	for (i = 0; i < 103; i++) res[i] = 0;
	while (scanf("%s\n", nums[index]) > 0){
		if (!strcmp(nums[index], "0")) break;
		i = strlen(_strrev(nums[index++]));
		if (i > toi) toi = i;
	}

	for (i = cur = 0; i < toi; i++){
		for (j = 0; j < index; j++){
			if (!nums[j][i]) continue;
			cur += nums[j][i] - '0';
		}
		res[i] = '0' + (cur % 10);
		cur /= 10;
	}

	while (cur){
		res[i++] = '0' + (cur % 10);
		cur /= 10;
	}
	res[i] = 0;
	p = _strrev(res);
	while (*p == '0') p++;
	printf("%s\n", p);
	return 0;
}
/* @END_OF_SOURCE_CODE */

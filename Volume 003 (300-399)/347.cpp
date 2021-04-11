/* @JUDGE_ID: 19899RK 347 C++ "By Anadan" */
// Run, Run, Runaround Numbers
// Accepted (1.783 seconds using as much as 380 kbytes)

#include <stdio.h>
#include <string.h>

int arr[510], sp = 0;

int runaround(char *s){
	int nums, i, j, mask = 0;

	if (strchr(s, '0')) return 0;

	for (i = 0; s[i]; i++){
		if (mask & (1 << (s[i] - '0'))) return 0;
		mask |= 1 << (s[i] - '0');
	}

	mask = 0;
	nums = i--; j = nums;
	while (j--){
		if (mask & (1 << i)) return 0;
		mask |= 1 << i;
		i = (i - s[i] + '0' + (nums << 10)) % nums;
	}

	return (i == nums - 1);
}

void inc(char *s){
	int rest = 1;

	while (*s){
		rest += *s - '0';
		if (rest < 10){
			*s = rest + '0';
			return;
		}
		*s++ = rest - 10 + '0';
		rest = 1;
	}

	*s++ = '1';
	*s = 0;
}

int getsmallest(int N){
	int i = 0, j = sp - 1, k;

	while (i + 1 < j){
		k = (i + j) >> 1;
		if (arr[k] > N) j = k; else i = k;
	}
	while (arr[i] < N) ++i;
	return arr[i];
}

int main(){
	int set = 0, N = 10;
	char str[10];

	for (strcpy(str, "01"); N <= 9682415; ++N, inc(str)){
		if (runaround(str)) arr[sp++] = N;
	}

	while (scanf("%d", &N) == 1 && N){
		printf("Case %d: %d\n", ++set, getsmallest(N));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

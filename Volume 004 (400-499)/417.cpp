/* @JUDGE_ID: 19899RK 417 C++ "By Anadan" */
// Word Index
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

#define COD 96

int in1(int i){
	if (i == 0) return 0;
	else return (i+1);
}

int in2(int i, int n, char *str){
	if (i > n) return 0;
	if (i == n) return (str[0]-COD);
	else return 26;
}

long f(char *str){
	int i;
	int a1, a2, a3, a4, a5, flag;
	long count = 0;
	int n = strlen(str);

	if (n == 1) return (long)(str[0]-COD);
	for (i=0; i<n-1; i++){
		if (str[i+1]<str[i]) return 0;
	}
	for (a1=in1( 0); a1<=in2(5,n,str) ;a1++)
	for (a2=in1(a1); a2<=in2(4,n,str) ;a2++)
	for (a3=in1(a2); a3<=in2(3,n,str) ;a3++)
	for (a4=in1(a3); a4<=in2(2,n,str) ;a4++)
	for (a5=in1(a4); a5<=in2(1,n,str) ;a5++){
		flag = 0;
		switch (n){
		case 5: if (a1 == str[0]-COD)
			if (a2 == str[1]-COD)
			if (a3 == str[2]-COD)
			if (a4 == str[3]-COD)
			if (a5 == str[4]-COD) flag=1;
			break;
		case 4:
			if (a2 == str[0]-COD)
			if (a3 == str[1]-COD)
			if (a4 == str[2]-COD)
			if (a5 == str[3]-COD) flag=1;
			break;
		case 3:
			if (a3 == str[0]-COD)
			if (a4 == str[1]-COD)
			if (a5 == str[2]-COD) flag=1;
			break;
		case 2:
			if (a4 == str[0]-COD)
			if (a5 == str[1]-COD) flag=1;
			break;
		};
		if (flag) return count;
		count++;
	}

	return count;
}

int main(){
	char str[6];
	while(scanf("%s", str) != EOF) printf("%ld\n", f(str));
	return 0;
}
/* @END_OF_SOURCE_CODE */

/* @JUDGE_ID: 19899RK 485 C++ "By Anadan" */
// Pascal's Triangle of Death
// Accepted (0.140 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <stdlib.h>

class Hugeint{
	#define OFFSET 9
	#define BASE 1000000000L
	#define LEN 7
	typedef unsigned long HINT;

	int len;
	HINT nums[LEN];
public:
	Hugeint();
	Hugeint(HINT);

	Hugeint& operator += (Hugeint&);
	Hugeint& operator =  (Hugeint&);

	void VerifyLenght();
	int print(char *str = NULL);
};

int Hugeint::print(char *str){
	int i;
	char format[10];
	sprintf(format, "%%0%dld", OFFSET);
	printf("%ld", nums[len - 1]);
	for (i = len-2; i >= 0; i--) printf(format, nums[i]);
	if (str) printf("%s", str);
	return 0;
}

void Hugeint::VerifyLenght(){
	for (len = LEN; len > 0; len--) if (nums[len - 1] != HINT(0)) break;
}

Hugeint::Hugeint() : len(1){
	for (int i = 0; i < LEN; i++) nums[i] = HINT(0);
}

Hugeint::Hugeint(HINT a) : len(1){
	for (int i = 0; i < LEN; i++) nums[i] = HINT(0);
	if (a < HINT(BASE)) nums[0] = a;
	else{
		HINT tmp = HINT(0);
		len++;
		while (a >= HINT(BASE)) { a -= HINT(BASE); tmp++; }
		nums[0] = a;
		nums[1] = tmp;
	}
}

Hugeint& Hugeint::operator += (Hugeint& hint){
	int i;
	HINT tmp = HINT(0);
	if (len < hint.len) len = hint.len;

	for (i = 0; i < len; i++){
		nums[i] += hint.nums[i] + tmp;
		tmp = HINT(0);
		while (nums[i] >= HINT(BASE)) {nums[i] -= HINT(BASE); tmp++;}
	}

	if (tmp > 0){
		if (len < LEN){
			nums[len++] = tmp;
		}else VerifyLenght();
	}

	return *this;
}

Hugeint& Hugeint::operator = (Hugeint& hint){
	len = hint.len;
	for (int i = 0; i < LEN; i++) nums[i] = hint.nums[i];
	return *this;
}

int main(){
	int i, n;
	Hugeint array[103], tmp(1);

	printf("1\n1 1\n");
	array[0] = array[1] = tmp;
	for (n = 2; n <= 204; n++){
		if (!(n & 1)){
			array[n/2]  = array[n/2-1];
			array[n/2] += array[n/2-1];
		}
		for (i = (n+1)/2-1; i > 0; i--){
			array[i] += array[i-1];
		}

		printf("1");
		for (i = 1; i <= n/2; i++){
			printf(" ");
			array[i].print();
		}
		for (i = (n-1)/2; i > 0; i--){
			printf(" ");
			array[i].print();
		}
		printf(" 1\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

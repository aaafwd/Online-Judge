/* @JUDGE_ID: 19899RK 297 C++ "By Anadan" */
// Quadtrees
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

char *getnextnode(char *s){
	int rest = 1;

	while (rest--){
		if (*s++ == 'p') rest += 4;
	}

	return s;
}

void addimages(char *s1, char *s2, char *s3){
	char *s;

	while (*s1 && *s2){
		if (*s1 == 'f'){
			*s3++ = 'f';
			s1++;
			s2 = getnextnode(s2);
		}else if (*s2 == 'f'){
			*s3++ = 'f';
			s1 = getnextnode(s1);
			s2++;
		}else if (*s1 == 'e' && *s2 == 'e'){
			*s3++ = 'e';
			s1++; s2++;
		}else if (*s1 == 'p' && *s2 == 'p'){
			*s3++ = 'p';
			s1++; s2++;
		}else{
			if (*s1 == 'p'){
				s = getnextnode(s1);
				while (s1 < s) *s3++ = *s1++;
				s2++;
			}else{
				s = getnextnode(s2);
				while (s2 < s) *s3++ = *s2++;
				s1++;
			}
		}
	}
	*s3 = 0;
}

int getpixels(char *s, int size){
	int i, res = 0;

	if (*s == 'f') return size*size;
	else if (*s == 'e') return 0;

	size >>= 1;
	for (i = 0, s++; i < 4; i++){
		res += getpixels(s, size);
		s = getnextnode(s);
	}

	return res;
}

int main(){
	char str1[2048], str2[2048], str3[2048];
	long set;
	scanf("%ld\n", &set);

	while (set--){
		scanf("%s\n%s\n", str1, str2);
		addimages(str1, str2, str3);
		printf("There are %d black pixels.\n", getpixels(str3, 32));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

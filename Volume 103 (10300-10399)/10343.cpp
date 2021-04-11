/* @JUDGE_ID: 19899RK 10343 C++ "By Anadan" */
// Base64 Decoding
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int c, i, pad, quant[4];
	char encode[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=#", *p;

	while ((c = getchar()) != EOF && c != '#'){
		if ((p = strchr(encode, c)) == NULL) continue;

		do{
			quant[0] = int(p - encode) << 2;
			pad = 0;

			while ((p = strchr(encode, c = getchar())) == NULL);
			i = int(p - encode);
			quant[0] |= (i >> 4) & 3;
			quant[1] = (i << 4) & 0xF0;

			while ((p = strchr(encode, c = getchar())) == NULL);
			if (c == '=') ++pad;
			else{
				i = int(p - encode);
				quant[1] |= (i >> 2) & 0x0F;
				quant[2] = (i << 6) & 0xC0;
			}

			while ((p = strchr(encode, c = getchar())) == NULL);
			if (c == '=') ++pad;
			else{
				i = int(p - encode);
				quant[2] |= i & 0x3F;
			}
			for (i = 0; i < 3 - pad; ++i) putchar(quant[i]);

			while ((p = strchr(encode, c = getchar())) == NULL);
		}while(c != '#');

		putchar('#');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

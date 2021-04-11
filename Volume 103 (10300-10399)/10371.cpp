/* @JUDGE_ID: 19899RK 10371 C++ "By Anadan" */
// Time Zones
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

const int tm[32] = {
	0, 0, 60, 60, 0, 60, 60, 120, 120, 180, 180, 240, -240, -180,
	-210, -150, -300, -240, -360, -300, -420, -360, -480, -420, -600,
	-540, -480, 600, 660, 570, 630, 480
};

const char TZ[32][5] = {
	"UTC", "GMT", "BST", "IST", "WET","WEST", "CET", "CEST", "EET", "EEST",
	"MSK", "MSD", "AST", "ADT", "NST", "NDT", "EST", "EDT", "CST", "CDT",
	"MST", "MDT", "PST", "PDT", "HST", "AKST", "AKDT", "AEST", "AEDT",
	"ACST", "ACDT", "AWST"
};

int gettm(char *str){
	int i;
	for (i = 0; i < 32; ++i) if (!strcmp(TZ[i], str)) return tm[i];
	return -1;
}

int main(){
	int set, h, m, t;
	char str[10];

	scanf("%d\n", &set);
	while (set--){
		scanf("%s", str);
		if (!strcmp(str, "noon")) m = 720;
		else if (!strcmp(str, "midnight")) m = 1440;
		else{
			sscanf(str, "%d:%d", &h, &m);
			if (h == 12) h = 0;
			m += h * 60;
			scanf("%s", str);
			if (!strcmp(str, "p.m.")) m += 720;
		}

		scanf("%s", str);
		t = gettm(str);
		scanf("%s", str);
		t = gettm(str) - t;
		m += t;
		if (m < 0) m += 1440;
		m %= 1440;
		if (m == 720) printf("noon\n");
		else if (m == 0) printf("midnight\n");
		else{
			if (m < 720){
				h = m / 60;
				if (!h) h = 12;
				printf("%d:%.2d a.m.\n", h, m % 60);
			}else{
				m -= 720;
				h = m / 60;
				if (!h) h = 12;
				printf("%d:%.2d p.m.\n", h, m % 60);
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

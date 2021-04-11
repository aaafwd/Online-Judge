/* @JUDGE_ID: 19899RK 505 C++ "By Anadan" */ 
// Moscow time
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

const char weeks[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
const char month[12][4] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };

int w, m, day, year, hh, mm, ss, tz;

int isleap(){
	if (year % 4) return 0;
	if (year % 100) return 1;
	if (year % 400) return 0;
	return 1;
}

void convert_time(){
	int dtz = 180 - tz, tmp;
	int mdays[] = { 0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	mdays[2] = 28 + isleap();
	if (dtz == 0) return;
	if (dtz > 0){
		mm += dtz;
		hh += mm / 60;
		mm %= 60;
		w = (w + (hh / 24)) % 7;
		day += hh / 24;
		hh %= 24;

		while (day > mdays[m]){
			day -= mdays[m];
			++m;
			if (m > 12){
				m = 1;
				++year;
				mdays[2] = 28 + isleap();
			}
		}
	}else{
		dtz = -dtz;

		tmp = hh*60 + mm;
		while (tmp < dtz){
			dtz -= tmp;
			tmp = 24*60;
			--day;
			w = (w + 6) % 7;
			if (day == 0){
				--m;
				if (m == 0){
					--year;
					m = 12;
					mdays[2] = 28 + isleap();
				}

				day = mdays[m];
			}
		}

		tmp -= dtz;
		hh = tmp / 60;
		mm = tmp % 60;
	}
}

int main(){
	int i;
	char str[10], flag;

	while (1){
		if (scanf("%3s%*1s", str) < 1) break;
		for (w = 0; strcmp(weeks[w], str); ++w);
		scanf("%d %s", &day, str);
		for (m = 0; strcmp(month[m], str); ++m); ++m;

		scanf("%s", str);
		sscanf(str, "%d", &year);
		if (strlen(str) <= 2){
			if (year == 0) year = 2000;
			else if (year < 100) year += 1900;
		}

		scanf("%d:%d:%d %s\n", &hh, &mm, &ss, str);
		if (!strcmp(str, "UT")) strcpy(str, "-0000");
		else if (!strcmp(str, "GMT")) strcpy(str, "-0000");
		else if (!strcmp(str, "EDT")) strcpy(str, "-0400");
		else if (!strcmp(str, "CDT")) strcpy(str, "-0500");
		else if (!strcmp(str, "MDT")) strcpy(str, "-0600");
		else if (!strcmp(str, "PDT")) strcpy(str, "-0700");

		if (str[0] == '-') flag = 1; else flag = 0;
		sscanf(str + 1, "%2d%2d", &tz, &i);
		tz = tz*60 + i;
		if (flag) tz = -tz;

		convert_time();
		--m;
		printf("%s, %.2d %s %.4d %.2d:%.2d:%.2d +0300\n", weeks[w], day, month[m], year, hh, mm, ss);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

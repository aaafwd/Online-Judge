/* @JUDGE_ID: 19899RK 150 C++ "By Anadan" */
// Double Time
// Accepted (0.373 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

const char months[12][10] = {
	"January", "February", "March", "April", "May", "June", "July",
	"August", "September", "October", "November", "December"
};

const char weekdays[7][10] = {
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
	"Saturday"
};

struct Date{
	int yy, mm, dd, oyy, omm, odd;
};
const Date init_date = { 1582, 9, 15, 1582, 9, 5 };
int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

inline int isleap(int yy){
	if (yy & 3) return 0;
	if (yy % 100) return 1;
	if (yy % 400) return 0;
	return 1;
}

void add_day(Date &dt, int new_f, int old_f){
	int tmp;

	if (new_f){
		++dt.dd;
		tmp = days[dt.mm];
		if (dt.mm == 1 && dt.dd == 29 && isleap(dt.yy)) ++tmp;

		if (dt.dd > tmp){
			dt.dd = 1;
			++dt.mm;
			if (dt.mm >= 12){
				dt.mm = 0;
				++dt.yy;
			}
		}
	}

	if (old_f){
		++dt.odd;
		tmp = days[dt.omm];
		if (dt.omm == 1 && dt.odd == 29 && !(dt.oyy & 3)) ++tmp;

		if (dt.odd > tmp){
			dt.odd = 1;
			++dt.omm;
			if (dt.omm >= 12){
				dt.omm = 0;
				++dt.oyy;
			}
		}
	}
}

int main(){
	int yy, mm, dd, ww, week, i, j;
	char str[10];
	Date dt;

	while (scanf("%s", str) == 1 && str[0] != '#'){
		for (ww = 0; strcmp(weekdays[ww], str); ++ww);
		scanf("%d %s %d", &dd, str, &yy);
		for (mm = 0; strcmp(months[mm], str); ++mm);

		week = yy - 1 + ((yy - 1) >> 2) + 5 + dd;
		for (i = 0; i < mm; ++i) week += days[i];
		if (mm > 1 && !(yy & 3)) ++week;
		week %= 7;

		dt = init_date;
		if (week == ww){ // Old style
			i = (yy - 1 - dt.oyy) * 365 + ((yy - 1) >> 2) - 395;
			dt.oyy = yy - 1;
			while (i >= 366){
				++dt.yy;
				i -= 365;
				if (isleap(dt.yy)) --i;
			}

			while (i--) add_day(dt, 1, 0);
			while (dt.oyy != yy || dt.omm != mm || dt.odd != dd){
				add_day(dt, 1, 1);
			}

			printf("%s %d %s %d\n", weekdays[ww], dt.dd, months[dt.mm], dt.yy);

		}else{ // New style
			i = (yy - 1 - dt.yy) * 365 + ((yy - 1) >> 2) - (yy - 1) / 100 + (yy - 1) / 400 - 383;
			dt.yy = yy - 1;
			while (i >= 366){
				++dt.oyy;
				i -= 365;
				if (!(dt.oyy & 3)) --i;
			}

			while (i--) add_day(dt, 0, 1);
			while (dt.yy != yy || dt.mm != mm || dt.dd != dd){
				add_day(dt, 1, 1);
			}

			printf("%s %d* %s %d\n", weekdays[ww], dt.odd, months[dt.omm], dt.oyy);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

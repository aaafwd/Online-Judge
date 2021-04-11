/* @JUDGE_ID: 19899RK 518 C++ "By Anadan" */ 
// Time
// Accepted (0.428 seconds using as much as 388 kbytes)

#include <stdio.h>

int is_leap(int yy){
	if (yy % 4)   return 0;
	if (yy % 100) return 1;
	if (yy % 400) return 0;
	return 1;
}

int main(){
	int yy1, mm1, dd1, hh1, min1, s1, yy2, mm2, dd2, hh2, min2, s2;
	int sec, min, hour, day, month, year, i;
	int max_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char str[21];

	while (scanf("%d%d%d%d%d%d%d%d%d%d%d%d\n", &yy1, &mm1, &dd1, &hh1, &min1, &s1, &yy2, &mm2, &dd2, &hh2, &min2, &s2) == 12){
		sec = min = hour = day = month = year = 0;
		max_days[1] = 28 + is_leap(yy1);

		if (mm1 != 1 || dd1 != 1 || hh1 || min1 || s1) --year;
		if (dd1 != 1 || hh1 || min1 || s1) --month;
		if (hh1 || min1 || s1) --day;
		if (min1 || s1) --hour;
		if (s1) --min;

		if (s1 <= s2) sec += s2 - s1;
		else{
			sec += 60 + s2 - s1;
			++min1;
			++min;
			if (min1 == 60){
				min1 = 0;
				++hh1;
				++hour;
				if (hh1 >= 24){
					hh1 -= 24;
					++dd1;
					++day;
				}
			}
		}

		if (min1 <= min2){
			sec += (min2 - min1) * 60;
			min += min2 - min1;
		}else{
			sec += (60 + min2 - min1) * 60;
			min += 60 + min2 - min1;
			++hh1;
			++hour;
			if (hh1 >= 24){
				hh1 -= 24;
				++dd1;
				++day;
			}
		}

		if (hh1 <= hh2){
			hour += hh2 - hh1;
			min += (hh2 - hh1) * 60;
			sec += (hh2 - hh1) * 3600;
		}else{
			hour += 24 + hh2 - hh1;
			min += (24 + hh2 - hh1) * 60;
			sec += (24 + hh2 - hh1) * 3600;
			++dd1;
			++day;
			if (dd1 > max_days[mm1 - 1]){
				dd1 -= max_days[mm1 - 1];
				++mm1;
				++month;
				if (mm1 > 12){
					mm1 = 1;
					++yy1;
					++year;
					max_days[1] = 28 + is_leap(yy1);
				}
			}
		}

		if (dd1 > max_days[mm1 - 1]){
			dd1 -= max_days[mm1 - 1];
			++mm1;
			++month;
			if (mm1 > 12){
				mm1 = 1;
				++yy1;
				++year;
				max_days[1] = 28 + is_leap(yy1);
			}
		}

		if (mm1 > 2) i = 1; else i = 0;
		while (yy1 < yy2 - 1){
			++year;
			month += 12;
			day   += (365 + is_leap(yy1 + i));
			hour  += (365 + is_leap(yy1 + i)) * 24;
			min   += (365 + is_leap(yy1 + i)) * 1440;
			sec   += (365 + is_leap(yy1 + i)) * 86400;
			++yy1;
		}

		max_days[1] = 28 + is_leap(yy1);
		while (yy1 != yy2 || mm1 != mm2 || dd1 != dd2){
			++dd1;
			++day;
			hour += 24;
			min += 1440;
			sec += 86400;

			if (dd1 > max_days[mm1 - 1]){
				dd1 = 1;
				++mm1;
				++month;
				if (mm1 > 12){
					mm1 = 1;
					++yy1;
					++year;
					max_days[1] = 28 + is_leap(yy1);
				}
			}
		}

		scanf("%d %s\n", &s1, str);
		if (str[0] == 'm' && str[1] == 'i'){
			i = min / s1;
		}else if (str[0] == 'h'){
			i = hour / s1;
		}else if (str[0] == 'd'){
			i = day / s1;
		}else if (str[0] == 'm'){
			i = month / s1;
		}else if (str[0] == 'y'){
			i = year / s1;
		}else i = sec / s1;

		if (i < 0) i = 0;
		printf("%d\n", i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

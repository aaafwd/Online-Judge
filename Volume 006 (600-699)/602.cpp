/* @JUDGE_ID: 19899RK 602 C++ "By Anadan" */ 
// What Day Is It?
// Accepted (0.300 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <time.h>

char months[12][10] = {
	"January", "February", "March", "April", "May", "June", "July",
	"August", "September", "October", "November", "December"
};

char weekdays[7][10] = {
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
	"Saturday"
};

int is_leap_year(int yy){
	if (yy <= 1752) return !(yy % 4);
	if (yy % 4)   return 0;
	if (yy % 100) return 1;
	if (yy % 400) return 0;
	return 1;
}

int isdate(int dd, int mm, int yy){
	int offset, i;
	int days[12] =  { 31, 28 + is_leap_year(yy), 31, 30, 31, 30, 31,
			  31, 30, 31, 30, 31
			};

	if (dd < 1 || mm < 1 || mm > 12 || yy < 0) return 0;
	if (dd > days[mm - 1]) return 0;
	if (yy == 1752 && mm == 9 && 2 < dd && dd < 14) return 0;
	printf("%s %d, %d is a ", months[mm - 1], dd, yy);

	offset = 0;
	if (yy < 1752){
		while (dd != 1 || mm != 1){
			if (++dd > days[mm - 1]) dd = 1, ++mm;
			if (mm > 12) mm = 1, ++yy;
			++offset;
		}
		while (yy % 4) ++offset, ++yy;
		offset += 5 * ((1752 - yy) >> 2);
		yy = 1752;
	}

	if (yy == 1752 && (mm < 9 || (mm == 9 && dd < 3))){
		days[1] = 29;
		while (dd != 2 || mm != 9){
			if (++dd > days[mm - 1]) dd = 1, ++mm;
			++offset;
		}
		offset %= 7;
		offset = (10 - offset) % 7;
		printf("%s\n", weekdays[offset]);
		return 1;
	}

	if (yy > 1752){
		while (dd != 31 || mm != 12){
			if (--dd == 0){
				if (--mm == 0) mm = 12, --yy;
				dd = days[mm - 1];
			}
			++offset;
		}

		offset += (yy + yy / 4 - yy / 100 + yy / 400) % 7;
	}

	while (dd != 14 || mm != 9){
		if (--dd == 0){
			--mm;
			dd = days[mm - 1];
		}
		++offset;
	}
	offset = (offset + 4) % 7;
	printf("%s\n", weekdays[offset]);

	return 1;
}

int main(){
	int dd, mm, yy;

	while (scanf("%d%d%d", &mm, &dd, &yy) == 3){
		if (dd == 0 && mm == 0 && yy == 0) break;
		if (!isdate(dd, mm, yy))
			printf("%d/%d/%d is an invalid date.\n", mm, dd, yy);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

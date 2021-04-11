/* @JUDGE_ID: 19899RK 149 C++ "By Anadan" */ 
// Forests
// Accepted (0.023 seconds with low memory spent)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAXCOORD 20

const double pi_2 = acos(0.0);
const double min_angle = 0.01 * pi_2 / 90.0;
const double min_angle_half = min_angle * 0.5;

int res;
double r;
struct Interval{
	double a1, a2;
	struct Interval *next;
} *head = NULL;

int insert(double a1, double a2){
	Interval *tmp, *p, *prev;
	double max = 0.0;

	p = (Interval *)malloc(sizeof(Interval));
	p->a1 = a1; p->a2 = a2; p->next = NULL;

	if (head == NULL){
		head = p;
		return 1;
	}

	for (tmp = head; tmp; prev = tmp, tmp = tmp->next){
		if (a1 < tmp->a1) break;
		if (max < tmp->a2) max = tmp->a2;
	}

	if (tmp == head){
		p->next = head;
		head = p;
		return (a2 < head->next->a1 && head->next->a1 - a2 > min_angle);
	}

	p->next = tmp;
	prev->next = p;
	if (a1 <= max + min_angle) return 0;
	if (tmp && tmp->a1 <= a2 + min_angle) return 0;

	return 1;
}

void freelist(){
	Interval *tmp;

	while (head){
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void add_to_res(double x, double y){
	int i, j;
	double tmp, len, vx, vy, x1, y1, x2, y2;

	for (i = 1; i < MAXCOORD; ++i){
		for (j = 1; j < MAXCOORD; ++j){
			vx = x - i; vy = y - j;
			len = sqrt(vx * vx + vy * vy);
			tmp = asin(r / len);
			if (tmp <= min_angle_half) break;

			vx *= r / len; vy *= r / len;
			tmp = pi_2 - tmp;
			x1 = vx * cos(tmp) - vy * sin(tmp) + i;
			y1 = vx * sin(tmp) + vy * cos(tmp) + j;
			x2 = vx * cos(tmp) + vy * sin(tmp) + i;
			y2 = -vx * sin(tmp) + vy * cos(tmp) + j;

			x1 = atan2(y1 - y, x1 - x);
			x2 = atan2(y2 - y, x2 - x);

			if (insert(x1, x2)) ++res;
		}
	}
}

int main(){
	double x, y;

	while (scanf("%lf%lf%lf", &r, &x, &y) == 3 && r > 0.01){
		res = 0;
		r *= 0.5;
		add_to_res(x, y); freelist();
		add_to_res(1.0 - x, y); freelist();
		add_to_res(x, 1.0 - y); freelist();
		add_to_res(1.0 - x, 1.0 - y); freelist();
		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

/* @JUDGE_ID: 19899RK 10256 C++ "By Anadan" */ 
// The Great Divide
// Accepted (1.375 seconds using as much as 440 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N[2];
struct Point{
	int x, y;
	double fi;
}pt[500], chull[2][500];

int sort_function(const void *a, const void *b){
	if (((Point *)a)->fi > ((Point *)b)->fi) return -1;
	return 1;
}

int isintriangle(int i, int j, int k){
	int det = (pt[k].x - pt[i].x) * (pt[k].y - pt[j].y) - (pt[k].x - pt[j].x) * (pt[k].y - pt[i].y);
	if (det <= 0) return 1;
	return 0;
}

void convex_hull(int c){
	int i, j, k, sp = 0, stack[500];

	while (N[c] > 0 && pt[N[c] - 1].fi == -100.0) --N[c];
	if (N[c] == 0){
		chull[c][N[c]++] = pt[0];
		return;
	}

	if (N[c] > 2){
		for (j = 0, i = 1; i < N[c]; ++i){
			if (pt[i].x < pt[j].x || (pt[i].x == pt[j].x && pt[i].y < pt[j].y)) j = i;
		}

		stack[sp++] = j++; j %= N[c]; k = j;
		stack[sp++] = j++; j %= N[c];

		while (j != k){
			while (sp > 1 && isintriangle(stack[sp - 2], j, stack[sp - 1])) --sp;
			stack[sp++] = j++; if (j == N[c]) j = 0;
		}
	}else{
		stack[0] = 0; stack[1] = 1;
		sp = N[c];
	}

	N[c] = sp;
	for (i = 0; i < N[c]; ++i) chull[c][i] = pt[stack[i]];
}

int is_in_interval(Point &p1, Point &p2, Point &p3){
	int it1, it2;

	if (p1.x == p2.x && p1.y == p2.y){
		return (p1.x == p3.x && p1.y == p3.y);
	}

	it1 = (p2.x - p1.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p2.y - p1.y);
	if (it1) return 0;

	if (p1.x == p2.x){
		it1 = p1.y;
		it2 = p2.y;
		if (it1 > it2) it1 ^= it2 ^= it1 ^= it2;
		if (it1 <= p3.y && p3.y <= it2) return 1;
	}else{
		it1 = p1.x;
		it2 = p2.x;
		if (it1 > it2) it1 ^= it2 ^= it1 ^= it2;
		if (it1 <= p3.x && p3.x <= it2) return 1;
	}

	return 0;
}

int is_in_polygon(int c, Point &p){
	int i, t1, t2, sign;

	if (is_in_interval(chull[c][0], chull[c][N[c] - 1], p)) return 1;
	t1 = (chull[c][N[c] - 1].x - p.x) * (chull[c][0].y - p.y);
	t2 = (chull[c][0].x - p.x) * (chull[c][N[c] - 1].y - p.y);
	if (t1 == t2) sign = 0;
	else if (t1 > t2) sign = 1; else sign = -1;

	for (i = 0; i < N[c] - 1; ++i){
		if (is_in_interval(chull[c][i], chull[c][i + 1], p)) return 1;
		t1 = (chull[c][i].x - p.x) * (chull[c][i + 1].y - p.y);
		t2 = (chull[c][i + 1].x - p.x) * (chull[c][i].y - p.y);
		if (t1 == t2) continue;
		if (t1 > t2){
			if (sign == -1) return 0;
			sign = 1;
		}
		if (t1 < t2){
			if (sign == 1) return 0;
			sign = -1;
		}
	}

	return sign;
}

int isintersect(int c, Point &p1, Point &p2){
	int i, j, det, it1, it2;

	for (i = 0; i < N[c]; ++i){
		j = ((i == N[c] - 1) ? (0) : (i + 1));
		det = (p2.x - p1.x) * (chull[c][i].y - chull[c][j].y) - (p2.y - p1.y) * (chull[c][i].x - chull[c][j].x);
		it1 = (chull[c][i].x - p1.x) * (chull[c][i].y - chull[c][j].y) - (chull[c][i].y - p1.y) * (chull[c][i].x - chull[c][j].x);
		it2 = (p2.x - p1.x) * (chull[c][i].y - p1.y) - (p2.y - p1.y) * (chull[c][i].x - p1.x);

		if (det < 0) { det = -det; it1 = -it1; it2 = -it2; }
		if (det == 0){
			if (it1 || it2) continue;
			if (is_in_interval(p1, p2, chull[c][i])) return 1;
			if (is_in_interval(p1, p2, chull[c][j])) return 1;
		}else{
			if (!(it1 < 0 || it1 > det || it2 < 0 || it2 > det)) return 1;
		}
	}

	return 0;
}

int main(){
	int i, j;
	double cx, cy;

	while (scanf("%d%d\n", &N[0], &N[1]) == 2 && N[0]){
		for (j = 0; j < 2; ++j){
			cx = cy = 0.0;
			for (i = 0; i < N[j]; ++i){
				scanf("%d%d\n", &pt[i].x, &pt[i].y);
				cx += pt[i].x;
				cy += pt[i].y;
			}

			cx /= N[j]; cy /= N[j];
			for (i = 0; i < N[j]; ++i){
				if (pt[i].y == cy && pt[i].x == cx) pt[i].fi = -100.0;
				else pt[i].fi = atan2(pt[i].y - cy, pt[i].x - cx);
			}

			qsort(pt, N[j], sizeof(Point), sort_function);
			convex_hull(j);
		}

		if (N[0] == 1 && N[1] == 1){
			if (chull[0][0].x == chull[1][0].x && chull[0][0].y == chull[1][0].y){
				printf("No\n");
			}else printf("Yes\n");
			continue;
		}

		if (N[0] <= 1 && N[1] <= 1){
			printf("Yes\n");
			continue;
		}

		for (j = 0; j < 2; ++j){
			for (i = 0; i < N[j]; ++i){
				if (N[j] > 1 && isintersect(j ^ 1, chull[j][i], chull[j][(i + 1) % N[j]])) break;
				if (is_in_polygon(j ^ 1, chull[j][i])) break;
			}

			if (i < N[j]) break;
		}

		printf(j == 2 ? "Yes\n" : "No\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

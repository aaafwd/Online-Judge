/* @JUDGE_ID: 19899RK 10485 C++ "By Anadan" */ 
// Painting with CSE
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct Object{
	int P, x[20], y[20];
};

struct List{
	int N;
	Object obj[20];
};

int printline(char map[10][10], int x1, int y1, int x2, int y2){
	if (x1 == x2){
		if (x1 < 0 || x1 > 9) return 1;
		if (y1 > y2) y1 ^= y2 ^= y1 ^= y2;
		if (y1 > 9 || y2 < 0) return 1;
		if (y1 < 0) y1 = 0; if (y1 > 9) y1 = 9;
		if (y2 < 0) y2 = 0; if (y2 > 9) y2 = 9;
		while (y1 <= y2) map[y1++][x1] = '#';
	}else if (y1 == y2){
		if (y1 < 0 || y1 > 9) return 1;
		if (x1 > x2) x1 ^= x2 ^= x1 ^= x2;
		if (x1 > 9 || x2 < 0) return 1;
		if (x1 < 0) x1 = 0; if (x1 > 9) x1 = 9;
		if (x2 < 0) x2 = 0; if (x2 > 9) x2 = 9;
		while (x1 <= x2) map[y1][x1++] = '#';
	}else return 0;

	return 1;
}

int getnum(char *&p, int &x){
	int sgn = 0;

	x = 0;
	while (*p == ' ') ++p;
	if (*p == '-') { sgn = 1; ++p; }
	if (*p < '0' || *p > '9') return 0;
	while ('0' <= *p && *p <= '9') x = x * 10 + *p++ - '0';
	if (sgn) x = -x;

	return 1;
}

int getobject(Object &obj, char *&p){
	int x1, y1, x2, y2, i;
	Object tmp;

	while (*p == ' ') ++p;
	if (*p == '['){
		++p;
		obj.P = 0;

		while (1){
			while (*p == ' ') ++p;
			if (*p++ != '(') return 0;
			if (!(getnum(p, x2))) return 0;
			while (*p == ' ') ++p;
			if (*p++ != ',') return 0;
			if (!(getnum(p, y2))) return 0;
			while (*p == ' ') ++p;
			if (*p++ != ')') return 0;

			obj.x[obj.P] = x2;
			obj.y[obj.P] = y2;
			++obj.P;

			x1 = x2; y1 = y2;
			while (*p == ' ') ++p;
			if (*p == ',') { ++p; continue; }
			else if (*p == ']') { ++p; break; }
			return 0;
		}

	}else if (*p == 'A'){
		++p;
		while (*p == ' ') ++p;
		if (*p++ != '(') return 0;
		if (!getobject(obj, p)) return 0;
		while (*p == ' ') ++p;
		if (*p++ != ',') return 0;
		if (!getobject(tmp, p)) return 0;
		while (*p == ' ') ++p;
		if (*p++ != ')') return 0;

		if (obj.x[obj.P - 1] != tmp.x[0] || obj.y[obj.P - 1] != tmp.y[0]) return 0;
		for (i = 1; i < tmp.P; ++i){
			obj.x[obj.P] = tmp.x[i];
			obj.y[obj.P] = tmp.y[i];
			++obj.P;
		}

	}else return 0;

	return 1;
}

int getmap(List &ls, char *&p){
	int dx, dy, i, j;
	List tmp;
	Object obj;

	while (1){
		while (*p == ' ') ++p;
		if (*p == 0) return 0;

		if (*p == '[' || *p == 'A'){
			if (!getobject(obj, p)) return 0;
			ls.obj[ls.N++] = obj;

		}else if (*p == 'T'){
			++p;
			while (*p == ' ') ++p;
			if (*p++ != '(') return 0;
			if (!getnum(p, dx)) return 0;
			while (*p == ' ') ++p;
			if (*p++ != ',') return 0;
			if (!getnum(p, dy)) return 0;
			while (*p == ' ') ++p;
			if (*p++ != ',') return 0;
			tmp.N = 0;
			if (!getmap(tmp, p)) return 0;
			while (*p == ' ') ++p;
			if (*p++ != ')') return 0;

			for (i = 0; i < tmp.N; ++i){
				for (j = 0; j < tmp.obj[i].P; ++j){
					tmp.obj[i].x[j] += dx;
					tmp.obj[i].y[j] += dy;
				}
			}

			for (i = 0; i < tmp.N; ++i) ls.obj[ls.N++] = tmp.obj[i];

		}else if (*p == 'S'){
			++p;
			while (*p == ' ') ++p;
			if (*p++ != '(') return 0;
			if (!getnum(p, dx)) return 0;
			while (*p == ' ') ++p;
			if (*p++ != ',') return 0;
			if (!getnum(p, dy)) return 0;
			while (*p == ' ') ++p;
			if (*p++ != ',') return 0;
			tmp.N = 0;
			if (!getmap(tmp, p)) return 0;
			while (*p == ' ') ++p;
			if (*p++ != ')') return 0;

			for (i = 0; i < tmp.N; ++i){
				for (j = 0; j < tmp.obj[i].P; ++j){
					tmp.obj[i].x[j] *= dx;
					tmp.obj[i].y[j] *= dy;
				}
			}

			for (i = 0; i < tmp.N; ++i) ls.obj[ls.N++] = tmp.obj[i];

		}else if (*p == 'R'){
			++p;
			while (*p == ' ') ++p;
			if (*p++ != '(') return 0;
			if (!getnum(p, dx)) return 0;
			if (dx % 90) return 0;
			while (*p == ' ') ++p;
			if (*p++ != ',') return 0;
			tmp.N = 0;
			if (!getmap(tmp, p)) return 0;
			while (*p == ' ') ++p;
			if (*p++ != ')') return 0;

			if (dx >= 0) dx = (dx / 90) & 3;
			else{
				dx = (-dx / 90) & 3;
				if (dx & 1) dx ^= 2;
			}

			for (i = 0; i < tmp.N; ++i){
				for (j = 0; j < tmp.obj[i].P; ++j){
					if (dx == 1){
						dy = tmp.obj[i].y[j];
						tmp.obj[i].y[j] = tmp.obj[i].x[j];
						tmp.obj[i].x[j] = -dy;
					}
					else if (dx == 2){
						tmp.obj[i].x[j] = -tmp.obj[i].x[j];
						tmp.obj[i].y[j] = -tmp.obj[i].y[j];
					}
					else if (dx == 3){
						dy = tmp.obj[i].y[j];
						tmp.obj[i].y[j] = -tmp.obj[i].x[j];
						tmp.obj[i].x[j] = dy;
					}
				}
			}

			for (i = 0; i < tmp.N; ++i) ls.obj[ls.N++] = tmp.obj[i];

		}else return 0;

		while (*p == ' ') ++p;
		if (*p == ')' || *p == 0) break;
		if (*p++ != 'u') return 0;
	}

	return 1;
}

int main(){
	int set = 0, i, j;
	char str[150], map[10][10], *p;
	List ls;

	while (1){
		gets(str);
		if (str[0] == '#' && str[1] == 0) break;

		p = str;
		ls.N = 0;
		memset(map, '.', sizeof(map));
		if (getmap(ls, p) == 0 || *p){
			map[0][0] = '?';
		}else{
			for (i = 0; i < ls.N; ++i){
				printline(map, ls.obj[i].x[0], ls.obj[i].y[0], ls.obj[i].x[0], ls.obj[i].y[0]);
				for (j = 1; j < ls.obj[i].P; ++j){
					if (!printline(map, ls.obj[i].x[j - 1], ls.obj[i].y[j - 1], ls.obj[i].x[j], ls.obj[i].y[j])) break;
				}

				if (j < ls.obj[i].P) break;
			}

			if (i < ls.N){
				memset(map, '.', sizeof(map));
				map[0][0] = '?';
			}
		}

		printf("Set #%d\n", ++set);
		for (i = 9; i >= 0; --i){
			for (j = 0; j < 10; ++j) putchar(map[i][j]);
			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

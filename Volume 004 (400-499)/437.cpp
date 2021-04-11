/* @JUDGE_ID: 19899RK 437 C++ "By Anadan" */ 
// The Tower of Babylon
// Accepted (0.025 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

int index;
struct Block{
	int x, y, z;
}opt[90], pt[30];

int sort_function(const void *a, const void *b){
	Block *pa = (Block *)a, *pb = (Block *)b;
	if (pa->x < pb->x) return -1;
	if (pa->x > pb->x) return 1;
	if (pa->y < pb->y) return -1;
	if (pa->y > pb->y) return 1;
	return 0;
}

void add(int x, int y, int z){
	int i;

	if (x > y) x ^= y ^= x ^= y;
	for (i = 0; i < index; ++i) if (opt[i].x == x && opt[i].y == y) break;
	if (i < index){
		if (opt[i].z < z) opt[i].z = z;
	}else{
		opt[i].x = x; opt[i].y = y; opt[i].z = z;
		++index;
	}
}

int improve(int x, int y, int z){
	int i, res = 0;
	Block tmp, *p;

	if (x > y) x ^= y ^= x ^= y;
	tmp.x = x; tmp.y = y;
	p = (Block *)bsearch(&tmp, opt, index, sizeof(Block), sort_function);
	for (i = 0; i < index; ++i){
		if (opt[i].x > x && opt[i].y > y){
			if (p->z < opt[i].z + z){
				p->z = opt[i].z + z;
				res = 1;
			}
		}
	}

	return res;
}

int main(){
	int set = 0, N, i;
	char changed;

	while (scanf("%d\n", &N) == 1 && N){
		index = 0;
		for (i = 0; i < N; ++i){
			scanf("%d%d%d\n", &pt[i].x, &pt[i].y, &pt[i].z);
			add(pt[i].x, pt[i].y, pt[i].z);
			add(pt[i].x, pt[i].z, pt[i].y);
			add(pt[i].y, pt[i].z, pt[i].x);
		}

		qsort(opt, index, sizeof(Block), sort_function);

		changed = 1;
		while (changed){
			changed = 0;
			for (i = 0; i < N; ++i){
				changed |= improve(pt[i].x, pt[i].y, pt[i].z);
				changed |= improve(pt[i].x, pt[i].z, pt[i].y);
				changed |= improve(pt[i].y, pt[i].z, pt[i].x);
			}
		}

		N = opt[0].z;
		for (i = 1; i < index; ++i) if (N < opt[i].z) N = opt[i].z;
		printf("Case %d: maximum height = %d\n", ++set, N);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

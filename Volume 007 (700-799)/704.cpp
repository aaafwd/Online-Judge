/* @JUDGE_ID: 19899RK 704 C++ "By Anadan" */ 
// Colour Hash
// Accepted (1.336 seconds using as much as 704 kbytes)

#include <stdio.h>
#include <string.h>
#define MAXSTEPS 16
#define ENDDEPTH 5
#define SZ 500

#include <time.h>

struct EndPos{
	int pos[24], step;
	char toend[ENDDEPTH];
}endpos[SZ];

int minstep, N;
char move[16], best[16], initflag;
char hash[262144] = { 0 };
const int finalpos[24] = { 0,3,4,3,0,5,6,5,0,1,2,1,0,7,8,7,0,9,10,9,0,1,2,1 };

inline int isfinalpos(int *currpos){
	return (memcmp(currpos, finalpos, sizeof(finalpos)) == 0);
}

inline int makehash(int *a){
	return ( (a[5] >> 1) | ((a[7] >> 1) << 3) | ((a[9] >> 1) << 6) | ((a[11] >> 1) << 9) | ((a[13] >> 1) << 12) | ((a[19] >> 1) << 15) );
}

void rot_left_wheel(int c_clockwize, int *currpos, int *nextpos){
	int i;

	if (c_clockwize){ // Counter-Clockwise rotation
		for (i = 0; i < 12; ++i) nextpos[i] = currpos[(i + 2) % 12];
		for (; i < 21; ++i) nextpos[i] = currpos[i];
		for (; i < 24; ++i) nextpos[i] = nextpos[i - 12];
	}else{
		for (i = 0; i < 12; ++i) nextpos[i] = currpos[(i + 10) % 12];
		for (; i < 21; ++i) nextpos[i] = currpos[i];
		for (; i < 24; ++i) nextpos[i] = nextpos[i - 12];
	}
}

void rot_right_wheel(int c_clockwize, int *currpos, int *nextpos){
	int i;

	if (c_clockwize){ // Counter-Clockwise rotation
		for (i = 12; i < 24; ++i) nextpos[i] = currpos[12 + (i - 2) % 12];
		for (i = 0; i < 9; ++i) nextpos[i] = currpos[i];
		for (; i < 12; ++i) nextpos[i] = nextpos[i + 12];
	}else{
		for (i = 12; i < 24; ++i) nextpos[i] = currpos[12 + (i - 10) % 12];
		for (i = 0; i < 9; ++i) nextpos[i] = currpos[i];
		for (; i < 12; ++i) nextpos[i] = nextpos[i + 12];
	}
}

int alreadywas(int N, int *nextpos){
	int i;
	for (i = 0; i < N; ++i) if (memcmp(endpos[i].pos, nextpos, sizeof(finalpos)) == 0) return 1;
	return 0;
}

void init(){
	int i = 0, j = 1, nextpos[24];

	memcpy(endpos[0].pos, finalpos, sizeof(finalpos));
	endpos[0].toend[0] = 0;
	endpos[0].step = 0;

	while (i < j){
		if (endpos[i].step == ENDDEPTH) break;

		// 1 Left Wheel Clockwise rotation
		rot_left_wheel(0, endpos[i].pos, nextpos);
		if (!alreadywas(i, nextpos)){
			memcpy(endpos[j].pos, nextpos, sizeof(finalpos));
			endpos[j++].step = endpos[i].step + 1;
		}

		// 2 Right Wheel Clockwise rotation
		rot_right_wheel(0, endpos[i].pos, nextpos);
		if (!alreadywas(i, nextpos)){
			memcpy(endpos[j].pos, nextpos, sizeof(finalpos));
			endpos[j++].step = endpos[i].step + 1;
		}

		// 3 Left Wheel Counter-Clockwise rotation
		rot_left_wheel(1, endpos[i].pos, nextpos);
		if (!alreadywas(i, nextpos)){
			memcpy(endpos[j].pos, nextpos, sizeof(finalpos));
			endpos[j++].step = endpos[i].step + 1;
		}

		// 4 Right Wheel Counter-Clockwise rotation
		rot_right_wheel(1, endpos[i].pos, nextpos);
		if (!alreadywas(i, nextpos)){
			memcpy(endpos[j].pos, nextpos, sizeof(finalpos));
			endpos[j++].step = endpos[i].step + 1;
		}		

		++i;
	}

	N = j;
}

void solvepuzzle(int step, int *currpos, int prevrot){
	int i, nextpos[24];

	if (initflag){
		if (minstep <= step) return;

		if (isfinalpos(currpos)){
			minstep = step;
			memcpy(best, move, step);
			return;
		}
	}else{
		if (minstep <= step + ENDDEPTH) return;

		if (hash[makehash(currpos)]) for (i = 0; i < N; ++i){
			if (minstep <= step + endpos[i].step) break;
			if (memcmp(endpos[i].pos, currpos, sizeof(finalpos)) == 0){
				minstep = step + endpos[i].step;
				memcpy(best, move, step);
				memcpy(best + step, endpos[i].toend, endpos[i].step);
				return;
			}
		}
	}

	// 1 Left Wheel Clockwise rotation
	move[step] = '1';
	if (prevrot != 3){
		rot_left_wheel(0, currpos, nextpos);
		solvepuzzle(step + 1, nextpos, 1);
	}

	// 2 Right Wheel Clockwise rotation
	move[step] = '2';
	if (prevrot != 4){
		rot_right_wheel(0, currpos, nextpos);
		solvepuzzle(step + 1, nextpos, 2);
	}

	// 3 Left Wheel Counter-Clockwise rotation
	move[step] = '3';
	if (prevrot != 1){
		rot_left_wheel(1, currpos, nextpos);
		solvepuzzle(step + 1, nextpos, 3);
	}

	// 4 Right Wheel Counter-Clockwise rotation
	move[step] = '4';
	if (prevrot != 2){
		rot_right_wheel(1, currpos, nextpos);
		solvepuzzle(step + 1, nextpos, 4);
	}
}

int main(){
	int set, currpos[24], i, j;

	initflag = 1;
	init();

	for (i = 0; i < N; ++i){
		minstep = endpos[i].step + 1;
		solvepuzzle(0, endpos[i].pos, 0);
		endpos[i].step = minstep;
		memcpy(endpos[i].toend, best, minstep);
		hash[makehash(endpos[i].pos)] = 1;
	}
	initflag = 0;

	scanf("%d\n", &set);
	while (set--){
		for (i = 0; i < 24; ++i){
			while ((j = getchar()) > '9' || j < '0');
			currpos[i] = j - '0';
			if ((j = getchar()) == '0') currpos[i] = 10;
		}

		minstep = MAXSTEPS + 1;
		solvepuzzle(0, currpos, 0);

		if (minstep == 0) puts("PUZZLE ALREADY SOLVED");
		else if (minstep > MAXSTEPS) puts("NO SOLUTION WAS FOUND IN 16 STEPS");
		else{
			for (i = 0; i < minstep; ++i) putchar(best[i]);
			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

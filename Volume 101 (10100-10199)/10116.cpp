/* @JUDGE_ID: 19899RK 10116 C++ "By Anadan" */ 
// Robot Motion
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int i, j, str, stl, nstl, step, flag[10][10];
char pole[10][11];

int func(){
    for (i = 0; i < str; i++) memset(flag[i], 0, 10*sizeof(int));

    i = step = 0, j = nstl-1;
    while (1){
	  step++;
	  if ((i < 0) || (i >= str)) return 1;
	  if ((j < 0) || (j >= stl)) return 1;
	  if (flag[i][j]) return 0;
	  flag[i][j] = step;
	  switch (pole[i][j]){
	  case 'N': i--; break;
	  case 'W': j--; break;
	  case 'E': j++; break;
	  case 'S': i++; break;
	  }
    }
}

int main(){
    while (scanf("%d%d%d\n", &str, &stl, &nstl) == 3){
	if ((!str) && (!stl) && (!nstl)) break;
	for (i = 0; i < str; i++) scanf("%s\n", pole[i]);
	if (func()){
		printf("%d step(s) to exit\n", step - 1);
	}else{
		printf("%d step(s) before a loop of %d step(s)\n", flag[i][j] - 1, step - flag[i][j]);
	}
    }

    return 0;
}
/* @END_OF_SOURCE_CODE */

/* @JUDGE_ID: 19899RK 10308 C++ "By Anadan" */ 
// Roads in the North
// Accepted (0.012 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int vertexes[10000], edge[20000], value[20000], next[20000], sp, res;

void addedge(int i, int j, int k){
	int index;

	if (vertexes[i] == -1){
		vertexes[i] = sp;
	}else{
		index = vertexes[i];
		while (next[index] != -1) index = next[index];
		next[index] = sp;
	}

	edge[sp] = j;
	value[sp] = k;
	next[sp] = -1;
	++sp;
}

int getmaxh(int v, int p){
	int i, a1 = 0, a2 = 0, maxh = 0, tmp;

	i = vertexes[v];
	while (i != -1){
		if (edge[i] != p){
			tmp = getmaxh(edge[i], v) + value[i];
			if (maxh < tmp) maxh = tmp;
			if (tmp > a1) tmp ^= a1 ^= tmp ^= a1;
			if (tmp > a2) a2 = tmp;
		}

		i = next[i];
	}

	if (res < a1 + a2) res = a1 + a2;
	return maxh;
}

int mytriplesscanf(char *p, int &i, int &j, int &k){
	i = j = k = 0;

	while (*p == ' ') ++p;
	if (*p < '0' || *p > '9') return 0;
	while ('0' <= *p && *p <= '9') i = i * 10 + *p++ - '0';

	while (*p == ' ') ++p;
	if (*p < '0' || *p > '9') return 0;
	while ('0' <= *p && *p <= '9') j = j * 10 + *p++ - '0';

	while (*p == ' ') ++p;
	if (*p < '0' || *p > '9') return 0;
	while ('0' <= *p && *p <= '9') k = k * 10 + *p++ - '0';

	return 1;
}

int main(){
	int i, j, k;
	char str[128];

	while (gets(str)){
		sp = 0;
		memset(vertexes, -1, sizeof(vertexes));
		while (mytriplesscanf(str, i, j, k)){
			--i; --j;
			addedge(i, j, k);
			addedge(j, i, k);
			if (!gets(str)) break;
		}

		res = 0;
		getmaxh(0, -1);
		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

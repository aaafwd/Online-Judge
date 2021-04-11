/* @JUDGE_ID: 19899RK 593 C++ "By Anadan" */
// MBone
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXREC 50000

int R, G, answer;
struct Router{
	char name[21];
	int hosts;
	long host_addr[50];
}rt[10];
struct Group{
	long group_addr;
	int ingroup;
	long host_addr[50];
}gr[20];
struct Received{
	long host_addr, pack_id;
	int ttl;
}rec[MAXREC];
int tunnels[10][10];

int getrouter(char *str){
	int i;
	for (i = 0; i < R; ++i) if (!strcmp(rt[i].name, str)) return i;
	strcpy(rt[R].name, str);
	rt[R].hosts = 0;
	return R++;
}

int sort_function(const void *a, const void *b){
	Received *ra = (Received *)a, *rb = (Received *)b;
	if (ra->host_addr < rb->host_addr) return -1;
	else if (ra->host_addr > rb->host_addr) return 1;
	if (ra->pack_id < rb->pack_id) return -1;
	else if (ra->pack_id > rb->pack_id) return 1;
	if (ra->ttl < rb->ttl) return -1;
	return 1;
}

void join_to_group(long hst_addr, long gr_addr){
	int i, j;
	for (i = 0; i < 20; ++i){
		if (gr[i].ingroup && gr[i].group_addr == gr_addr){
			++gr[i].ingroup;
			for (j = 0; j < 50; ++j){
				if (gr[i].host_addr[j] == -1){
					gr[i].host_addr[j] = hst_addr;
					break;
				}
			}
			return;
		}
	}

	for (i = 0; i < 20; ++i) if (gr[i].ingroup == 0) break;
	gr[i].ingroup = 1;
	gr[i].group_addr = gr_addr;
	gr[i].host_addr[0] = hst_addr;
	for (j = 1; j < 50; ++j) gr[i].host_addr[j] = -1;
}

void remove_from_group(long hst_addr, long gr_addr){
	int i, j;
	for (i = 0; i < 20; ++i) if (gr[i].ingroup && gr[i].group_addr == gr_addr) break;
	for (j = 0; j < 50; ++j){
		if (gr[i].host_addr[j] == hst_addr){
			gr[i].host_addr[j] = -1;
			break;
		}
	}
	--gr[i].ingroup;
}

int getrouterbyhost(long hst_addr){
	int i, j;
	for (i = 0; i < R; ++i){
		for (j = 0; j < rt[i].hosts; ++j){
			if (rt[i].host_addr[j] == hst_addr) return i;
		}
	}

	return -1;
}

void send_packet(long hst_addr, long gr_addr, long pack_id, int ttl){
	int g1 = getrouterbyhost(hst_addr), g2, i, j;
	for (i = 0; i < 20; ++i) if (gr[i].ingroup && gr[i].group_addr == gr_addr) break;
	for (j = 0; j < 50; ++j){
		if (gr[i].host_addr[j] != -1){
			g2 = getrouterbyhost(gr[i].host_addr[j]);
			if (tunnels[g1][g2] != -1 && tunnels[g1][g2] <= ttl){
				rec[answer].host_addr = gr[i].host_addr[j];
				rec[answer].pack_id = pack_id;
				rec[answer].ttl = ttl - tunnels[g1][g2];
				++answer;
			}
		}
	}
}

int main(){
	long tmp, gr_addr, pack_id;
	char str[21], id[2];
	int i, j, k, m, g1, g2, ttl, set = 0;

	while (scanf("%d\n", &m) == 1 && m){
		for (i = 0; i < m; ++i){
			for (j = 0; j < m; ++j) tunnels[i][j] = -1;
			tunnels[i][i] = 0;
		}

		for (R = i = 0; i < m; ++i){
			scanf("%s %d\n", str, &k);
			g1 = getrouter(str);
			for (j = 0; j < k; ++j){
				scanf("%s", id);
				if (id[0] == 'T'){
					scanf("%ld %s\n", &tmp, str);
					g2 = getrouter(str);
					if (tunnels[g1][g2] == -1 || tunnels[g1][g2] > tmp) tunnels[g1][g2] = tmp;
				}else if (id[0] == 'H'){
					scanf("%ld\n", &tmp);
					rt[g1].host_addr[rt[g1].hosts++] = tmp;
				}else return 1;
			}
		}

		// Floyd-Yorshell`s algorithm
		for (i = 0; i < m; ++i){
			for (j = 0; j < m; ++j){
				if (j == i) continue;
				for (k = 0; k < m; ++k){
					if (k == i) continue;
					if (tunnels[j][i] == -1 || tunnels[i][k] == -1) continue;
					if (tunnels[j][k] == -1 || tunnels[j][k] > tunnels[j][i] + tunnels[i][k])
						tunnels[j][k] = tunnels[j][i] + tunnels[i][k];
				}
			}
		}

		scanf("%d\n", &m);
		answer = 0;
		for (G = i = 0; i < 20; ++i) gr[i].ingroup = 0;
		while (m--){
			scanf("%s", id);
			if (id[0] == 'J'){
				scanf("%ld %ld\n", &tmp, &gr_addr);
				join_to_group(tmp, gr_addr);
			}else if (id[0] == 'L'){
				scanf("%ld %ld\n", &tmp, &gr_addr);
				remove_from_group(tmp, gr_addr);
			}else if (id[0] == 'S'){
				scanf("%ld %ld %ld %d\n", &tmp, &gr_addr, &pack_id, &ttl);
				send_packet(tmp, gr_addr, pack_id, ttl);
			}else return 2;
		}

		printf("Network #%d\n", ++set);
		qsort((void *)rec, answer, sizeof(Received), sort_function);
		for (i = 0; i < answer; ++i)
			printf("%ld %ld %d\n", rec[i].host_addr, rec[i].pack_id, rec[i].ttl);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

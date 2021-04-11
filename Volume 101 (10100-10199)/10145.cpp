/* @JUDGE_ID: 19899RK 10145 C++ "By Anadan" */
// Lock Manager
// Accepted (0.150 seconds using as much as 600 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 16384

const int jumps[4] = { 101, 223, 5023, 7001 };

inline int gethash(int x){
	return x & (SZ - 1);
}

struct tag_blocked {
	int arr[SZ];
	
	inline void init() { memset(arr, 0, sizeof(arr)); }
	
	int isset(int x){
		int i = gethash(x);
		while (1){
			if (arr[i] == 0) break;
			else if (arr[i] == x) return 1;
			i = (i + jumps[i & 3]) & (SZ - 1);
		}
		return 0;
	}

	void set(int x){
		int i = gethash(x);
		while (arr[i] != 0) i = (i + jumps[i & 3]) & (SZ - 1);
		arr[i] = x;
	}

} blocked;

struct tag_lock {
	int arr[SZ], trid[SZ];
	char exclusive[SZ];

	inline void init() { memset(arr, 0, sizeof(arr)); }

	int try_set(int t, int l, int x){
		int i = gethash(l);
		while (arr[i] != 0 && arr[i] != l) i = (i + jumps[i & 3]) & (SZ - 1);
		if (arr[i] == 0){
			arr[i] = l;
			trid[i] = t;
			exclusive[i] = x;
			return 1;
		}else if (trid[i] == t){
			if (x) exclusive[i] = 1;
			return 1;
		}else{
			if (x || exclusive[i]) return 0;
			trid[i] = -1;
			return 1;
		}
	}

} lock;

void solve(){
	int i, j;
	char s[2];

	blocked.init();
	lock.init();

	while (scanf("%s", s) == 1 && s[0] != '#'){
		scanf("%d%d", &i, &j);
		if (blocked.isset(i)) puts("IGNORED");
		else if (lock.try_set(i, j, (s[0] == 'X' || s[0] == 'x'))) puts("GRANTED");
		else{
			puts("DENIED");
			blocked.set(i);
		}
	}
}

int main(){
	int set;

	scanf("%d", &set);
	while (set--){
		solve();
		if (set) putchar('\n');
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */

/* @JUDGE_ID: 19899RK 10088 C++ "By Anadan" */
// Trees on My Island
// Accepted (0.105 seconds using as much as 388 kbytes)

#include <stdio.h>

typedef long long qword;
struct Point{
	qword x, y;
};

qword gcd(qword x, qword y){
	if (x < 0) x = -x;
	if (y < 0) y = -y;
	while (x && y) if (x > y) x %= y; else y %= x;
	if (x) return x; else return y;
}

int main(){
	int N, i;
	qword S, b;
	Point p0, p1, p2;

	while (scanf("%d\n", &N) == 1 && N){
		scanf("%lld%lld%lld%lld", &p0.x, &p0.y, &p1.x, &p1.y);

		S = 0;
		b = gcd(p0.x - p1.x, p0.y - p1.y);

		for (i = 2; i < N; ++i){
			scanf("%lld%lld", &p2.x, &p2.y);
			b += gcd(p2.x - p1.x, p2.y - p1.y);
			S += (p0.x - p1.x) * (p0.y - p2.y) - (p0.x - p2.x) * (p0.y - p1.y);
			p1 = p2;
		}

		b += gcd(p0.x - p1.x, p0.y - p1.y);
		if (S < 0) S = -S;

		// Formula Pika: S = b/2 + i - 1, where b - bound, i - in
		printf("%lld\n", ((S - b) >> 1) + 1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

/* @JUDGE_ID: 19899RK 10335 C++ "By Anadan" */ 
// Ray Inside a Polygon
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int V, edge;
struct Point{
	double x, y;
}pt[10], norm[10], p, vect;
const double eps = 0.005;

int getintersection(){
	int j, k;
	double tmp, det, it1, it2;
	Point q;

	for (j = 0; j < V; ++j){
		if (j == edge) continue;
		k = ((j == V - 1) ? (0) : (j + 1));

		det = vect.x * (pt[j].y - pt[k].y) - vect.y * (pt[j].x - pt[k].x);
		if (fabs(det) < 1e-12) continue;
		it1 = (pt[j].x - p.x) * (pt[j].y - pt[k].y) - (pt[j].y - p.y) * (pt[j].x - pt[k].x);
		it2 = vect.x * (pt[j].y - p.y) - vect.y * (pt[j].x - p.x);
		det = 1.0 / det; it1 *= det; it2 *= det;

		q.x = p.x + vect.x * it1;
		q.y = p.y + vect.y * it1;

		if (fabs(q.x - p.x) <= eps && fabs(q.y - p.y) <= eps) continue;

		if (fabs(q.x - pt[j].x) <= eps && fabs(q.y - pt[j].y) <= eps) break;
		if (fabs(q.x - pt[k].x) <= eps && fabs(q.y - pt[k].y) <= eps) break;

		if (it2 <= 0.0 || it2 >= 1.0) continue;

		tmp = (vect.x * norm[j].x + vect.y * norm[j].y) * 2.0;
		vect.x -= tmp * norm[j].x;
		vect.y -= tmp * norm[j].y;

		p = q;
		edge = j;

		return 1;
	}

	return 0;
}

int main(){
	int N, i, j;
	double tmp;
	const double pi_180 = acos(0.0) / 90.0;

	while (scanf("%d%d\n", &V, &N) == 2 && V){
		scanf("%lf%lf%lf\n", &p.x, &p.y, &tmp);
		for (i = 0; i < V; ++i) scanf("%lf%lf", &pt[i].x, &pt[i].y);
		vect.x = cos(tmp * pi_180);
		vect.y = sin(tmp * pi_180);

		for (i = 0; i < V; ++i){
			j = ((i == V - 1) ? (0) : (i + 1));
			norm[i].x = pt[i].y - pt[j].y;
			norm[i].y = pt[j].x - pt[i].x;
			tmp = sqrt(norm[i].x * norm[i].x + norm[i].y * norm[i].y);
			norm[i].x /= tmp; norm[i].y /= tmp;
		}

		edge = -1;
		for (i = 0, ++N; i < N; ++i){
			if (getintersection() == 0) break;
		}

		if (i < N) printf("lost forever...\n");
		else{
			printf("%.2lf %.2lf\n", p.x + 1e-12, p.y + 1e-12);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

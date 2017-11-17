#include <cstdio>

struct pos {
	int x;
	int y;
};

bool isInside(const pos &p1, const pos &p2, int r){
	return ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) < r * r);
}

int check(const pos &start, const pos &end, const pos &center, int r){
	return isInside(start, center, r) ^ isInside(center, end, r);
}

int main() {
	int T, n, r, count;
	pos start, end, point;
	scanf("%d", &T);
	for(; T > 0; --T) {
		scanf("%d%d%d%d", &start.x, &start.y, &end.x, &end.y);
		scanf("%d", &n);
		count = 0;
		for(; n > 0; --n) {
			scanf("%d%d%d", &point.x, &point.y, &r);
			count += check(start, end, point, r);
		}
		printf("%d\n", count);
	}
	return 0;
}
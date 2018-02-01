#include <cstdio>

#define MIN(X, Y) ((X) > (Y)) ? (Y) : (X)

int main() {
	int x, y, w, h;
	int result = 0;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	
	result = MIN(x, w - x);
	result = MIN(y, result);
	result = MIN(h - y, result);
	printf("%d", result);
	
	return 0;
}
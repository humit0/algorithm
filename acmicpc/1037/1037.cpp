#include <cstdio>
#define MAX(X, Y) ((X) > (Y)) ? (X) : (Y)
#define MIN(X, Y) ((X) < (Y)) ? (X) : (Y)

int main() {
	int result = 1;
	int num, val, m, M;
	
	scanf("%d", &num);
	scanf("%d", &val);
	m = M = val;
	for(;num > 1; --num) {
		scanf("%d", &val);
		m = MIN(m, val);
		M = MAX(M, val);
	}
	printf("%d", m * M);
	
	return 0;
}
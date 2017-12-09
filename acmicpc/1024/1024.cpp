#include <cstdio>

int main() {
	int N, L, k, a, b;
	scanf("%d%d", &N, &L);
	N *= 2;
	a = b = -1;
	for(int i = L; i <= 100; ++i) {
		if(N % i == 0) {
			k = N / i;
			if((i + k) % 2 == 0) continue;
			b = (i + k - 1) / 2;
			a = k - b;
			if(a >= 0 && b >= 0) break;
		}
		
	}
	if(a >= 0 && b >= 0) {
		for(int i = a; i <= b; ++i) {
			printf("%d ", i);
		}
	} else {
		printf("%d", -1);
	}
	
	return 0;
}
#include <cstdio>

unsigned int func(unsigned int n) {
	int m = n / 2;
	if(n % 2) { // odd
		return (m + 1) * (m + 1); 
	} else { // even
		return m * (m + 1);
	}
}
int main() {
	int T;
	unsigned int a, b, n, i;
	scanf("%d", &T);
	for(; T > 0; --T) {
		scanf("%u%u", &a, &b);
		n = b - a;
		for(i = 1; n > func(i); ++i);
		printf("%d\n", i);
	}
	return 0;
}
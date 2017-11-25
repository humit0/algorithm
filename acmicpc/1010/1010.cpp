#include <cstdio>

// calculate combination...
int comb(int a, int b) {
	int result = b;
	if(2 * a > b) a = b - a;
	if(a == 0) return 1;
	for(int i = 2; i <= a; ++i) {
		result *= (b - i + 1);
		result /= i;
	}
	return result;
}

int main() {
	int T, a, b;
	scanf("%d", &T);
	for(; T > 0; --T) {
		scanf("%d%d", &a, &b);
		printf("%d\n", comb(a, b));
	}
	return 0;
}
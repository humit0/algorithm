#include <cstdio>

int main() {
	int n, f, result;
	scanf("%d%d", &n, &f);
	n = ((n / 100) * 100) % f;
	for(result = 0; result < 100; ++result) {
		if((n + result) % f == 0) break;
	}
	if(result < 10) printf("0");
	printf("%d", result);
	return 0;
}
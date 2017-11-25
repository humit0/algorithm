#include <cstdio>

#define DIVISOR 10

int pow(int a, int b) {
	int result;
	if(b == 0) return 1;
	else if(b == 1) return a % DIVISOR;
	else {
		result = pow(a, b / 2);
		if(b % 2) { // odd
			result = (result * result * a) % DIVISOR;
		} else {
			result = (result * result) % DIVISOR;
		}
		return result;
	}
}

int main() {
	int N, a, b;
	scanf("%d", &N);
	for(; N > 0; --N) {
		scanf("%d%d", &a, &b);
		a = a % 10;
		b = (b + 3) % 4 + 1;
		if(a == 0) printf("10\n");
		else printf("%d\n", pow(a, b));
	}
	return 0;
}
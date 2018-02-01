#include <cstdio>

int ARR[16];

long long int recursive(int N, int r, int c) {
	if(N == 0) return 0;
	int k = ARR[N - 1];
	if(r < k && c < k) {
		return recursive(N - 1, r, c);
	}
	else if(r < k && c >= k) {
		return recursive(N - 1, r, c - k) + k * k;
	}
	else if(r >= k && c < k) {
		return recursive(N - 1, r - k, c) + 2 * k * k;
	}
	else {
		return recursive(N - 1, r - k, c - k) + 3 * k * k;
	}
}

int main() {
	int N, r, c;
	for(int i = 0; i < 16; ++i) {
		ARR[i] = 1 << i;
	}
	scanf("%d%d%d", &N, &r, &c);
	printf("%lld", recursive(N, r, c));
	return 0;
}
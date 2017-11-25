// using Rearrangement inequality
#include <cstdio>
#include <algorithm>

#define MAX_N 50

using namespace std;

int A[MAX_N] = { 0 };
int B[MAX_N] = { 0 };

int main() {
	int n, sum;

	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
	for(int i = 0; i < n; ++i) {
		scanf("%d", &B[i]);
	}

	sort(A, A + n);
	sort(B, B + n);

	sum = 0;
	for(int i = 0; i < n; ++i) {
		sum += A[i] * B[n - i - 1];
	}

	printf("%d", sum);

	return 0;
}
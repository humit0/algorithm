#include <cstdio>

int main() {
	int N, cnt, j;
	
	scanf("%d", &N);
	// 한자리 수나 두자리 수는 항상 등차수열이다.
	if(N < 100) printf("%d", N);
	else {
		cnt = 99;
		for(j = 100; j <= N; ++j)
			if((j / 100) + (j % 10) == 2 * ((j / 10) % 10)) ++cnt;
		printf("%d", cnt);
	}
	return 0;
}
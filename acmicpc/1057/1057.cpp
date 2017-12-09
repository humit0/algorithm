#include <cstdio>

int main() {
	int N, jimin, hansu, round = 0;
	scanf("%d%d%d", &N, &jimin, &hansu);
	
	while(jimin != hansu) {
		jimin = (jimin + 1) / 2;
		hansu = (hansu + 1) / 2;
		++round;
	}
	printf("%d", round);
	return 0;
}
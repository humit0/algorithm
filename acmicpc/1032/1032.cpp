#include <cstdio>

#define MAX_LEN 50
#define MAX_N 50

char strs[MAX_N][MAX_LEN + 1];

int main() {
	int N, i, j;
	char result[MAX_LEN + 1], ch;
	scanf("%d", &N);
	for(i = 0; i < N; ++i) {
		scanf("%s", strs[i]);
	}
	for(i = 0; strs[0][i] != '\0'; ++i) {
		ch = strs[0][i];
		for(j = 1; j < N; ++j) {
			if(ch != strs[j][i]) {
				ch = '?';
				break;
			}
		}
		result[i] = ch;
	}
	result[i] = '\0';
	printf("%s", result);
	return 0;
}
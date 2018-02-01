#include <cstdio>

int main() {
	char ch;
	int cnt = 0, result = 0;
	while((ch = getchar()) != EOF){
		if(cnt % 2 == 0 && ch == 'F') ++result;
		++cnt;
	}
	printf("%d", result);
	return 0;
}
#include <cstdio>
#include <cstring>

char str[][10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };

int main() {
	int i, result;
	char s[11];
	scanf("%s", s);
	for(i = 0; i < 10; ++i) {
		if(!strcmp(str[i], s)) break;
	}
	result = i;
	scanf("%s", s);
	for(i = 0; i < 10; ++i) {
		if(!strcmp(str[i], s)) break;
	}
	result = result * 10 + i;
	scanf("%s", s);
	for(i = 0; i < 10; ++i) {
		if(!strcmp(str[i], s)) break;
	}
	if(result == 0) {
		printf("0");
		return 0;
	}
	printf("%d", result);
	for(; i > 0; --i) printf("0");
	
	return 0;
}
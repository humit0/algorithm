#include <cstdio>

int main() {
	int d, mask, result;
	mask = 64;
	result = 0;
	
	scanf("%d", &d);
	while(mask) {
		if(d & mask) ++result;
		mask >>= 1;
	}
	printf("%d", result);
	return 0;
}
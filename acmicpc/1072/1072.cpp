#include <cstdio>

int main(){
	long long int x, y, z;
	while(scanf("%lld%lld", &x, &y) != EOF){
		z = 100 * y / x;
		printf("%d\n", (z >= 99) ? -1 : ((z + 1) * x - 100 * y + 98 - z) / (99 - z));
	}
	return 0;
}
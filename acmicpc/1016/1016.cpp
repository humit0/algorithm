#include <cstdio>
#include <vector>

#define ARR_SIZE 1000000

std::vector<long long int> square;
bool check[ARR_SIZE + 1];

int main() {
	long long int min, max, val, j, ans;
	int i, size;
	ans = 0;
	scanf("%lld%lld", &min, &max);
	for(val = 2; val * val <= max; ++val) {
		square.push_back(val * val);
	}
	size = square.size();
	for(i = 0; i < max - min + 1; ++i) {
		check[i] = false;
	}
	for(i = 0; i < size; ++i) {
		for(j = (min / square[i]) * square[i]; j <= max; j += square[i]) {
			if(j - min < 0) continue;
			if(!check[j - min]) {
				check[j - min] = true;
				++ans;
			}
		}
	}
	printf("%lld", max - min - ans + 1);
	return 0;
}
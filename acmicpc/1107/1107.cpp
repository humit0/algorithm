#include <cstdio>
#include <cmath>
#include <algorithm>

#define START 100

bool can_push[10];

bool check_possible(int num) {
	if(num == 0) return can_push[0];
	while(num) {
		if(!can_push[num % 10]) return false;
		num /= 10;
	}
	return true;
}

int len(int num) {
	int result = 0;
	if(num == 0) return 1;
	while(num) {
		num /= 10;
		++result;
	}
	return result;
}

int get_result(int src, int dst) {
	int push = std::abs(dst - src);
	int start = std::max(0, dst - push);
	int end = dst + push;
	for(int num = start; num < end; ++num) {
		if(check_possible(num)) push = std::min(push, abs(dst - num) + len(num));
	}
	return push;
}

int main() {
	int N, M, val, push;
	scanf("%d", &N);
	for(int i = 0; i < 10; ++i) can_push[i] = true;
	scanf("%d", &M);
	for(int i = 0; i < M; ++i) {
		scanf("%d", &val);
		can_push[val] = false;
	}
	if(M < 10) push = get_result(START, N);
	else push = std::abs(N - START);
	printf("%d", push);
	return 0;
}
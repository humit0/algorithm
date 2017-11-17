#include <cstdio>
#include <vector>

struct data {
	int num0;
	int num1;
};

std::vector<data> datas = std::vector<data>(41);

int main() {
	int T, N, i;
	datas[0].num0 = 1; datas[0].num1 = 0;
	datas[1].num0 = 0; datas[1].num1 = 1;
	for(i = 2; i <= 40; ++i) {
		datas[i].num0 = datas[i - 1].num0 + datas[i - 2].num0;
		datas[i].num1 = datas[i - 1].num1 + datas[i - 2].num1;
	}
	scanf("%d", &T);
	for(; T > 0; --T) {
		scanf("%d", &N);
		printf("%d %d\n", datas[N].num0, datas[N].num1);
	}
	return 0;
}
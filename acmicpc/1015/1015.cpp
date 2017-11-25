#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define MAX_N 50

struct data {
	int value;
	int idx;
};

vector<data> items;
int results[MAX_N + 1];

bool compare(const data& lh, const data& rh) {
	if(lh.value != rh.value) return lh.value < rh.value;
	else return lh.idx <rh.idx;
}

int main() {
	int n, i;

	scanf("%d", &n);
	items = vector<data>(n);

	for(i = 0; i < n; ++i) {
		scanf("%d", &items[i].value);
		items[i].idx = i;
	}
	sort(items.begin(), items.end(), compare);
	
	for(i = 0; i < n; ++i) {
		results[items[i].idx] = i;
	}

	for(i = 0; i < n; ++i) {
		printf("%d ", results[i]);
	}

	return 0;
}
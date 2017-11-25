#include <cstdio>
#include <utility> // for pair.
#include <queue>

#define MAX_N 50

using namespace std;

int arr[MAX_N + 2][MAX_N + 2];
bool check[MAX_N + 2][MAX_N + 2];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void bfs(int x, int y) {
	queue <pair<int, int> > q;
	q.push(make_pair(x, y));
	check[y][x] = true;
	
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx, ny;
			nx = x + dx[i]; ny = y + dy[i];
			if(arr[ny][nx] == 1 && !check[ny][nx]) {
				q.push(make_pair(nx, ny));
				check[ny][nx] = true;
			}
		}
	}
}

int main() {
	int T, M, N, K, x, y, count;
	scanf("%d", &T);
	for(; T > 0; --T) {
		scanf("%d%d%d", &M, &N, &K);
		count = 0;
		for(int y = 0; y <= N + 1; ++y) {
			for(int x = 0; x <= M + 1; ++x) {
				arr[y][x] = 0;
				check[y][x] = false;
			}
		}
		for(; K > 0; --K) {
			scanf("%d%d", &x, &y);
			++x; ++y;
			arr[y][x] = 1;
		}
		for(int y = 1; y <= N; ++y) {
			for(int x = 1; x <= M; ++x) {
				if(arr[y][x] == 1 && !check[y][x]) {
					bfs(x, y);
					++count;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
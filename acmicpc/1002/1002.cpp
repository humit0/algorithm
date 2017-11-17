#include <iostream>

using namespace std;

int get_result(int x1, int x2, int y1, int y2, int r1, int r2);

int main(){
	int T, x1, x2, y1, y2, r1, r2;
	
	cin >> T;
	for (int i = 0; i < T; i++){
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		cout << get_result(x1, x2, y1, y2, r1, r2) << endl;
	}
	return 0;
}

int get_result(int x1, int x2, int y1, int y2, int r1, int r2){
	int d2, r_m, r_p;
  // 조규현과 백승환 사이의 거리 계산.
	d2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	
  // 거리가 0인 경우 반지름이 다르면 존재할 수 없고, 반지름이 같으면 원 위에 있을 수 있으므로 개수가 무한대이다.
	if (d2 == 0)
		return (r1 == r2) ? -1 : 0;
  // 안쪽 거리
	r_m = (r1 - r2) * (r1 - r2);
  // 바깥쪽 거리
	r_p = (r1 + r2) * (r1 + r2);
	if (r_p > d2 && d2 > r_m)
		return 2;
	else if (r_p == d2 || r_m == d2)
		return 1;
	else return 0;
}
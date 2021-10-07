#include <iostream>
#include <algorithm>

using namespace std;

int n;

struct day {
	int x, y;
};

day arr[1000009];

bool check(day a, day b) {
	return a.x <= b.x;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].x;
		arr[i].y = i;
	}
	sort(arr + 1, arr + n + 1, check);
	for (int i = 1; i <= n; i++) if (i < arr[i].y) cout << i << " " << arr[i].y << endl;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 50005;
const int oo = 1e8;

struct nodes
{
	long long val;
	long long lazy;
}; 
nodes st[4 * N];
int n, m;

void update(int l, int r, int x, int y, int id, int value) {
	if (l > y || r < x) return;
	if (l >= x && r <= y) {
		st[id].val += value;;
		st[id].lazy += value;
		return;
	}
	long long t = st[id].lazy;
	st[id * 2].lazy += t;
	st[id * 2].val += t;
	st[id * 2 + 1].lazy += t;
	st[id * 2 + 1].val += t;
	st[id].lazy = 0;
	int mid = (l + r) / 2;
	update(l, mid, x, y, id * 2, value);
	update(mid + 1, r, x, y, id * 2 + 1, value);
	st[id].val = max(st[id * 2].val,st[id * 2 + 1].val); 
}

long long findMax(int l, int r, int x, int y, int id) {
	if (l > y || r < x) return -oo;
	if (l >= x && r <= y) {
		return st[id].val;
	}
	long long t = st[id].lazy;
	st[id * 2].lazy += t;
	st[id * 2].val += t;
	st[id * 2 + 1].lazy += t;
	st[id * 2 + 1].val += t;
	st[id].lazy = 0;
	int mid = (l + r) / 2;
	return max(findMax(l,mid,x,y,id * 2),findMax(mid + 1,r,x,y,id * 2 + 1));

}

int main(int argc, char const *argv[])
{
	//freopen("toffees.inp","r",stdin);
	cin >> n >> m;
	while (m--) {
		int status, x, y, value;
		cin >> status >> x >> y;
		if (!status) {
			cin >> value;
			update(1,n,x,y,1,value);
		}
		else cout << findMax(1,n,x,y,1) << endl;
	}
	return 0;
}
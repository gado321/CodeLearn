#include <bits/stdc++.h>

using namespace std;

struct ed
{
	int x;
	int y;
};

ed edge[1000];
int n, tmpx, tmpy, emin;

bool cmp(ed a, ed b)
{
	return (a.x * b.y > b.x * a.y);
}

int main(int argc, char const *argv[])
{
	cin >> n;
	tmpx = 999999; 
	tmpy = 999999;
	for (int i = 1; i <= n; i++) 
	{
		cin >> edge[i].x >> edge[i].y;
		if (tmpy > edge[i].y)
		{
			tmpy = edge[i].y;
			tmpx = edge[i].x;
		}
		else if (tmpy == edge[i].y)
		{
			if (tmpx > edge[i].x) tmpx = edge[i].x;			
		}
	}
	for (int i = 1; i <= n; i++) 
	{
		edge[i].x -= tmpx;
		edge[i].y -= tmpy;
	}
	cout << "--------" << endl;
	sort(edge + 1,edge + n + 1,cmp);
	for (int i = 1; i <= n; i++) cout << edge[i].x << " " << edge[i].y << endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n;

void swapp(int t1, int m1, int t2, int m2)
{
	if (m1 + m2 > n) return;
	else
	{
		swapp(t1, m1, t1 + t2, m1 + m2);
			cout << t1 + t2 << "/" << m1 + m2 << endl;
		swapp(t1 + t2, m1 + m2, t2, m2);
	}
}

int main(int argc, char const *argv[])
{
	cin >> n;
	cout << "0/1" << endl;
	swapp(0,1,1,1);
	cout << "1/1";
	return 0;
}

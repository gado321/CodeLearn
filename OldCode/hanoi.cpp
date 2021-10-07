#include <bits/stdc++.h>

using namespace std;

int n;
char a = 'A', b = 'B', c = 'C';

void hanoi(int n, int a, int b, int c)
{
	if (n == 1)
	{
		cout << "Move " << a << " to " << c << endl;
		return;
	}
	else
	{
		hanoi(n - 1,a,c,b);
		hanoi(1,a,b,c);
		hanoi(n - 1,b,a,c);
	}
}
int main(int argc, char const *argv[])
{
	cin >> n;
	hanoi(n,1,2,3);
	return 0;
}
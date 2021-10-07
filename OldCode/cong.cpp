#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	a = rand() % 10000 - 1;
	b = rand() % 10000 - 1;
	c = rand() % 10000 - 1;
	if ((a + b > c && a + c > b && c + b > a) && (a > 0 && b > 0 && c > 0)) cout << "YES";
	else cout << "NO";
	return 0;
}
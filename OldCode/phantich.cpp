#include <bits/stdc++.h>

using namespace std;

int n, x[1000], t[1000];

void back(int i)
{
	for (int j = x[i - 1]; j <= (n - t[i - 1]) / 2; j++)
	{\
		x[i] = j;
		t[i] = t[i - 1] + j;
		back(i + 1);
	}
	x[i] = n - t[i - 1];
	for (int k = 1; k <= i; k++) cout << x[k] << " ";
	cout << endl; 
}

int main(int argc, char const *argv[])
{
	cin >> n;
	x[0] = 1;
	back(1);
	return 0;
}
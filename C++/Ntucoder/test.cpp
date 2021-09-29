#include <iostream>
#include <stack>

int n, ok[50], ans;

bool check()
{
	stack<int> st;
	for (int i = 1; i <= n; i++)
		if (ok[i])
			st.push(1);
		else
			st.pop();
	if (!st.size())
	{
		for (int i = 1; i <= n; i++)
			if (ok[i])
				cout << "(";
			else
				cout << ")";
		return 1;
	}
	return 0;
}

void back(int num)
{
	for (int i = 0; i <= 1; i++)
	{
		if (!ok[num])
		{
			ok[num] = 1;
			if (i == n / 2)
			{
				if (check())
				{
					ans++;
					cout << "\n";
				}
			}
			else
				back(num + 1);
			ok[num] = 0;
		}
	}
}

int main()
{
	cin >> n;
	back(1);
	cout << ans;
	return 0;
}
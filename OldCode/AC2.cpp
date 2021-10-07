#include <bits/stdc++.h>

using namespace std;

string s, x, ss, tmpstr;
int a, b, test, tmp, f1, f2, maxi, c1, c2;

int main(int argc, char const *argv[])
{
	freopen("AC2.inp","r",stdin);
	freopen("AC2.out","w",stdout);
	scanf("%d%d",&test);
	while (test--)
	{
		c1 = c2 = 0;
		cin >> s >> x;
		scanf("%d%d",&a,&b);
		tmp = a + b;  
		maxi = max(a,b);
		getline(cin,tmpstr);
		while (tmp--)
		{
			getline(cin,ss);
			f1 = ss.find(s); 
			f2 = ss.find(x);
			if (f1) c1++;
			if (f2) c2++; 
			if (((f1 && (!a || !b)) || (f2 && (!a || !b))) || ((c1 == maxi) || (c2 == maxi))) 
			{
				cout << ss << "\n"; 
				break;
			}
		}
	}
	return 0;
}
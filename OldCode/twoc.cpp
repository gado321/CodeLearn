#include <bits/stdc++.h>

using namespace std;

int n, cnt[1005], ans;
char s[1005];

int main(int argc, char const *argv[])
{
	freopen("twoc.inp","r",stdin);
	freopen("twoc.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		cnt[int(s[i])]++;
	}
	for (int i = 60; i <= 120; i++) 
		for (int j = i + 1; j <= 120; j++) {
			if (cnt[i] && cnt[j]) {
				stack <char> st;
				bool is = 0;
				for (int k = 1; k <= n; k++) {
					char x = (char)(i);
					char y = (char)(j);
					if (s[k] == x || s[k] == y) {
						if (!st.size()) st.push(s[k]);
						else {
							char tmp = st.top();
							if (s[k] != tmp) st.push(s[k]);
							else {
								is = 1;					
								break;
							}
						}
					}					
				}
				int c = st.size();
				if (is) c = 0;
				ans = max(ans,c);
			}
		}
	cout << ans;
	return 0;
}
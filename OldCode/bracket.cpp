#include <bits/stdc++.h>

using namespace std;

int ans, tmp, cnt, pre;
string s;
stack <char> st;

int main(int argc, char const *argv[])
{
	freopen("bracket.inp","r",stdin);
	//freopen("bracket.out","w",stdout);
	cin >> s;
	s += 'C';
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
			if (st.size() == 1) ans = max(ans,tmp);
		}
		else if (!st.empty() && s[i] == ')') {
			st.pop();
			tmp += 2;
		}
		else if (st.empty() && s[i] == ')') {
			ans = max(ans,tmp);	
			tmp = 0;
		}
		else if (s[i] == 'C') {
			if (!st.empty()) ans = max(ans,tmp - ans); 
			else ans = max(ans,tmp);
			tmp = 0;
		}
	}
	if (!ans) {cout << -1; return 0;}
	cout << ans;
	tmp = 0;
	while (!st.empty()) st.pop();
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
			if (st.size() == 1) {
				pre = tmp;
				if (tmp == ans) cnt++;
			}
		}
		else if (!st.empty() && s[i] == ')') {
			st.pop();
			tmp += 2;
		}
		else if (st.empty() && s[i] == ')') {
			if (tmp == ans) cnt++;
			tmp = 0;
		}
		else if (s[i] == 'C') {
			if (!st.empty()) {
				if (tmp - pre == ans) cnt++; 
			} 
			else {
				if (tmp == ans) cnt++;
			}
			tmp = 0;
		}
	}
	cout << " " << cnt;
	return 0;
}
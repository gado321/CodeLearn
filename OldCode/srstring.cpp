#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

string s;
vector <char> vt;
stack <char> st;

int main(int argc, char const *argv[])
{
	freopen("srstring.inp","r",stdin);
	freopen("srstring.out","w",stdout);
	cin >> s;
	st.push(s[0]);
	int i = 1;
	while (i < s.size()) {
		if (!st.size()) st.push(s[i]);
		else {
			if (st.top() == s[i]) st.pop();
			else st.push(s[i]);
		}
		i++;
	}
	if (!st.size()) {cout << "Empty String"; return 0;}
	while (st.size()) {
		vt.push_back(st.top());
		st.pop();
	}
	for (int i = vt.size() - 1; i >= 0; i--) cout << vt[i];
	return 0;
}
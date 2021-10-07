#include <bits/stdc++.h>

using namespace std;

int t;

int main(int argc, char const *argv[])
{
	freopen("SPC6.inp","r",stdin);
    freopen("SPC6.out","w",stdout);
    cin >> t;
    while (t--)
    {
        string s;
        stack <int> st;
        long long ans = 0;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(') st.push(0);
            else if (s[i] == ')')
            {
                int tmp = 0;
                while (!st.empty() && st.top() != 0)
                {
                    tmp += st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == 0)
                {
                    st.pop();
                    st.push(tmp);
                }
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                int so = s[i] - '0';
                if (!st.empty())
                {
                    int tmp = st.top();
                    st.pop();
                    tmp = tmp * so;
                    st.push(tmp);
                }
            }
            else if (s[i] == 'C') st.push(12);
            else if (s[i] == 'H') st.push(1);
            else if (s[i] == 'O') st.push(16);
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        cout << ans << endl;
    }
    return 0;
}
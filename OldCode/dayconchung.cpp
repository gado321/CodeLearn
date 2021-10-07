#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string s1, s2;
bool dp1[1005], dp2[1005];

int main()
{
    cin >> s1;
    cin >> s2;
    for (int i = 0; i < s1.size(); i++)
        for (int j = 0; j < s2.size(); j++)
            if (dp2[j] == 0 && dp1[i] == 0 && s1[i] == s2[j])
            {
                dp1[i] = 1;
                dp2[j] = 1;
                break;
            }
    for (int i = 0; i < s1.size(); i++) cout << dp1[i]; cout << endl;
    for (int j = 0; j < s2.size(); j++) cout << dp2[j];
    return 0;
}

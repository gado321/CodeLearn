#include<iostream>

using namespace std;

string s, t, mini = "9999999999999999999", maxi = "0";

void back(int x,int y,string ans){
    if (ans.size() == s.size() + t.size()){
        mini = min(ans,mini);
        maxi = max(ans,maxi);
    }
    if (x < s.size()) back(x + 1, y, ans + s[x]);
    if (y < t.size()) back(x, y + 1, ans + t[y]);
}

int main (){
    cin >> s >> t;
    back(0,0,"");
    cout << mini << "\n" << maxi;
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int n, ok[30], check[3000000], cnt, ans;
string a, b, s[3000000];

void back(int num){
    for (int i = 0; i <= 1; i++){
        if (!ok[num]){
            ok[num] = i;
            if (num == n){
                cnt++;
                for (int j = 0 ; j < n; j++){
                    if (!ok[j + 1]) s[cnt] += a[j];
                    else s[cnt] += b[j]; 
                }
            }
            else back(num + 1);
            ok[num] = 0;
        }
    }
}

int main(){
    cin >> n;
    cin >> a >> b;
    back(1);
    sort(s + 1, s + cnt + 1);
    for (int i = 1; i <= cnt; i++){
        if (s[i + 1] == s[i]) check[i + 1] = 1;
        else ans++;
    }
    cout << ans << "\n";
    for (int i = 1; i <= cnt; i++) 
        if (!check[i]) cout << s[i] << "\n";
    return 0;
}
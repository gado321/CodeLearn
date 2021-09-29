#include <iostream>
#include <vector>

using namespace std;

int n, q, lastAnswer;
vector<vector<int>> a(100005,vector<int>(0));

int main(){
    cin >> n >> q;
    while (q--){
        int t, x, y;
        cin >> t >> x >> y;
        int idx = (x ^ lastAnswer) % n;
        if (t == 1){
            a[idx].push_back(y);
        }
        else{
            lastAnswer = a[idx][y % a[idx].size()];
            cout << lastAnswer << endl; 
        }
    }
    return 0;
}
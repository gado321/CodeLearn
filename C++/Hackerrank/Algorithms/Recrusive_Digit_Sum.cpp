#include <iostream>
#include <algorithm>

using namespace std;

string n;
int k;

long long stringToNum(string s) {
    long long cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = (int)(s[i] - '0');
        cnt += c;
    }
    return cnt;
}

string numToString(long long num) {
    string t = "";
    while (num) {
        string tmp = to_string(num % 10);
        t += tmp;
        num /= 10;
    }
    reverse(t.begin(),t.end());
    return t;
}

long long superDigit(long long number) {
    if (number < 10) return number;
    return superDigit(stringToNum(numToString(number)));
}

int main() {
    cin >> n >> k;
    cout << superDigit(stringToNum(n) * k);
    return 0;
}
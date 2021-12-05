#include <iostream>
#include <cmath>
using namespace std;
#include <bits/stdc++.h>

int check(int n){   
	if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

int TongUocChung(int m, int n){
    int sum = 0;
    for (int i = 1; i <= __gcd(m,n); i++)
        if (m % i == 0 && n % i == 0) sum += i;
    if (!sum) return -1;
    return sum;
}

void input(int &n) {
    cin >> n;
}

int input() {
	int m;
	cin >> m;
	return m;
}

int main(){
    int a, b;
    a=input();
    input(b);
    std::cout << TongUocChung(a, b);
    return 0;
}
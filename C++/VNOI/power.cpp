#include <iostream>
#include <math.h>

using namespace std;

const long long MAX = 1e12;

int t;
long long Left, Right;

long long power(long long n, int k) {
    long long tmp = 1;
    for (int i = 1; i <= k; i++) tmp *= n;
    return tmp;
}

int bsearch(long long l, long long r, int k) {
    long long mid;
    while (l < r) {
        mid = l + (r - l) / 2;
        //cout << mid << endl;
        if (power(mid,k) < Left) l = mid + 1;
        else if (power(mid,k) > Right) r = mid;
        else return mid;
    }
    return 0;
}

int main() {
    freopen("test.inp","r",stdin);
    scanf("%d",&t);
    for (int u = 1; u <= t; u++) {
        scanf("%lld%lld",&Left,&Right);
        for (int i = 40; i > 0; i--){
            long long rr = (long long)(pow( Right, 1.0 / i) + 10);
            int ans = bsearch(0,rr,i);
            if (ans) {
                printf("Case #%d: %d\n",u,i);
                break;
            }
        }
    }
    return 0;
}

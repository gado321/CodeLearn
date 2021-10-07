#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef pair<int, int> ii;

int n;
long long ans;
ii origin, a[1000005];

bool ccw(ii O, ii A, ii B) {
    A.X -= O.X; A.Y -= O.Y;
    B.X -= O.X; B.Y -= O.Y;
    return A.X * B.Y > A.Y * B.X;
}

bool cmp(ii A, ii B) { 
    return ccw(origin, A, B); 
}
    
int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].X, &a[i].Y);
    sort(a + 1, a + n + 1);
    origin = a[1];
    sort(a + 2, a + n + 1, cmp);
    a[0] = a[n]; a[n + 1] = a[1];
    int j = 1;
    for (int i = 1; i <= n + 1; i++) {
        while (j > 2 && !ccw(a[j - 2], a[j - 1], a[i])) j--;
        a[j++] = a[i];
    }
    n = j - 2;
    //for (int i = 1; i <= n; i++) printf("%d %d\n", a[i].X, a[i].Y);
    a[0] = a[n]; a[n + 1] = a[1];
    for (int i = 1; i <= n; i++)
        ans += (a[i].X - a[i + 1].X) * (a[i + 1].Y + a[i].Y);
    ans = abs(ans);
    cout << ans / 2 << "." << ((ans % 2) * 10) / 2;
}
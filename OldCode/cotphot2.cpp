#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int N = (int) 1e5 + 1;

int n, s, k, t;
int c[N], v[N], g[N], dist[N + 5] = {0};

void SORT(int l, int r)
{
    int i = l, j = r;
    srand(time(NULL));
    int m = v[l + rand() % (r - l + 1)];
    while (i <= j)
    {
        while (v[i] < m) i++;
        while (v[j] > m) j--;
        if (i <= j)
        {
            swap(v[i],v[j]);
            swap(c[i],c[j]);
            i++;
            j--;
        }
    }
    if (l < j) SORT(l, j);
    if (i < r) SORT(i, r);
}

int Bin_search(int x)
{

    int m = x;
    while (true){
    int sum = 0;
    bool check = true;
    FOR(i, 1, k + 1)
    {
        if (dist[i] > v[m]) {check =false; break;}
        else if (dist[i] * 2 <= v[m]) sum += dist[i];
        else if (dist[i] * 2 > v[m])
        {
            int tmp = (dist[i] * 2 - v[m]);
            sum += (tmp * 2) + (v[m] - tmp);
        }
        cout << check << " " << sum << endl;
    }
    if (sum < t) check = false;
    if (check == true && m == 1) return m;
    if (check == false && m == n) return -1;
    if (check == true) m--;
    if (check == false) m++;
    }
}

int main()
{
    freopen("test.inp","r",stdin);
    cin >> n >> k >> s >> t;
    FOR(i, 1, n) cin >> c[i] >> v[i];
    FOR(i, 1, k)  cin >> g[i];
    sort(g + 1, g + k + 1);
    g[k + 1] = s;
    FOR(i, 1, k + 1) dist[i] = g[i] - dist[i - 1];
    SORT(1,n);
    FOR(i, 1, n) cout << c[i] << " " << v[i] << " " << endl;
    cout << endl << Bin_search((1 + n) / 2);
    int Min = (int) 1e9;
    //FOR(i, Bin_search((1 + n) / 2), n) Min = min(Min, c[i]);
    //cout << Min;
    return 0;
}

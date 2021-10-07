#include <bits/stdc++.h>

using namespace std;

int st[10000], n;
int a[10000];

void update(int l, int r, int pos) {
  if (l == r) 
  {
    st[pos] = a[l];
    return;
  }
  if (l > r) return;
  int mid = (l + r) / 2;
  update(l,mid,pos * 2);
  update(mid + 1,r,pos * 2 + 1);
  //st[pos] = st[pos * 2] + st[pos * 2 + 1];
  st[pos] = max(st[pos * 2],st[pos * 2 + 1]);
}

//TIM TONG TREN DOAN [L,R] BAT KI
// int findSum(int l, int r,int x, int y, int pos) {
//   if ((l > y || r < x)) {
//     return 0;
//   }
//   if (l >= x && r <= y) {
//     return st[pos];
//   }
//   int mid = (l + r) / 2;
//   return findSum(l,mid,x,y,pos * 2) + findSum(mid + 1,r,x,y,pos * 2 + 1);;
// }

int findMax(int l, int r,int x, int y, int pos) {
  if (l > y || r < x) return -1;
  if (l >= x && r <= y) return st[pos];
  int mid = (l + r) / 2;
  return max(findMax(l,mid,x,y,pos * 2),findMax(mid + 1,r,x,y,pos * 2 + 1));
}

int main(int argc, char const *argv[])
{
  freopen("toffees.inp","r",stdin);
  //freopen("toffees.out","w",stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  update(1,n,1);
  for (int i = 1; i <= 4 * n; i++) cout << st[i] << " "; cout << endl;
  cout << findMax(1,n,2,4,1);
  return 0;
}
#include <iostream>

using namespace std;

int k, mod;
long long n;
int pow[7] = {1, 2, 4, 8, 16, 32, 64};

int main()
{
	cin >> n >> k;
	mod = n % 100;
	int i, dem = 0;
    while (dem < k){
        if (n % 100 != 0)
        {
            for (i = 1; i <= 6; i++)
                if (pow[i] * mod > 100 || i == 6 || dem + i > k)
                {
                    n += pow[i - 1] * mod - mod;
                    dem += i - 1;
                    if (dem < k)
                    {
                        n += n % 100;
                        mod = n % 100;
                        dem++;
                    }
                    break;
                }
        }
        else break;}
	cout << n;
	return 0;
}

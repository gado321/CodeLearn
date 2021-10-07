#include <bits/stdc++.h>
#include <sstream>

using namespace std;

string a[20];
string table[10][5];
string Date = "Thứ";
int ordinalNumber[20];
bool ok[20];

int main(int argc, char const *argv[])
{
	freopen("Class_List.inp","r",stdin);
	freopen("Class_List_Out.inp","w",stdout);
	srand(time(NULL));
	for (int i = 1; i <= 18; i++) getline(cin,a[i]);
	for (int i = 1; i <= 6; i++) table[i][1] = Date + " " + (char)((i + 1) + '0');
	for (int i = 1; i <= 6; i++)
		for (int j = 2; j <= 4; j++) {
			int stt = 0;
			do { 
				stt = rand() % (18 - 1 + 1) + 1;
			} while (ok[stt]);
			ok[stt] = 1;
			table[i][j] = a[stt];
		}
	for (int i = 1; i <= 6; i++) cout << table[i][1] << ",";
	cout << "\n";
	for (int i = 2; i <= 4; i++) {
		for (int j = 1; j <= 6; j++) cout << table[j][i] << ",";
		cout << "\n";
	}
	return 0;
}
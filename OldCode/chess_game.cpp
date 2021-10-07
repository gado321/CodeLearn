#include <bits/stdc++.h>

using namespace std;

int n, m, ok, turn, cnt;

void COM(int &box1, int &box2, int &sta)
{
	if ((box1 == 1 && box2 == 1)) 
	{
		cout << "YOU WIN!";
		sta = 1; return;
	}
	else if ((box1 == 0 || box2 == 0))
	{
		cout << "YOU LOSE!";
		sta = 1; return;
	}
	int best_choice = 0;
	if (box1 % 2 != 0 && box2 % 2 != 0) 
	{
		best_choice = max(box1,box2);
		if (best_choice == box1) cout << "COM pick first box!\n";
		else cout << "COM pick second box!\n";
		box1 = 1; box2 = best_choice - 1;
	}
	else
	{
		if (box1 % 2 == 0 && box2 % 2 == 0)
		{
			best_choice = min(box1,box2);
			if (best_choice == box1) cout << "COM pick first box!\n";
			else cout << "COM pick second box!\n";
			box1 = 1; 
			box2 = best_choice - 1;	
		}
		else if (box1 % 2 == 0) 
		{
			cout << "COM pick first box!\n"; 
			box2 = box1 - 1; box1 = 1;
		}
		else if (box2 % 2 == 0) 
		{
			cout << "COM pick second box!\n";
			best_choice = box2 / 2;
			box1 = box2 - 1; box2 = 1;
		}
	}
}

void player(int &box1, int &box2, int &sta)
{
	if (box1 == 1 && box2 == 1) 
	{
		cout << "YOU LOSE!";
		sta = 1; return;
	}
	else if ((box1 == 0 || box2 == 0))
	{
		cout << "YOU WIN!";
		sta = 1; return;
	}
	int t, choice;
	cout << "Pick your box: ";
	cin >> t;
	if (t == 1) choice = box1;
	else choice = box2;
	cout << "Divine " << choice << " chessmans in box" << t <<" into two box: \n";
	cout << "First box: "; cin >> box1;
	box2 = choice - box1;
}

int main(int argc, char const *argv[])
{
	printf("Amount of first box: \n");
	cin >> n;
	printf("Amount of second box: \n");
	cin >> m;
	printf("Chose your turn: \n");
	printf("1: You first: \n");
	printf("2: COM first: \n");
	cin >> turn;
	while (1)
	{
		if (ok) return 0;
		cout << "===== ROUND " << ++cnt << " =====\n";
		printf("Amount of first box: %d\n",n);
		printf("Amount of second box: %d\n",m);
		if (turn == 2)
		{
			COM(n,m,ok);
			if (ok) break;
			printf("Amount of first box: %d\n",n);
			printf("Amount of second box: %d\n",m);
			player(n,m,ok);
		}
		else 
		{
			player(n,m,ok);
			if (ok) break;
			printf("Amount of first box: %d\n",n);
			printf("Amount of second box: %d\n",m);
			COM(n,m,ok);
		}
	}
	sleep(3000);
	return 0;
}
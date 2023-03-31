#include <iostream>

using namespace std;

int main()
{
	int nTest;
	cin >> nTest;

	for(int j = 1; j <= nTest; j++)
	{
		bool flag = false;

		int number;
		cin >> number;

		if (number % 7 == 0)
		{
			cout << number << "\n";
			continue;
		}

		int temp1 = number;
		for (int i = 1; i <= 9; i++)
		{
			temp1 -= temp1 % 10;
			temp1 += i;

			if (temp1 % 7 == 0)
			{
				cout << temp1 << "\n";
				flag = true;
				break;
			}
		}
		if (flag) continue;

		int temp2 = number;
		for (int i = 1; i <= 9; i++)
		{
			temp2 -= (temp2 % 100) * 10;
			temp2 += i * 10;


			if (temp2 % 7 == 0)
			{
				cout << temp2 << "\n";
				flag = true;
				break;
			}
		}
		if (flag) continue;

		int temp3 = number;
		for (int i = 1; i <= 9; i++)
		{
			temp3 -= (temp3 % 10) * 100;
			temp3 += i * 100;


			if (temp3 % 7 == 0)
			{
				cout << temp3 << "\n";
				flag = true;
				break;
			}
		}

	}
}

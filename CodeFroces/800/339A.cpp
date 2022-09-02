#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string senSum;
    cin >> senSum;

	int nNum = (senSum.length() / 2) + 1;
    int* numSum = new int[nNum];

	for (int i = 0; i < senSum.length(); i += 2)
	{
		switch (senSum[i])
		{
		case '1':
			numSum[i / 2] = 1;
			break;

		case '2':
			numSum[i / 2] = 2;
			break;

		case '3':
			numSum[i / 2] = 3;
			break;

			default:
				break;
		}
	}

	for (int i = 0; i < nNum; i++)
	{
		for (int j = 0; j < nNum - i - 1; j++)
		{
			if (numSum[j] > numSum[j + 1])
			{
				int temp = numSum[j];
				numSum[j] = numSum[j + 1];
				numSum[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < nNum; i++)
	{
		if (i != nNum - 1) cout << numSum[i] << "+";
		else cout << numSum[i];
	}

}

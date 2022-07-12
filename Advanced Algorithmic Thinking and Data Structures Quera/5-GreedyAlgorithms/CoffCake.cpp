//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//
//	int maxA = 0, minA = 5001;
//
//	int* a = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//		if (a[i] > maxA) maxA = a[i];
//		if (a[i] < minA) minA = a[i];
//	}
//
//	if (k == 1) cout << maxA;
//	else if (k > 2) cout << minA;
//	else cout << min(a[0], a[n - 1]);
//
//	cout << "\n";
//}
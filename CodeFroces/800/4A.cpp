#include <iostream>

using namespace std;

int main()
{
    int nWeight;
    cin >> nWeight;

    if (nWeight % 2 == 0 && nWeight != 2) cout << "YES";
    else cout << "NO";
}

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

string* codeGray(int n);

int main()
{
    int n;
    cin >> n;

    string* s = codeGray(n);
    for (int i = 0; i < pow(2, n); i++)
    {
        cout << s[i] << "\n";
    }
}

string* codeGray(int n)
{
    if (n == 1)
    {
        string* a = new string[2];
        a[0] = "0";
        a[1] = "1";
        return a;
    }

    string* cG1 = codeGray(n - 1);

    string* cG2 = new string[int(pow(2, n - 1))];
    for (int i = 0; i < pow(2, n - 1); i++) cG2[i] = cG1[int(pow(2, n - 1)) - 1 - i];
    

    for (int i = 0; i < pow(2, n - 1); i++) cG1[i] = "0" + cG1[i];
    for (int i = 0; i < pow(2, n - 1); i++) cG2[i] = "1" + cG2[i];
    

    string* cG = new string[int(pow(2, n))];
    for (int i = 0; i < int(ceil(pow(2, n - 1))); i++) cG[i] = cG1[i];
    for (int i = pow(2, n - 1); i < pow(2, n); i++) cG[i]=cG2[i - int(pow(2, n - 1))];
    

    return cG;
}

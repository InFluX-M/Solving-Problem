#include <iostream>

using namespace std;

//A. Red Versus Blue

#define ll long long int

int main()
{
    ll nTest;
    cin >> nTest;

    for (ll t = 1; t <= nTest; t++)
    {
        ll n, r, b;
        cin >> n >> r >> b;

        ll lMax = ceil(1.0 * r / (b + 1));
        ll nLMax = r % (b + 1);

        string mx1 = "";
        string mx2 = "";

        if (nLMax != 0)
        {
            for (int i = 0; i < lMax - 1; i++) mx1 += "R";
            mx2 = mx1 + "R";
        }
        else
        {
            for (int i = 0; i < lMax; i++) mx1 += "R";
            mx2 = mx1;
        }


        string aim = "";
        for (int i = 0; i < b + 1; i++)
        {
            if (i < nLMax)
            {
                if (i == b)
                    aim += mx2;
                else
                    aim += mx2 + "B";
            }
            else
            {
                if (i == b)
                    aim += mx1;
                else
                    aim += mx1 + "B";
            }
        
        }

        cout << aim + "\n";
    }

}

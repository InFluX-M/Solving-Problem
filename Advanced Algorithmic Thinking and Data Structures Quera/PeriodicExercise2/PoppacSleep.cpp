#include <iostream>

using namespace std;

int main()
{
    int a,b,x;
    
    cin>>a>>b>>x;
    
    int counter=0;
    
    
    for (int i=1; i<=a; i++)
    {
        if(a%i==0)
        {
            for (int j=1; j<=b; j++)
            {
                if(b%j==0)
                {
                    if (x>=i+j) counter++; 
                }
            }
        }
    }

    cout<<counter;
    
	return 0;
}

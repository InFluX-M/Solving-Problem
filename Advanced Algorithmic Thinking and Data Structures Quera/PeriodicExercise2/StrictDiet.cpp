#include <iostream>

using namespace std;

int main()
{
    char Item1,Item2,Item3,Item4,Item5;
    int R=0,Y=0,G=0;
    
    cin>>Item1>>Item2>>Item3>>Item4>>Item5;
    
    if(Item1 == 'R') R++;
    else if(Item1 == 'Y') Y++;
    else if(Item1 == 'G') G++;
    
    if(Item2 == 'R') R++;
    else if(Item2 == 'Y') Y++;
    else if(Item2 == 'G') G++;
    
    if(Item3 == 'R') R++;
    else if(Item3 == 'Y') Y++;
    else if(Item3 == 'G') G++;
    
    if(Item4 == 'R') R++;
    else if(Item4 == 'Y') Y++;
    else if(Item4 == 'G') G++;
    
    if(Item5 == 'R') R++;
    else if(Item5 == 'Y') Y++;
    else if(Item5 == 'G') G++;
    
    if(R>=3) cout<<"nakhor lite";
    else if(R>=2 && Y>=2)  cout<<"nakhor lite";
    else if(G == 0) cout<<"nakhor lite";
    else cout<< "rahat baash";
    
    
	return 0;
}

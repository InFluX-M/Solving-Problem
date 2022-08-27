#include <iostream>
using namespace std;

void hanoiTower(string from, string to, string help, int n);
int i = 0;
int main()
{
   int n;
   cin >> n;
   hanoiTower("A", "B", "C", n);
}

void hanoiTower(string from, string to, string help, int n)
{
   if (n == 0) return;
   
   hanoiTower(from, help, to, n - 1);
   cout << ++i << " " << from << " " << to << "\n";
   hanoiTower(help, to, from, n-1);

}
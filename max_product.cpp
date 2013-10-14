#include<iostream>
#include<cmath>
using namespace std;

double max_product(int n)
{
    if(n < 2)
        return n;
    int quotient = n / 3;
    int remainder = n % 3;
    
    if(remainder == 0)
        return pow(3.0, quotient);
    else if(remainder == 1)
        return 4 * pow(3.0, quotient-1);
    else
        return 2 * pow(3.0, quotient);
}

int main()
{
    int n = 7;
    
    cout << max_product(n) << endl;

    cin.get();
    return 0;
}

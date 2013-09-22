#include <iostream>
using namespace std;

/*
Problem Description:
    Determine whether an integer is a palindrome. Do this without extra space!
*/

bool isPalindromeNumber(int n)
{
     if (n < 0)
     {
        return false;
     }
     
     int x = n;
     int div = 1;
     while (x >= 10)
     {
         x /= 10;
         div *= 10;     
     }
     
     while (n >= 10)
     {
          int l = n / div;
          int r = n % 10;
          if (l != r)
          {
             return false;      
          }      
          n = (n % div) / 10;
          div /= 100;
     }
     return true;
}

int main()
{
    cout << isPalindromeNumber(5087806) << endl;
    
    cin.get();
    return 0;
}

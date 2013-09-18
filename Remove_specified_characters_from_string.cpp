#include <iostream>
using namespace std;

/*
Problem Description:

Delete "b" and "ac" from the string.
Requirement: One time traversal, no more space.
For example:
            "acbac'  ==> "";
            "aaac"   ==> "aa";
            "ababac" ==> "aa";
            "bbbbd"  ==> "d".
Further: How about "aaccac"?

*/

void remove_ac_and_b(char* str)
{
    int p = 0;
    int q = 0;
    int len = strlen(str);
    while (p < len)
    {
        if (str[p] == 'b')
        {
            p++;
        }
        else if ((str[p]== 'a') && (p+1 < len) && (str[p+1] == 'c'))
        {
            p += 2;
        }
        else if ((str[p]== 'c') && (q-1 >=0) && (str[q-1] == 'a'))
        {
            //This branch may not be necessary.
            p++;
            q--; 
        }
        else
        {
            str[q++] = str[p++];
        }
    }
    
    str[q] = '\0';
    
    cout << str << endl;
}

int main()
{
    char str[] = "aaccacd";
    
    remove_ac_and_b(str);
    
    cin.get();
    return 0;
}

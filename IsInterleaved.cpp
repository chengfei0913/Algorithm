#include <iostream>
using namespace std;

/*
Problem Description:
        For three given string:a, b and c. To decide whether c is interleave of 
        a and b, that is to say, c contains all the characters that in a and b, 
        and they have the same order. For example:
            a = "ef"    b = "gh"  c = "egfh"       return true
            a = "ef"    b = "gh"  c = "ehgf"       return false
*/

bool isInterleaved(char* st, char* la, char* lb) 
{
     while (*st != '\0') 
     {
           if (*la == *st) 
           {
                  la++;       
           }
           if (*lb == *st) 
           {
                  lb++;       
           }
           st++;
     }
     
     if ((*la == '\0') && (*lb == '\0')) 
     {
        return true;
     } 
     else 
     {
        return false;
     }
}

int main() 
{
    char st[] = "ehgf";
    char la[] = "ef";
    char lb[] = "gh";

    cout << isInterleaved(st, la, lb) << endl;
    
    cin.get();
    return 0;
}

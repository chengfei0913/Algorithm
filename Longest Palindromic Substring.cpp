#include <iostream>
using namespace std;

/*
Problem Description:
    Given a string S, find the longest palindromic substring in S.
*/
string longestPalindrome(string s)
{
    int len = s.length();
    if(len == 0)
        return "";
    int maxLen = 1;
    int centIdx = 0;
    int left, right;
    for(int i = 0; i < len; ++i)
    {   
        left = i;
        right = i;
        while((left >=0)&&(right < len)&&(s[left]==s[right]))
        {
            left--;
            right++;
        }
        if((right-left-1) > maxLen)
        {
            maxLen = right-left-1;
            centIdx = i;
        }
        
        left = i;
        right = i+1;
        while((left >=0)&&(right < len)&&(s[left]==s[right]))
        {
            left--;
            right++;
        }
        if((right-left-1) > maxLen)
        {
            maxLen = right-left-1;
            centIdx = i;
        }
    }
    
    int beginIdx = ((centIdx+1) / 2) - 1;
    return s.substr(beginIdx, maxLen);
}

int main()
{
    string s = "abcddcbc";
    string ps = longestPalindrome(s);
    cout << ps << endl;
    
    cin.get();
    return 0;
}

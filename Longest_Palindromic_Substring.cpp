#include<iostream>
using namespace std;

char* longest_palindromic_substring(char* s)
{
    if(s == NULL)
        return NULL;

    int len = strlen(s);
    if(len <= 1)
        return s;

    char* new_s = (char*)malloc((2*len+4)*sizeof(char));
    new_s[0] = '^';
    new_s[1] = '#';
    for(int i = 0; i < len; ++i)
    {
        new_s[2*i+2] = s[i];
        new_s[2*i+3] = '#';
    }
    new_s[2*len+2] = '$';
    new_s[2*len+3] = '\0';

    return new_s;
}

int main()
{
    char s[] = "abcddcbc";
    char* lps = longest_palindromic_substring(s);
    cout << lps << endl;

    cin.get();
    return 0;
}

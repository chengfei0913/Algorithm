#include <iostream>
using namespace std;

/*
Problem Description:

删除字符串中的“b”和“ac”，需要满足如下的条件：字符串只能遍历一次；不能够实用额外的空间。
例如：acbac ==> ""；aaac ==> aa；ababac ==> aa；bbbbd ==> d。
进一步思考：如何处理aaccac呢，需要做哪些改变呢？

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

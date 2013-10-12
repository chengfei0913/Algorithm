#include<iostream>
#include<vector>
using namespace std;

void split_string_to_intArray(string s, vector<int> &arr)
{
    int len = s.length();
    for(int i = 0; i < len; ++i)
    {
        int n = 0;
        while( (i < len) && (s[i] != '.') )
        {
            n = 10 * n + (s[i] - '0');
            ++i;
        }
        arr.push_back(n);
    }
}

bool vector_bigger(vector<int> &v1, vector<int> &v2)
{
    vector<int>::iterator iter1 = v1.begin();
    vector<int>::iterator iter2 = v2.begin();
    
    while((iter1 != v1.end()) && (iter2 != v2.end()))
    {
        if(*iter1 > *iter2)
            return true;
        else if(*iter1 < *iter2)
            return false;
        else
        {
            ++iter1;
            ++iter2;
        }
    }
    
    if(iter1 != v1.end())
        return true;
    else
        return false;
}

string latest_version_between_two(string s1, string s2)
{
    vector<int> v1;
    vector<int> v2;
    
    split_string_to_intArray(s1, v1);
    split_string_to_intArray(s2, v2);
    
    if(vector_bigger(v1, v2))
        return s1;
    else
        return s2;
}

void check_version_validation(string s)
{

}

string latest_version(vector<string>& versions)
{
    if(versions.empty())
        return "No versions need to be compared.";
    vector<string>::iterator iter = versions.begin();
    string latest_version = *iter;
    
    check_version_validation(latest_version);
    while(iter != versions.end())
    {
        string cur_version = *iter;
        check_version_validation(cur_version);
        latest_version = latest_version_between_two(latest_version, cur_version);
        ++iter;
    }
    
    return latest_version;
}


int main()
{
    vector<string> versions;
    
    versions.push_back("2.13.4");
    versions.push_back("5.01.4");
    versions.push_back("3.3.4");
    
    cout << latest_version(versions) << endl;

    cin.get();
    return 0;
}

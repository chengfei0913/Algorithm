#include<iostream>
#include<vector>
using namespace std;

int next_index(string s, int cur_idx)
{
    // separated by dot.
    
    int idx = cur_idx;
    int len = s.length();
    
    while((idx < len) && (s[idx] != '.'))
    {
        ++idx;
    }

    return ++idx;
}

int next_int(string s, int cur_idx, int next_idx)
{
    int num = 0;
    int len = s.length();
    for(int idx = cur_idx; (idx < len) && (idx < next_idx); ++idx)
        num = 10 * num + (s[idx] - '0');
        
    return num;
}

void check_version_validation(vector<string>& versions)
{
    vector<string>::iterator iter = versions.begin();
    for( ; iter != versions.end(); ++iter)
    {
    
    }
}

string latest_version(vector<string>& versions)
{
    check_version_validation(versions);
    int num = versions.size();
    int* pIndex = new int[num];
    int* iValue = new int[num];
    
    int max_len = 0;
    for(int i = 0; i < num; ++i)
    {
        pIndex[i] = 0;
        iValue[i] = 0;
        
        if(int(versions[i].length()) > max_len)
            max_len = versions[i].length();
    }
    
    int survivor = num;
    int max_times = max_len; // in case that two versions are both the latest.
    do
    {
        int max_value = 0;
        
        for(int i = 0; i < num; ++i)
        {
            if(pIndex[i] >= 0)
            {
                int next_idx = next_index(versions[i], pIndex[i]);
                iValue[i] = next_int(versions[i], pIndex[i], next_idx);
                pIndex[i] = next_idx;
                max_value = max_value > iValue[i] ? max_value : iValue[i];
            }
        }
        
        for(int j = 0; j < num; ++j)
        {
            if((pIndex[j] >= 0) && (iValue[j] < max_value))
            {
                pIndex[j] = -1;
                --survivor;
            }
        }
    --max_times;
    }while((survivor > 1) && (max_times > 0));
    
    string latest_version;
    for(int k = 0; k < num; ++k)
    {
        if(pIndex[k] >= 0)
        {
            latest_version = versions[k];
            break;
        }
    }
    
    delete[] pIndex;
    delete[] iValue;
    return latest_version;
}


int main()
{
    vector<string> versions;
    
    versions.push_back("2.13.14");
    versions.push_back("5.3.21");
    versions.push_back("3.14.9");
    versions.push_back("5.03.21");
    
    cout << latest_version(versions) << endl;

    cin.get();
    return 0;
}

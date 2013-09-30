#include<iostream>
using namespace std;

/*
    Problem Description: For two given strings A & B, judge whether A contains all the
        characters in the B. For example:
    A = abcde, B = ba, retrun true. Because ab is the permutation of B, and the substring of A.
*/
int cmp(const void* a, const void* b)
{
    return *(char*)a - *(char*)b;    
}

bool Is_Contained(char* A, char* B)
{
    bool res = false;
    int len_A = strlen(A);
    int len_B = strlen(B);
    
    if(len_A < len_B)
        return res;
    
    qsort(B, len_B, sizeof(char), cmp);
    char* T = (char*)malloc((len_B+1) * sizeof(char));
    for(int i = 0; i <= (len_A - len_B); ++i)
    {
        strncpy(T, A+i, len_B);
        T[len_B] = '\0';
        qsort(T, len_B, sizeof(char), cmp);
        if(strcmp(B, T) == 0)
        {
            res = true;
            break;            
        }
    }
    
    free(T);
    return res;
}

bool Is_Contained_Optimization(char* A, char* B)
{
    bool res = false;
    int  len_A = strlen(A);
    int  len_B = strlen(B);
    
    if(len_A < len_B)
        return res;
    
    qsort(B, len_B, sizeof(char), cmp);
    char* T = (char*)malloc((len_B+1) * sizeof(char));
    strncpy(T, A, len_B);
    T[len_B] = '\0';
    qsort(T, len_B, sizeof(char), cmp);
    if(strcmp(B, T) == 0)
        return true;
        
    for(int i = 1; i <= (len_A - len_B); ++i)
    {
        char ch = A[len_B + i - 1];
        for(int j = 0; j < len_B; ++j)
        {
            if((j < len_B-1) && (ch > T[j]))
                T[j] = T[j+1];
            else
            {
                T[j] = ch;
                break;
            }
        }
        if(strcmp(B, T) == 0)
            return true;
    }
    
    free(T);
    return res;
}

int main()
{
    char A[] = "abcde";
    char B[] = "ba";
    
    cout << Is_Contained_Optimization(A, B) << endl;

    cin.get();
    return 0;
}

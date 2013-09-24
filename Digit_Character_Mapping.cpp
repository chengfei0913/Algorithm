#include <iostream>
using namespace std;

void digit_to_character(char* s, char* new_s, int idx)
{
    if((s == NULL) || (*s == '\0'))
    {
        new_s[idx] = '\0';
        cout << new_s << endl;
        return;
    }

    new_s[idx++] = (*s - '1' + 'a');
    digit_to_character(s+1, new_s, idx--);

    if(*(s+1) == '\0')
    {
        return;
    }
    int first_two = (*s - '0') * 10 + (*(s+1) - '0');
    if(first_two <= 26)
    {
        new_s[idx++] = (first_two - 1 + 'a');
        digit_to_character(s+2, new_s, idx--);
    }
}


void digit_character_mapping(char* s)
{
    int len = strlen(s);
    for(int i = 0; i < len; ++i)
    {
        if( (s[i]<'1') || (s[i] > '9') )
        {
            cout << "Invalid input!" << endl;
            return;
        }
    }

    char* new_s = (char*)malloc(len*sizeof(char) + 1);
    digit_to_character(s, new_s, 0);
    free(new_s);
}

int main()
{
    char s[] = "12259";
    digit_character_mapping(s);

    cin.get();
    return 0;
}

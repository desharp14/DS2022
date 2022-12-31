#include <iostream>
#include <string>
#include <cmath>
#include "caculator.h"

using namespace std;

string calculate(string & s)
{
    string *num = new string[s.size()];
    string *sign = new string[s.size()];
    int j = 0;
    ExpressionTree T;
    for(int i = 0; i < s.size(); ++i)
    {
        string t = "";
        if(s[i] == '(')
        {
            int p = 1;
            int q = i;

            while(p != 0 && q < s.size())
            {
                q++;
                if(s[q] == '(')
                {
                    p = p+1;
                }
                if(s[q] == ')')
                {
                    p = p-1;
                }
            }
            for(int k = i+1; k < q; ++k)
            {
                t.push_back(s[k]);
            }

            num[j] = calculate(t);
            i = q;
        }
        else if(s[i] == '-' && character(s[i-1]) != 0 && s[i-1] != ')')
        {
            num[j] = '-';
        }
        else if(s[i] >= '0' && s[i] <= '9' || s[i] == '.')
        {
            num[j] = num[j] + s[i];
        }
        else if(character(s[i]) == 1)
        {
            sign[j] = s[i];
            j++;
        }
    }

    for(int k = 0; k < j; ++k)
    {
        T.insert(num[k]);
        T.insert(sign[k]);
    }
    T.insert(num[j]);

    return T.calculate();
}

int main()
{
    const int size = 13;
    int a = 1;
    for(int x = 0; x < size; ++x)
    {
        string s1;
        cout << "Input" << a <<": ";
        getline(cin, s1);
        string s;

        for(int i = 0; i < s1.size(); ++i)
        {
            if(s1[i] == ' ')
                ;
            else if(s1[i] == '(' && (s1[i-1] == ')' || character(s1[i-1]) == 0))
            {
                s.push_back('*');
                s.push_back(s1[i]);
                ++i;
                s.push_back(s1[i]);
            }

            else
                s.push_back(s1[i]);
        }

        if(check(s) && calculate(s) != " ")
        {
            cout << "Output" << a << ": " << s1 << " = " << strtd(calculate(s)) << endl;
        }
      ++a;
    }
    return 0;
}



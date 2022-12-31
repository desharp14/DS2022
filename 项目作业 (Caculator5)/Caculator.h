#ifndef CACULATOR_H
#define CACULATOR_H

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

//string to double
double strtd(string& str) 
{
    istringstream iss(str);
    double num;
    iss >> num;
    return num;
}

double strtd(string&& str)
{
    istringstream iss(str);
    double num;
    iss >> num;
    return num;
}

//double to string
string dts(double num)
{
    stringstream ss;
    string str;
    ss << num;
    ss >> str;
    return str;
}

int character(char & s)
{
    if(s >= '0' && s <= '9')
    {
        return 0;
    }
    else if(s == '+' || s == '-' || s == '*' || s == '/' || s == '^')
    {
        return 1;
    }
    else if(s == '(' || s == ')' || s == '.')
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

bool check(string & s)
{
    int x = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(character(s[i]) != 3)
        {
            if(character(s[i]) == 1 && ((i == 0 && s[i] != '-') || i == s.size() || (character(s[i+1]) != 0 && s[i+1] != '(') || (character(s[i-1]) != 0 && s[i-1] != ')' && s[i] != '-')))
            {
                cerr << "Illegal operators!" << endl;
                return false;
            }
            
            else if(s[i] == '.' && (i == 0 || i == s.size() || character(s[i+1]) != 0 || character(s[i-1]) != 0))
            {
                cerr << "Incorrect decimal points!" << endl;
                return false;
            }

            else if(s[i] == '/' && s[i+1] == '0')
            {
                cerr << "The divisor is 0!" << endl;
                return false;
            }

            else if(s[i] == '(')
            {
                if(s[i+1] != ')' )
                {
                    x = x+1;
                }
                else
                {
                    cerr << "Empty parentheses!" << endl;
                    return false;
                }
            }

            else if(s[i] == ')' )
            {
                x = x-1;
            }
        }

        else
        {
            cerr << "Illegal characters!" << endl;
            return false;
        }

        if (x < 0)
        {
            cerr << "Incorrect parentheses position!" << endl;
            return false;
        }
    }

    if( x != 0)
    {
        cerr << "Parentheses mismatch!" << endl;
        return false;
    }
    return true;
}

class ExpressionTree
{
public:
    ExpressionTree() : root{nullptr}
    {}

    void makeEmpty()
    {
        makeEmpty(root);
    }

    ~ExpressionTree()
    {
        makeEmpty();
    }

    void insert(const string & s)
    {
        insert(s, root);
    }

    string calculate()
    {
        calculate(root);
        return root -> element;
    }

private:
    struct ExpressionNode
    {
        string element;
        ExpressionNode *left;
        ExpressionNode *right;

        ExpressionNode(const string & theElement, ExpressionNode *lt, ExpressionNode *rt) : element{theElement}, left{lt}, right{rt} {}
        ExpressionNode(string && theElement, ExpressionNode *lt, ExpressionNode *rt) : element{move(theElement)}, left{lt}, right{rt} {}
    };

    ExpressionNode *root;

    void insert(const string & s, ExpressionNode *&t)
    {
        if(t == nullptr)
            t = new ExpressionNode{s, nullptr, nullptr};
        else if(priority(s) <= priority(t -> element) && t->right != nullptr && (priority(s) != 2 ||  priority(t -> element) != 2))
        {
            insert(s, t -> left);
            t -> left -> left = t -> left -> right;
            t -> left -> right = t;
            t = t -> left;
            t -> right -> left = t -> left;
            t -> left = nullptr;
        }

        else if(priority(s) <= priority(t -> element) && t -> right == nullptr && (priority(s) != 2 || priority(t -> element) != 2))
        {
            insert(s, t -> right);
            t -> right -> right = t;
            t = t -> right;
            t -> right -> right = nullptr;
        }

        else if(priority(s) == 2 && priority(t -> element) == 2)
        {
            insert(s, t -> left);
        }

        else if(priority(s) > priority(t -> element) && t -> right != nullptr)
        {
            insert(s, t -> left);
        }

        else if(priority(s) > priority(t -> element) && t -> right == nullptr)
        {
            insert(s, t -> right);
        }
    }

    int priority(string s)
    {
        if(s == "+" || s == "-")
        {
            return 0;
        }
        else if(s == "*" || s == "/") 
        {
            return 1;
        }
        else if(s == "^") 
        {
            return 2;
        }
        else 
        {
            return 3;
        }
    }

    void calculate(ExpressionNode *t)
    {
        if(character((t -> element)[0]) == 1 && t -> element.size() == 1 && !(t -> element == "/" && strtd(t -> left -> element) == 0))
        {
            calculate(t -> left);
            calculate(t -> right);
            t -> element = getvalue(t);
        }
        else if(t -> element == "/" && strtd(t -> left -> element) == 0)
        {
            cerr << "The divisor is 0!" << endl;
            t -> element = " ";
        }   
    }

    string getvalue(ExpressionNode *&t)
    {
        if(t -> left -> element == " " || t -> right -> element == " ")
        {
            return " ";
        }
        else if(t -> element == "+")
        {
            return dts(strtd(t -> right -> element) + strtd(t -> left -> element));
        }
        else if(t -> element == "-")
        {
            return dts(strtd(t -> right -> element) - strtd(t -> left -> element));
        }
        else if(t -> element == "*")
        {
            return dts(strtd(t -> right -> element) * strtd(t -> left -> element));
        }
        else if(t -> element == "/")
        {
            return dts(strtd(t -> right -> element) / strtd(t -> left -> element));
        }
        else if(t -> element == "^")
        {
            return dts(pow(strtd(t -> right -> element), strtd(t -> left -> element)));
        }
        else
            return " ";
    }

    void makeEmpty(ExpressionNode *&t)
    {
        if(t != nullptr)
        {
            makeEmpty(t -> left);
            makeEmpty(t -> right);
            delete t;
        }
        t = nullptr;
    }  
}; 

#endif
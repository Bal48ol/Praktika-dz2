#include <iostream>
#include <vector>
#include <string>
#include "Header1.h"

int pos = 0;
std::string exemp = "11+0)*0";


bool S()
{
    return(T() && S_());
}

bool S_()
{
    if (pos == exemp.length())
    {
        return true;
    }
    if (exemp[pos] == '+')
    {
        pos++;
        return(T() && S_());
    }
    return true;
}

bool T()
{
    return(F() && T_());
}

bool T_()
{
    if (pos == exemp.length())
    {
        return true;
    }
    if ((exemp[pos] == '(') || (exemp[pos] == '0') || (exemp[pos] == '1'))
    {
        return (F() && T_());
    }
    return true;
}

bool F()
{
    if (pos == exemp.length())
    {
        return false;
    }
    if (exemp[pos] == '(')
    {
        pos++;
        if (!S())
        {
            return false;
        }
        if (exemp[pos] == ')')
        {
            pos++;
            return F_();
        }
        return false;
    }
    if (exemp[pos] == '0' || exemp[pos] == '1')
    {
        pos++;
        return F_();
    }
    return false;
}

bool F_()
{
    if (pos == exemp.length())
    {
        return true;
    }
    if (exemp[pos] == '*')
    {
        pos++;
        return true;
    }
    return true;
}

int main()
{
    std::cout << ((S()) && (pos == exemp.length()));
}
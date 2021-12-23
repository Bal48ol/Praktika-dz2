#include <iostream>
#include <vector>
#include <string>
#include "Header1.h"

int pos2 = 0;
std::string exemp2 = "(1+0)*0";

bool S()
{
    return(T2() && S_());
}

bool S_()
{
    if (pos2 == exemp2.length())
    {
        return true;
    }
    if (exemp2[pos2] == '+')
    {
        pos2++;
        return(T2() && S_());
    }
    return true;
}

bool T2()
{
    return(F2() && T_2());
}

bool T_2()
{
    if (pos2 == exemp2.length())
    {
        return true;
    }
    if ((exemp2[pos2] == '(') || (exemp2[pos2] == '0') || (exemp2[pos2] == '1'))
    {
        return (F2() && T_2());
    }
    return true;
}

bool F2()
{
    if (pos2 == exemp2.length())
    {
        return false;
    }
    if (exemp2[pos2] == '(')
    {
        pos2++;
        if (!S())
        {
            return false;
        }
        if (exemp2[pos2] == ')')
        {
            pos2++;
            return F_2();
        }
        return false;
    }
    if (exemp2[pos2] == '0' || exemp2[pos2] == '1')
    {
        pos2++;
        return F_2();
    }
    return false;
}

bool F_2()
{
    if (pos2 == exemp2.length())
    {
        return true;
    }
    if (exemp2[pos2] == '*')
    {
        pos2++;
        return true;
    }
    return true;
}

int main()
{
    std::cout << ((S() && pos2 == exemp2.length()));
    return 0;
}
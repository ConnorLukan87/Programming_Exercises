#include <iostream>
#include <cmath>

typedef long long unsigned int ll;

ll gcd(ll n, ll d)
{
    return n % d == 0 ? d : gcd(d, n % d);
}

ll str_to_ll(const std::string& s)
{
    ll rv = 0;
    for (int i = 0 ; i < s.size(); i++)
    {
        rv *= 10;
        rv += s[i]-48;
    }
    return rv;
}

int main()
{
    std::string num;
    int repeating;
    std::cin >> num >> repeating;

    // find the amount of digits to the right of the decimal;
    int decimal_idx = 0;
    for (int i = 0 ; i < num.size(); i++)
    {
        if (num[i] == '.')
        {
            decimal_idx = i;
            break;
        }
    }

    std::string repeating_part = "";
    int i;
    for (i = num.size()-1; i > num.size()-1-repeating; i--)
    {
        repeating_part = num[i] + repeating_part;
    }

    // get non repeating part
    ll denom = 1;
    ll numerator = 0;
    bool dot_found = false;
    for (int j = 0; j <= i ; j++)
    {
        if (num[j] == '.')
        {
            dot_found = true;
            continue;
        }

        numerator *= 10;
        numerator += (num[j]-48);
        if (dot_found)
        {
            denom *= 10;
        }
    }

    ll repeat_part = str_to_ll(repeating_part);
    ll nines = (ll)(std::pow(10, repeating) - 1);

    numerator *= nines;
    numerator += repeat_part;
    denom *= nines;

    ll d = numerator > denom ? gcd(numerator, denom) : gcd(denom, numerator);
    numerator /= d;
    denom /= d;
    std::cout << numerator << "/" << denom << std::endl;
}

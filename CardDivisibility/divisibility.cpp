#include <iostream>

typedef long long unsigned int ll;

ll sum_of_digits(ll& num) {
    ll rv = 0;
    ll temp = num;
    while (temp > 0) {
        rv += temp % 10;
        temp /= 10;
    }
    return rv;
}

ll remainder_div_9(ll num) {
   // std::cout << "here\n";
    return num < 9 ? num : remainder_div_9(sum_of_digits(num));
}

ll triangle(ll i) {
    return (i*(i+1))/ 2;
}

int main()
{
    ll L, R;
    std::cin >> L >> R;
    ll sum = 0;
    // a = bq + r

    if (L == R) {
        std::cout << L % 9;
        return 0;
    }

    ll r = R - (R%9);
    ll l = (L-1)/9;
    l = l*9 + 9;
    if ((R-L < 9 && ((L%9) < (R%9))) || l==r)
    {
        for (ll i = L; i <= R; i++) {
            sum += i % 9;
        }
        std::cout << sum % 9 << std::endl;
        return 0;
    }
    else {
        sum = 0;
        for (ll i = L; i < l; i++) {
            sum += i % 9;
        }
        for (ll i = r+1; i <= R;i++ ) {
            sum += i % 9;
        }

        std::cout << sum % 9 << std::endl;
    }

    return 0;
}

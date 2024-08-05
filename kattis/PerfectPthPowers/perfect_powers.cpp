#include <iostream>
#include <cmath>

int main()
{
  long long x;
  while (true)
  {
    std::cin >> x;
    if (x==0) break;
    double base; bool good = false;
    for (long long power=31;!good && power>0;power--)
    {
      base = std::pow(std::abs(x),1.00/power);
      if (base-std::floor(base)<0.001)
      {
        if (std::pow(std::floor(base),power)==std::abs(x) && (x>0 || power%2==1))
        {
          std::cout << power << std::endl;
          good = true;
        }
      }
      else if (std::ceil(base)-base < 0.001)
      {
        if (std::pow(std::ceil(base),power)==std::abs(x) && (x>0 || power%2==1))
        {
          std::cout << power << std::endl;
          good = true;
        }
      }
    }
   
  }
  return 0;
}

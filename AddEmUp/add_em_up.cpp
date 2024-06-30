#include <iostream>
#include <vector>

const int N = 200000000;
const int flipped[10] = {0, 1, 2, N, N, 5, 9, N, 8, 6};

int get_flipped(int num)
{
  int ans = 0;
  while (num > 0)
  {
    ans = ans*10 + flipped[num % 10];
    num /= 10;
  }
  return ans;
}

int main()
{
  int c, sum;
  std::cin >> c >> sum;
  std::vector<std::pair<int,int>> cards(c);

  for (int i = 0; i < c ; i++)
  {
    std::cin >> cards[i].first;
    cards[i].second = get_flipped(cards[i].first);
  }
  bool found = false;

  for (int i=  0; i < c-1 && !found; i++)
  {
    for (int j = i + 1; j < c && !found; j++)
    {
      if (cards[i].first + cards[j].second == sum)
      {
        found = true;
      }
      else if (cards[i].first + cards[j].first == sum)
      {
        found = true;
      }
      else if (cards[i].second + cards[j].first == sum)
      {
        found = true;
      }
      else if (cards[i].second + cards[j].second == sum)
      {
        found = true;
      }
    }
  }
  if (found)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
}
  

  

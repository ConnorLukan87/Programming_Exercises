#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

int main()
{
    int T;
    std::cin >> T;
    for (int i= 0 ; i < T; i++)
    {
        int n;
        std::cin >> n; // num snowflakes
        int current_length = 0, best_length = 0;
        int current_begin = 0;
        std::unordered_set<int> current_package;
        std::unordered_map<int, int> snowflake_to_place;
        std::vector<int> shapes(n);
        for (int j = 0 ; j < n; j++)
        {
            std::cin >> shapes[j];
        }
        for (int j = 0; j < n ; j++)
        {
            int shape = shapes[j];
            // if it's not in the current package
            if (current_package.find(shape) == current_package.end())
            {
                // add it
                current_package.insert(shape);
                snowflake_to_place[shape] = j;
                if (j + 1 - current_begin > best_length)
                {
                    best_length = j + 1 - current_begin;
                }
            }
            else
            {
                // carry out the case where the sequence starts after the last occurence of the snowflake
                int next_to_begin = snowflake_to_place[shape] + 1;
                for (int k = current_begin; k < next_to_begin ; k++)
                {
                    current_package.erase(shapes[k]);
                }
                current_package.insert(shape);
                current_begin = next_to_begin;
                snowflake_to_place[shape] = j;
            }
            
        }
        std::cout << best_length << std::endl;
    }

}

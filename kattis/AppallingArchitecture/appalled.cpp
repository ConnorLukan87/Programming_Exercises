#include <iostream>
#include <vector>

int main()
{

    int total_building_units = 0;
    int h, w;
    std::cin >> h >> w;
    std::vector<std::vector<char>> grid(h, std::vector<char>(w));
    float avg = 0.0;
    for (int i = 0 ; i < h ; i++) // for each row
    {
        for (int j = 0 ; j < w; j++) // for each column
        {
            std::cin >> grid[i][j];
            if (grid[i][j] != '.')
            {
                total_building_units++;
                avg += ((float)j) + .5;
            }
        }
    }
    float center_gravity = ((float)avg)/((float)total_building_units);

    int rightmost_col, leftmost_col;

    // find the leftmost lower part of the grid
    for (leftmost_col = 0; leftmost_col < w; leftmost_col++)
    {
        if (grid[h-1][leftmost_col] != '.')
        {
            break;
        }
    }
    if (center_gravity < (float)leftmost_col)
    {
        std::cout << "left" << std::endl;
    }

    // find the rightmost low part of the gird
    for (rightmost_col = w-1; rightmost_col >= 0; rightmost_col--)
    {
        if (grid[h-1][rightmost_col] != '.')
        {
            break;
        }
    }

    if (center_gravity > ((float)rightmost_col + .9999999999))
    {
        std::cout << "right" << std::endl;
    }

    if (center_gravity <= ((float)rightmost_col + .9999999999) && center_gravity >= (float)leftmost_col)
    {
        std::cout << "balanced" << std::endl;
    }

  //  std::cout << leftmost_col << " ";
   // std::cout << center_gravity << " ";
   // std::cout << rightmost_col << " ";

}

// shoutout https://www.reddit.com/r/adventofcode/comments/1h689qf/2024_day_4_solutions/m0brv3m/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <regex>
int main()
{
    std::ifstream file("input.txt");
    std::vector<std::string> grid;
    std::string line;
    while (std::getline(file, line))
    {
        grid.push_back(line);
    }
    int total = 0;
    for (int row = 1; row < grid.size() - 1; row++)
    {
        for (int col = 1; col < grid[row].length() - 1; col++)
        {
            std::stringstream left, right;
            left << grid[row - 1][col - 1] << grid[row][col] << grid[row + 1][col + 1];
            right << grid[row + 1][col - 1] << grid[row][col] << grid[row - 1][col + 1];

            if ((left.str() == "MAS" || left.str() == "SAM") &&
                (right.str() == "MAS" || right.str() == "SAM"))
            {
                total++;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Total: " << total << std::endl;
    return 0;
}
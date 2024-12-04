#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

int main()
{
    std::ifstream file("test.txt");
    std::vector<std::vector<char>> grid;
    std::string line;
    while (std::getline(file, line))
    {
        std::vector<char> row;
        for (char c : line)
        {
            row.push_back(c);
        }
        grid.push_back(row);
    }
    int total = 0;
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid.at(row).size(); col++)
        {
            if (grid.at(row).at(col) == 'A')
            {
                // check up left for an 'M'
                if (
                    // check for out of range

                    grid.at(row - 1).at(col - 1) == 'M' &&
                    grid.at(row - 1).at(col + 1) == 'M' &&
                    grid.at(row + 1).at(col + 1) == 'S' &&
                    grid.at(row + 1).at(col - 1) == 'S')
                {
                    total++;
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Total: " << total << std::endl;
    return 0;
}
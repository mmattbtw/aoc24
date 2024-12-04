#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

int main()
{
    std::ifstream file("test.txt");
    // std::ifstream file("input.txt");
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
            if (grid.at(row).at(col) == 'X')
            {
                // check for each one to not go out of range
                // something might not be able to go +3 row but could got +3 col, so check for each one

                if (grid.at(row - 1).at(col) == 'M' && grid.at(row - 2).at(col) == 'A' && grid.at(row - 3).at(col) == 'S')
                {
                    total++;
                }
                if (
                    grid.at(row + 1).at(col) == 'M' && grid.at(row + 2).at(col) == 'A' && grid.at(row + 3).at(col) == 'S')
                {
                    total++;
                }
                if (grid.at(row).at(col + 1) == 'M' && grid.at(row).at(col + 2) == 'A' && grid.at(row).at(col + 3) == 'S')
                {
                    total++;
                }
                if (grid.at(row).at(col - 1) == 'M' && grid.at(row).at(col - 2) == 'A' && grid.at(row).at(col - 3) == 'S')
                {
                    total++;
                }
                if (grid.at(row + 1).at(col + 1) == 'M' && grid.at(row + 2).at(col + 2) == 'A' && grid.at(row + 3).at(col + 3) == 'S')
                {
                    total++;
                }
                if (grid.at(row - 1).at(col + 1) == 'M' && grid.at(row - 2).at(col + 2) == 'A' && grid.at(row - 3).at(col + 3) == 'S')
                {
                    total++;
                }
                if (grid.at(row - 1).at(col - 1) == 'M' && grid.at(row - 2).at(col - 2) == 'A' && grid.at(row - 3).at(col - 3) == 'S')
                {
                    total++;
                }
                if (grid.at(row + 1).at(col - 1) == 'M' && grid.at(row + 2).at(col - 2) == 'A' && grid.at(row + 3).at(col - 3) == 'S')
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

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main()
{

    std::ifstream file;
    file.open("input.txt");

    std::string line;

    std::vector<std::vector<int>> number_groups;
    while (std::getline(file, line))
    {
        // Create a vector to store the numbers in the current line
        std::vector<int> numbers;
        // iterate over each number in the line
        // e.g. "10 20 30" -> 10, 20, 30
        int number;

        std::stringstream ss(line);
        while (ss >> number)
        {
            numbers.push_back(number);
        }
        number_groups.push_back(numbers);
    }

    int safe = 0;
    for (int i = 0; i < number_groups.size(); i++)
    {
        std::cout << "Group " << i << ": ";
        for (int j = 0; j < number_groups[i].size(); j++)
        {
            std::cout << number_groups[i][j] << " ";
        }
        std::cout << std::endl;

        bool safee = true; // Start by assuming the group is safe
        bool increasing = false, decreasing = false;
        //    safe if, all numbers are increasing or decreasing
        // any two adjacent numbers differ at least by one and at most by 3

        for (int j = 0; j < number_groups[i].size() - 1; j++)
        {
            int diff = number_groups[i][j + 1] - number_groups[i][j];

            // Check if difference is within the allowed range
            if (diff < -3 || diff > 3 || diff == 0)
            {

                safee = false;
                break;
            }

            // Determine if the sequence is increasing or decreasing
            if (diff > 0)
            {
                increasing = true;
            }
            else if (diff < 0)
            {
                decreasing = true;
            }

            // If the sequence is both increasing and decreasing, it's not monotonic
            if (increasing && decreasing)
            {
                safee = false;
                break;
            }
        }
        if (safee)
        {
            safe++;
        }
    }

    std::cout << "Safe: " << safe << std::endl;

    return 0;
}
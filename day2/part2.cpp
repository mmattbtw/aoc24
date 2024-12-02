#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

bool check_valid(std::vector<int> numbers);

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

        // Step 1: Check if the group is valid as-is
        if (check_valid(number_groups[i]))
        {
            std::cout << "Safe (no removal needed)" << std::endl;
            safe++;
            continue;
        }

        // Step 2: Check all subgroups
        bool group_is_safe = false;
        for (int k = 0; k < number_groups[i].size(); k++)
        {
            std::vector<int> temp_group = number_groups[i];
            temp_group.erase(temp_group.begin() + k); // Remove the k-th number

            if (check_valid(temp_group))
            {
                group_is_safe = true;
                break; // No need to check further, the group is safe
            }
        }

        // Step 3: Determine if the group is safe or unsafe
        if (group_is_safe)
        {
            std::cout << "Safe (valid after removing one number)" << std::endl;
            safe++;
        }
        else
        {
            std::cout << "Unsafe" << std::endl;
        }
    }

    std::cout << "Safe: " << safe << std::endl;

    return 0;
}

bool check_valid(std::vector<int> numbers)
{
    bool safee = true; // Start by assuming the group is safe
    bool increasing = false, decreasing = false;
    for (int j = 0; j < numbers.size() - 1; j++)
    {
        int diff = numbers[j + 1] - numbers[j];

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
    return safee;
}
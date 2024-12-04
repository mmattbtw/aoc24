#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

int main()
{
    // std::ifstream file("test.txt");
    std::ifstream file("input.txt");

    std::string line;
    std::vector<std::string> lines;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }
    file.close();

    std::vector<std::pair<int, int>> instructions; // Store pairs of x and y
    int total = 0;

    for (const auto &line : lines)
    {
        // Regex to match mul(x,y)
        std::regex pattern(R"(mul\((\d+),(\d+)\))");
        std::smatch match;

        // Search the line for all occurrences of the pattern
        auto search_start = line.cbegin();
        while (std::regex_search(search_start, line.cend(), match, pattern))
        {
            int x = std::stoi(match[1].str());
            int y = std::stoi(match[2].str());
            instructions.emplace_back(x, y);
            total += x * y;
            search_start = match.suffix().first; // Continue searching after this match
        }
    }

    // Output the total
    std::cout << "Total: " << total << std::endl;

    return 0;
}

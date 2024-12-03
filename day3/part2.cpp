#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

int main()
{
    std::ifstream file("test.txt");
    // std::ifstream file("input.txt");

    std::string line;

    int total = 0;
    bool please = true;

    std::regex mulPattern(R"(mul\((\d+),(\d+)\))");      // Matches valid mul(x,y) only
    std::regex togglePattern(R"((do\(\))|(don't\(\)))"); // Matches "do()" or "don't()"

    while (std::getline(file, line)) // Process line by line
    {
        size_t pos = 0;
        while (pos < line.size())
        {
            std::smatch match;

            // Create a substring starting from the current position
            std::string subline = line.substr(pos);

            // Search for toggle instructions first
            if (std::regex_search(subline, match, togglePattern))
            {
                std::string toggle = match.str();
                if (toggle == "do()")
                {
                    please = true;
                }
                else if (toggle == "don't()")
                {
                    please = false;
                }
                pos += match.position() + match.length();
            }
            // Then search for valid mul(x,y)
            else if (std::regex_search(subline, match, mulPattern))
            {
                if (please)
                {
                    int x = std::stoi(match[1].str());
                    int y = std::stoi(match[2].str());
                    total += x * y;
                }
                pos += match.position() + match.length();
            }
            else
            {
                break; // No more matches
            }
        }
    }

    file.close();
    // Output the total
    std::cout << "Total: " << total << std::endl;

    return 0;
}

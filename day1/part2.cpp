#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int main()
{
    std::ifstream file("input.txt");
    if (!file)
    {
        std::cerr << "Error: Could not open input file." << std::endl;
        return 1;
    }

    std::vector<int> left_side;
    std::vector<int> right_side;

    int left, right;
    while (file >> left >> right)
    {
        left_side.push_back(left);
        right_side.push_back(right);
    }

    file.close();

    int similar = 0;

    for (int i = 0; i < left_side.size(); i++)
    {
        int left = left_side.at(i);

        int times_appeared = 0;
        for (int i = 0; i < right_side.size(); i++)
        {
            int right = right_side.at(i);
            if (left == right)
            {
                times_appeared++;
            }
        }
        similar += left * times_appeared;
    }
    std::cout << "Similarity: " << similar << std::endl;
    return 0;
}

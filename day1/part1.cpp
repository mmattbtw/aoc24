#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <cmath>

// Helper function to sort a queue into a stack (ascending order)
std::stack<int> sortQueueToStack(std::queue<int> &inputQueue)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // Transfer all elements from queue to priority queue (min-heap)
    while (!inputQueue.empty())
    {
        minHeap.push(inputQueue.front());
        inputQueue.pop();
    }

    // Transfer sorted elements from min-heap to stack
    std::stack<int> sortedStack;
    while (!minHeap.empty())
    {
        sortedStack.push(minHeap.top());
        minHeap.pop();
    }

    return sortedStack;
}

int main()
{
    std::ifstream file("input.txt");
    if (!file)
    {
        std::cerr << "Error: Could not open input file." << std::endl;
        return 1;
    }

    std::queue<int> left_side;
    std::queue<int> right_side;

    int left, right;
    while (file >> left >> right)
    {
        left_side.push(left);
        right_side.push(right);
    }

    file.close();

    // Sort both queues into stacks
    std::stack<int> left_sorted = sortQueueToStack(left_side);
    std::stack<int> right_sorted = sortQueueToStack(right_side);

    // Calculate total difference
    int total = 0;
    while (!left_sorted.empty() && !right_sorted.empty())
    {
        std::cout << left_sorted.top() << " - " << right_sorted.top() << std::endl;
        total += std::abs(left_sorted.top() - right_sorted.top());
        left_sorted.pop();
        right_sorted.pop();
    }

    std::cout << "Total: " << total << std::endl;
    return 0;
}

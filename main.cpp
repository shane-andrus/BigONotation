#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random> 

// Timing function
template <typename Func, typename... Args>
double timeFunction(Func func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    func(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}

// O(1) - Constant Time: Accessing an element in a vector by index
int getFirstElement(const std::vector<int>& v) {
    return 0;
}

// O(log n) - Logarithmic Time: Binary Search
bool binarySearch(const std::vector<int>& v, int target) {
    return false;
}

// O(n) - Linear Time: Finding the maximum element
int findMax(const std::vector<int>& v) {
    return 0;
}

// O(n log n) - Quasi-linear Time: Merge Sort
void mergeSort(std::vector<int>& v) {

}

// O(n^2) - Quadratic Time: Bubble Sort
void bubbleSort(std::vector<int>& v) {

}

// O(2^n) - Exponential Time: Fibonacci using Recursion
int fibonacci(int n) {
    return 0;
}

// O(n!) - Factorial Time: Generating all permutations of a vector
void generatePermutations(std::vector<int>& v, int l, int r) {

}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

    std::vector<int> v(100000);
    for (int& num : v) {
        num = dist(gen); // Random numbers in the full integer range
    }

    std::cout << v.at(0) << std::endl;
    std::cout << v.at(100) << std::endl;
    std::cout << v.at(1000) << std::endl;
    std::cout << v.at(v.size() - 1) << std::endl << std::endl << std::endl;

    // std::cout << "O(1): First Element = " << timeFunction(getFirstElement, v)<< " ms" << std::endl;

    // std::cout << "O(log n): Binary Search time: " << timeFunction(binarySearch, v, 5) << " ms" << std::endl;

    // std::cout << "O(n): Max Element time: " << timeFunction(findMax, v) << " ms" << std::endl;

    // std::cout << "O(n log n): Merge Sorting time: " << timeFunction(mergeSort, v) << " ms" << std::endl;

    // std::cout << "O(n^2): Bubble Sorting time: " << timeFunction(bubbleSort, v) << " ms" << std::endl;
    
    // std::cout << "O(2^n): Fibonacci(5) time: " << timeFunction(fibonacci, 5) << " ms" << std::endl;
    
    // std::cout << "O(n!): Generating Permutations (first 6 elements) time: " << timeFunction(generatePermutations, v, 0, 5) << " ms" << std::endl;
    
    return 0;
}
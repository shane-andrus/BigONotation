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
    return v.at(0);
}

// O(log n) - Logarithmic Time: Binary Search
int binarySearch(const std::vector<int>& v, int target) {
    int low = 0;
    int high = v.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v.at(mid) == target) {
            return mid;
        }
        if (v.at(mid) < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

// O(n) - Linear Time: Finding the maximum element
int findMax(const std::vector<int>& v) {
    int max = v.at(0);
    for (int num : v) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

// Helper function to merge two halves
void merge(std::vector<int>& v, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = v[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = v[mid + 1 + j];

    // Merge the temporary arrays back into v[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            ++i;
        }
        else {
            v[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        v[k] = L[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        v[k] = R[j];
        ++j;
        ++k;
    }
}

// Main function that sorts v[left..right] using merge()
void mergeSort(std::vector<int>& v, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // start of log n

        // Sort first and second halves
        mergeSort(v, left, mid); //log n
        mergeSort(v, mid + 1, right); //log n
        //                              2 log n

        // Merge the sorted halves
        merge(v, left, mid, right); // n
        //                              n * 2*log n
        //                              2n * log n
        //                              n * log n
    }
}

// O(n log n) - Quasi-linear Time: Merge Sort
void mergeSortSimplified(std::vector<int>& v) {
    mergeSort(v, 0, v.size() - 1);
}

// O(n^2) - Quadratic Time: Bubble Sort
void bubbleSort(std::vector<int>& v) {
    bool swapped;
    for (int outer = 0; outer < v.size() - 1; ++outer) { // n - 1
        swapped = false;
        for (int inner = 0; inner < v.size() - outer - 1; ++inner) {
            if (v.at(inner) > v.at(inner + 1)) {
                std::swap(v[inner], v[inner + 1]);
                swapped = true;
            }
        } // n -2
        // (n)(n) = n^2
        if (!swapped) {
            break;
        }
    }
}

// O(2^n) - Exponential Time: Fibonacci using Recursion
int fibonacci(int max) {
    //base case 
    if (max <= 1) return max;
    //recursive case
    return fibonacci(max -1) + fibonacci(max - 2);
}

// O(n!) - Factorial Time: Generating all permutations of a vector
void generatePermutations(std::vector<int>& v, int l, int r, std::vector<std::vector<int>> & results) {
    // Base case: l == r, we have a permutation
    if (l == r) {
        results.push_back(v);
        return;
    }
    for (int i = l; i <= r; ++i) {
        std::swap(v[l], v[i]);
        generatePermutations(v, l + 1, r, results);
        std::swap(v[l], v[i]);
    }
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

    std::cout << "O(1): First Element = " << timeFunction(getFirstElement, v)<< " ms" << std::endl;

    //std::sort(v.begin(), v.end());
    //std::cout << "O(log n): Binary Search time: " << timeFunction(binarySearch, v, 777) << " ms" << std::endl;

    std::cout << "O(n): Max Element time: " << timeFunction(findMax, v) << " ms" << std::endl;

    //std::cout << "O(n log n): Merge Sorting time: " << timeFunction(mergeSortSimplified, v) << " ms" << std::endl;

    // std::cout << "O(n^2): Bubble Sorting time: " << timeFunction(bubbleSort, v) << " ms" << std::endl;
    
    // std::cout << "O(2^n): Fibonacci(5) time: " << timeFunction(fibonacci, 49) << " ms" << std::endl;
    
    std::vector<std::vector<int>> results;
    std::cout << "O(n!): Generating Permutations (first 16 elements) time: " << timeFunction(generatePermutations, v, 0, 15, results) << " ms" << std::endl;
    std::cout << "Size of results: " << results.size()<<std::endl;
    return 0;
}
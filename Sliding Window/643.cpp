#include <vector>
#include <numeric> // For std::accumulate (or can do manual sum)
#include <algorithm> // For std::max
#include <iostream>  // For example usage
using namespace std;

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Calculate the sum of the first k elements
        int current_sum = 0; 
        for (int i = 0; i < k; ++i) {
            current_sum += nums[i];
        }

        int max_sum = current_sum; // Initialize max_sum with the sum of the first window

        // Step 3: Slide the window
        // Start from the k-th element (index k)
        for (int i = k; i < n; ++i) {
            // Add the new element entering the window (nums[i])
            // Subtract the element leaving the window (nums[i-k])
            current_sum += nums[i] - nums[i-k];
            
            // Update max_sum if the current window sum is greater
            max_sum = max(max_sum, current_sum);
        }

        // Step 4: Calculate the maximum average
        // Cast to double for accurate division
        return static_cast<double>(max_sum) / k;
    }
};
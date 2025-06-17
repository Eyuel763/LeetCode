#include <vector>
#include <unordered_map> 
#include <iostream>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0; // Stores the total number of subarrays whose sum equals k
        int current_sum = 0; // Stores the running sum of elements
        
        // A hash map to store the frequency of each prefix sum encountered so far.
        // Key: prefix sum, Value: frequency of that prefix sum
        unordered_map<int, int> prefix_sum_counts;
        
        // Initialize the map with a prefix sum of 0 occurring once.
        // This handles the case where a subarray starting from index 0 itself sums to k.
        // For example, if nums = [2] and k = 2, current_sum will become 2.
        // We look for current_sum - k = 2 - 2 = 0. If 0 is in the map, it means
        // the subarray from index 0 to current index has sum k.
        prefix_sum_counts[0] = 1; 
        
        for (int num : nums) {
            current_sum += num; // Update the running sum
            
            // Check if (current_sum - k) exists in our hash map.
            // If it does, it means there was a previous prefix_sum_counts[i] such that
            // current_sum - prefix_sum_counts[i] = k.
            // The value associated with current_sum - k tells us how many such
            // previous prefix sums exist, which directly translates to
            // the number of subarrays ending at the current position with sum k.
            if (prefix_sum_counts.count(current_sum - k)) {
                count += prefix_sum_counts[current_sum - k];
            }
            
            // Increment the frequency of the current_sum in the map.
            // If current_sum is not yet a key, it will be added with a frequency of 1.
            // Otherwise, its frequency will be increased by 1.
            prefix_sum_counts[current_sum]++;
        }
        
        return count;
    }
};
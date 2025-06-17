#include <vector> 
#include <iostream>
using namespace std; 

class Solution {
public:
    vector<int> runningSum(std::vector<int>& nums) {
        int n = nums.size(); // Get the number of elements in the input vector
        
        // Create a new vector to store the running sum.
        // It will have the same size as the input 'nums' vector.
        vector<int> running_sum(n); 
        
        // The first element of the running sum is simply the first element of nums.
        if (n > 0) { // Check to ensure the array is not empty
            running_sum[0] = nums[0];
        }
        
        // Iterate from the second element (index 1) up to the end of the array.
        // Each element of running_sum is the sum of the current nums element
        // and the previous running_sum element.
        for (int i = 1; i < n; ++i) {
            running_sum[i] = running_sum[i-1] + nums[i];
        
        }
        
        return running_sum; 
    }
};
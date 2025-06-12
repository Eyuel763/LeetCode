#include <vector>
#include <limits>
class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int minLength = std::numeric_limits<int>::max(); // Initialize with a very large number
        int currentSum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            currentSum += nums[right]; // Expand the window by adding the current element

            // While the current window sum is greater than or equal to the target
            while (currentSum >= target) {
                // Update the minimum length found so far
                minLength = std::min(minLength, right - left + 1);
                
                // Shrink the window from the left
                currentSum -= nums[left];
                left++;
            }
        }
        
        // If minLength is still std::numeric_limits<int>::max(), no such subarray was found
        return (minLength == std::numeric_limits<int>::max()) ? 0 : minLength;
    }
};
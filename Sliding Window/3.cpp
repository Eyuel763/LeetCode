#include <string>
#include <unordered_set> // For efficient character lookup
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }

        int maxLength = 0;
        int left = 0;
        unordered_set<char> charSet; // Stores characters in the current window

        // The 'right' pointer expands the window
        for (int right = 0; right < n; ++right) {
            // While the character at 'right' is already in our set (duplicate found)
            while (charSet.count(s[right])) {
                // Remove the character at 'left' from the set
                charSet.erase(s[left]);
                // Shrink the window from the left
                left++;
            }
            
            // Add the new character at 'right' to the set
            charSet.insert(s[right]);
            
            // Update the maximum length found so far
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
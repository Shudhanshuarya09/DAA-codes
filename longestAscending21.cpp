#include <iostream>
#include <vector>

using namespace std;

int longest_ascending_subsequence(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
  
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int longest = 0;
    for (int i = 0; i < n; ++i) {
        longest = max(longest, dp[i]);
    }

    return longest;
}

int main() {
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << "Length of the longest ascending subsequence: " << longest_ascending_subsequence(nums) << endl;
    return 0;
}
#include <iostream> 
#include <vector> 
#include <algorithm> 
int knapsack(int W, const std::vector<int>& weights, const std::vector<int>& values) { 
 int n = weights.size(); 
 // Initialize a 2D vector to store the maximum value that can be obtained with 
 // the first i items and a knapsack capacity of j 
 std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0)); 
 // Fill the dp table 
 for (int i = 1; i <= n; ++i) { 
 for (int j = 1; j <= W; ++j) { 
 if (weights[i - 1] > j) { 
 dp[i][j] = dp[i - 1][j]; 
 } else { 
 dp[i][j] = std::max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]); 
 } 
 } 
 } 
 return dp[n][W]; 
} 
int main() { 
 int W = 50; // Knapsack capacity 
 std::vector<int> weights = {10, 20, 30}; // Weights of items 
 std::vector<int> values = {60, 100, 120}; // Values of items 
 std::cout << "Maximum value that can be obtained: " << knapsack(W, weights, values) << std::endl; 
 return 0; 
} 
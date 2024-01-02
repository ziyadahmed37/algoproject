#include <iostream>
#include <vector>

std::string longest_common_substring(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();

    // Create a 2D table to store the lengths of common substrings
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Variables to store the length of the longest common substring and its ending index
    int max_length = 0;
    int end_index = 0;

    // Fill the dynamic programming table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_length) {
                    max_length = dp[i][j];
                    end_index = i - 1;
                }
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    // Extract the longest common substring
    std::string longest_common_sub = str1.substr(end_index - max_length + 1, max_length);

    return longest_common_sub;
}

int main() {
    std::string str1 = "Algorithms";
    std::string str2 = "Advamncedalgorithms";

    std::string result = longest_common_substring(str1, str2);
    std::cout << "Longest Common Substring: " << result << std::endl;

    return 0;
}

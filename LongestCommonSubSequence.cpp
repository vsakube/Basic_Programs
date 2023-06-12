#include <iostream>
#include <vector>

std::string longestCommonSubsequence(std::string str1, std::string str2) {
    int m = str1.length();
    int n = str2.length();

    // Create a 2D table to store the lengths of LCS
    std::vector<std::vector<int>> lcs_lengths(m + 1, std::vector<int>(n + 1, 0));

    // Populate the table using dynamic programming
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                lcs_lengths[i][j] = lcs_lengths[i - 1][j - 1] + 1;
            } else {
                lcs_lengths[i][j] = std::max(lcs_lengths[i - 1][j], lcs_lengths[i][j - 1]);
            }
        }
    }

    // Retrieve the longest common subsequence
    std::string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs = str1[i - 1] + lcs;
            --i;
            --j;
        } else if (lcs_lengths[i - 1][j] > lcs_lengths[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    return lcs;
}

int main() {
    std::string str1 = "ABCDGH";
    std::string str2 = "AEDFHR";

    std::string lcs = longestCommonSubsequence(str1, str2);
    std::cout << "Longest Common Subsequence: " << lcs << std::endl;

    return 0;
}


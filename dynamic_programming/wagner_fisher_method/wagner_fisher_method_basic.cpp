#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) 
        dp[i][0] = i;
    for (int j = 0; j <= m; j++) 
        dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::min({
                    dp[i - 1][j],
                    dp[i][j - 1],
                    dp[i - 1][j - 1]
                }) + 1;
            }
        }
    }

    std::vector<std::string> ops;
    int i = n, j = m;

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && s1[i - 1] == s2[j - 1]) {
            ops.push_back("keep    " + std::string(1, s1[i - 1]));
            i--; j--;
        }
        else if (i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + 1) {
            ops.push_back("replace " + std::string(1, s1[i - 1]) + " -> " + std::string(1, s2[j - 1]));
            i--; j--;
        }
        else if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
            ops.push_back("delete  " + std::string(1, s1[i - 1]));
            i--;
        }
        else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
            ops.push_back("insert  " + std::string(1, s2[j - 1]));
            j--;
        }
    }

    std::cout << "distance: " << dp[n][m] << std::endl;
    for (int i = ops.size() - 1; i >= 0; i--)
        std::cout << ops[i] << std::endl;
}

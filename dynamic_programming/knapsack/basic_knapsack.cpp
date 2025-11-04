#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, W;
    std::cin >> N >> W;

    std::vector<int> w(N+1);
    std::vector<int> p(N+1);

    for (int i = 1; i <= N; i++) {
        std::cin >> w[i] >> p[i];
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0));

    // create table

    // dp(k, s) = max(dp(k - 1, s), dp(k - 1, s - wk) + pk)
    for (int k = 1; k <= N; k++) {
        for (int s = 0; s <= W; s++) {
            dp[k][s] = dp[k-1][s];
            
            if (s >= w[k]) {
                dp[k][s] = std::max(dp[k][s], dp[k - 1][s - w[k]] + p[k]);
            }
        }
    }

    // restore answer

    // if dp(k, s) == dp(k - 1, s) go to dp(k - 1, s)
    // else add wk to answer and go to dp(k - 1, s - wk)
    std::vector<int> answer;
    int s = W;
    for (int k = N; k >= 1; k--) {
        if (dp[k][s] != dp[k - 1][s]) {
            answer.push_back(k);
            s -= w[k];
        }
    }

    // print answer
    for (int i = intanswer.size() - 1; i >= 0; i--) {
        std::cout << answer[i] << " ";
    }
    std::cout << std::endl;
}

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, W;
    std::cin >> N >> W;

    std::vector<int> w(N+1), p(N+1);
    for (int i = 1; i <= N; i++) {
        std::cin >> w[i] >> p[i];
    }

    std::vector<int> dp(W + 1, 0);

    for (int k = 1; k <= N; k++) {
        for (int s = W; s >= w[k]; s--) {
            dp[s] = std::max(dp[s], dp[s - w[k]] + p[k]);
        }
    }

    int s = W;
    std::vector<int> answer;

    for (int k = N; k >= 1; k--) {
        if (s >= w[k] && dp[s] == dp[s - w[k]] + p[k]) {
            answer.push_back(k);
            s -= w[k];
        }
    }

    // print answer
    for (int i = answer.size() - 1; i >= 0; i--) {
        std::cout << answer[i] << " ";
    }
    
    std::cout << std::endl;
}

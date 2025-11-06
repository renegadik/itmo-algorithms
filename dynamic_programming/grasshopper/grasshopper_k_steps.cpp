#include <iostream>
#include <vector>
#include <cstdint>

int main() {
    int n, K;
    std::cin >> n >> K;
    
    std::vector<int64_t> dp(n + 1, 0);
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= K; j++) {
            if (i - j >= 0) 
                dp[i] += dp[i - j];
        }
    }

    std::cout << dp[n] << std::endl;
}
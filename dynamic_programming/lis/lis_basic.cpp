#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];

    std::vector<int> dp(n, 1);
    std::vector<int> prev(n, -1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    int best_len = 0;
    int best_pos = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > best_len) {
            best_len = dp[i];
            best_pos = i;
        }
    }

    std::vector<int> lis;
    int cur = best_pos;

    while (cur != -1) {
        lis.push_back(v[cur]);
        cur = prev[cur];
    }

    for (int i = lis.size() - 1; i >= 0; i--)
        std::cout << lis[i] << " ";
}

#include <iostream>
#include <vector>
#include <cstdint>

int64_t solve(int n, std::vector<int64_t>& memo) {
    if (n == 0) 
        return 1;
    if (n == 1) 
        return 1;

    if (memo[n] != -1) 
        return memo[n];

    memo[n] = solve(n - 1, memo) + solve(n - 2, memo);
    return memo[n];
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int64_t> memo(n + 1, -1);

    std::cout << solve(n, memo) << std::endl;
}
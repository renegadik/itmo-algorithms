#include <iostream>
#include <vector>
#include <cstdint>

int main() {
    int n;
    std::cin >> n;

    if (n == 0 || n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }

    int64_t prev2 = 1;
    int64_t prev1 = 1;
    int64_t curr = 0;

    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    std::cout << curr << std::endl;
}

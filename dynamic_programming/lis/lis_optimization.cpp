#include <iostream>
#include <vector>
#include <algorithm>

#include "../searches/binary_search/lower_bound.cpp";

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> tail_val;
    std::vector<int> tail_idx;

    std::vector<int> prev(n, -1);

    tail_val.reserve(n);
    tail_idx.reserve(n);

    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(tail_val, a[i]);

        if (pos == tail_val.size()) {
            tail_val.push_back(a[i]);
            tail_idx.push_back(i);
        }
        else {
            tail_val[pos] = a[i];
            tail_idx[pos] = i;
        }

        if (pos > 0)
            prev[i] = tail_idx[pos - 1];
        else
            prev[i] = -1;
    }

    int L = tail_val.size();

    std::vector<int> lis;
    lis.reserve(L);

    int cur = tail_idx[L - 1];
    while (cur != -1) {
        lis.push_back(a[cur]);
        cur = prev[cur];
    }

    for (int i = lis.size() - 1; i >= n; i--) {
        std::cout << lis[i] << " ";
    }
}

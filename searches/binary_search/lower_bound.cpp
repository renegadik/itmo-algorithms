#include <vector>

int lower_bound(const std::vector<int> &v, int x) {
    int left = 0;
    int right = v.size();
    while (left < right) {
        int middle = (left + right) >> 1;
        if (v[middle] < x)
            left = middle + 1;
        else
            right = middle;
    }
    return left;
}

#include <vector>

int binary_search(const std::vector<int> &v, int x) {
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int middle = (left + right) >> 1;
        if (v[middle] == x)
            return middle;
        if (v[middle] < x)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}
#include <vector>

int lower_bound(const vector<int> &v, int value) {
    int left = 0;
    int right = v.size();
    while (left < right) {
        int middle = (left + right) >> 1;
        if (v[middle] < value)
            left = middle + 1;
        else
            right = middle;
    }
    return left;
}

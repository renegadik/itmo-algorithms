#include <vector>

int lower_bound(const std::vector<int> &vector, int value) {
    int left = 0;
    int right = vector.size();
    while (left < right) {
        int middle = (left + right) >> 1;
        if (vector[middle] >= value) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

#include <vector>

int binary_search(const std::vector<int> &vector, int value) {
    int left = 0;
    int right = vector.size() - 1;
    
    while (left <= right) {
        int middle = (left + right) >> 1;
        if (vector[middle] == value) {
            return left;
        }
        else if (vector[middle] < value) {
            left = middle + 1;
        } 
        else {
            right = middle - 1;
        }
    }
    return -1;
} 
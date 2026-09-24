#include <iostream>
#include <random>
#include <utility>
#include <vector>

std::mt19937 generator{std::random_device{}()};

int partition(std::vector<int>& values, int left, int right) {
    std::uniform_int_distribution<int> distribution(left, right);
    int pivotIndex = distribution(generator);
    std::swap(values[pivotIndex], values[right]);
    int pivot = values[right];
    int smaller = left - 1;

    for (int index = left; index < right; ++index) {
        if (values[index] <= pivot) {
            ++smaller;
            std::swap(values[smaller], values[index]);
        }
    }

    std::swap(values[smaller + 1], values[right]);
    return smaller + 1;
}

void quickSort(std::vector<int>& values, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivotIndex = partition(values, left, right);
    quickSort(values, left, pivotIndex - 1);
    quickSort(values, pivotIndex + 1, right);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> values(n);
    for (int& value : values) {
        std::cin >> value;
    }

    quickSort(values, 0, n - 1);
    for (int value : values) {
        std::cout << value << ' ';
    }
}
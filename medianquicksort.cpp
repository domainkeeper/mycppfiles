// Quick sort using the median-of-three pivot selection strategy.
#include <algorithm>
#include <vector>

template <typename T>
int medianOfThree(std::vector<T>& values, int left, int right)
{
	const int middle = left + (right - left) / 2;

	if (values[middle] < values[left])
		std::swap(values[middle], values[left]);
	if (values[right] < values[left])
		std::swap(values[right], values[left]);
	if (values[right] < values[middle])
		std::swap(values[right], values[middle]);

	// Place the median just outside the partition range.
	std::swap(values[middle], values[right - 1]);
	return right - 1;
}

template <typename T>
void medianQuickSort(std::vector<T>& values, int left, int right)
{
	if (right - left <= 1) {
		if (right > left && values[right] < values[left])
			std::swap(values[right], values[left]);
		return;
	}

	const int pivotIndex = medianOfThree(values, left, right);
	const T pivot = values[pivotIndex];
	int i = left;
	int j = right - 1;

	while (true) {
		while (values[++i] < pivot) {}
		while (pivot < values[--j]) {}

		if (i < j)
			std::swap(values[i], values[j]);
		else
			break;
	}

	std::swap(values[i], values[pivotIndex]);
	medianQuickSort(values, left, i - 1);
	medianQuickSort(values, i + 1, right);
}

template <typename T>
void medianQuickSort(std::vector<T>& values)
{
	if (values.size() > 1)
		medianQuickSort(values, 0, static_cast<int>(values.size()) - 1);
}

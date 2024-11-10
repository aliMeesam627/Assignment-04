#include <iostream>

int THRESHOLD = 20;

// Function to perform Quick Sort partitioning
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hybrid Quick-Merge Sort function
void hybridQuickMergeSort(int arr[], int low, int high) {
    if (high - low + 1 <= THRESHOLD) {
        // Use insertion sort when array size is below the threshold
        for (int i = low + 1; i <= high; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= low && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    } else {
        // Use Quick Sort partitioning for larger sections
        int pivotIndex = partition(arr, low, high);
        hybridQuickMergeSort(arr, low, pivotIndex - 1);
        hybridQuickMergeSort(arr, pivotIndex + 1, high);
    }
}

// Helper function to print an array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {24, 17, 12, 22, 19, 23, 10, 15, 28, 30, 4, 14, 9, 6, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, size);

    hybridQuickMergeSort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    printArray(arr, size);
    return 0;
}

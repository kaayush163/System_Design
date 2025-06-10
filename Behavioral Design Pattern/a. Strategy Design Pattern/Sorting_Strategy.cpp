#include <bits/stdc++.h>
using namespace std;
class SortingStrategy {
public:
    virtual void sort(std::vector<int>& arr) = 0;
};
class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& arr) override
    {
        // Implement Bubble Sort algorithm
        int n = arr.size();
        bool swapped;

        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }

            // If no two elements were swapped, then break
            if (!swapped)
                break;
        }

        for(int i=0;i<n;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

class QuickSort : public SortingStrategy {
    private:

    int partition(vector<int> &vec, int low, int high) {

    // Selecting last element as the pivot
    int pivot = vec[high];

    // Index of elemment just before the last element
    // It is used for swapping
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // Put pivot to its position
    swap(vec[i + 1], vec[high]);

    // Return the point of partition
    return (i + 1);
}

    void quickSort(vector<int> &vec, int low, int high) {

    // Base case: This part will be executed till the starting
    // index low is lesser than the ending index high
    if (low < high) {

        // pi is Partitioning Index, arr[p] is now at
        // right place
        int pi = partition(vec, low, high);

        // Separately sort elements before and after the
        // Partition Index pi
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}
public:
    void sort(std::vector<int>& arr) override
    {
        // Implement Quick Sort algorithm
        int n = arr.size();
        quickSort(arr, 0, n - 1);

        for(int i=0;i<n;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

// Add more sorting algorithms as needed

class SortContext {
private:
    SortingStrategy* strategy;

public:
    void setStrategy(SortingStrategy* strategy)
    {
        this->strategy = strategy;
    }

    void executeStrategy(std::vector<int>& arr)
    {
        strategy->sort(arr);
    }
};
int main()
{
    std::vector<int> data = { 5, 2, 7, 1, 9 };

    SortContext context;
    BubbleSort bubbleSort;
    QuickSort quickSort;

    context.setStrategy(&bubbleSort);
    context.executeStrategy(data); // Executes Bubble Sort

    context.setStrategy(&quickSort);
    context.executeStrategy(data); // Executes Quick Sort

    return 0;
}

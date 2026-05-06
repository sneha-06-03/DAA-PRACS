#include <iostream>
#include <vector>
using namespace std;

int comp = 0;

// Partition function
int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comp++; // count comparison
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

// Quick Sort
void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    comp = 0;
    quickSort(a, 0, n - 1);

    cout << "Sorted array:\n";
    for (int x : a)
        cout << x << " ";

    cout << "\nNumber of comparisons: " << comp << endl;

    return 0;
}

// INPUT

//Enter number of elements: 5
//Enter elements:
//5 2 4 6 1

// OUTPUT

//Sorted array:
//1 2 4 5 6
//Number of comparisons: 7
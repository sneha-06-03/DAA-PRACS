#include <iostream>
#include <vector>
using namespace std;

int comp = 0;

// Heapify function
void heapify(vector<int>& a, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n) {
        comp++; // comparison
        if (a[left] > a[largest])
            largest = left;
    }

    if (right < n) {
        comp++; // comparison
        if (a[right] > a[largest])
            largest = right;
    }

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

// Heap Sort
void heapSort(vector<int>& a) {
    int n = a.size();

    // Build heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
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
    heapSort(a);

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
//Number of comparisons: 10
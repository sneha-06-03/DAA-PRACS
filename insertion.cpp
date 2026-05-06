#include <iostream>
#include <vector>
using namespace std;

int insertionSort(vector<int>& a) {
    int comparisons = 0;
    int n = a.size();

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++;  // count comparison
            if (a[j] > key) {
                a[j + 1] = a[j];
                j--;
            } else {
                break;
            }
        }
        a[j + 1] = key;
    }

    return comparisons;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int comp = insertionSort(a);

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
//Number of comparisons: 8
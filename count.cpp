#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countSort(vector<int>& a) {
    int maxVal = *max_element(a.begin(), a.end());

    vector<int> count(maxVal + 1, 0);

    // Count frequency
    for (int i = 0; i < a.size(); i++) {
        count[a[i]]++;
    }

    // Reconstruct sorted array
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            a[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    countSort(a);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

// INPUT

//Enter number of elements: 6
//Enter elements:
//4 1 3 4 2 1

// OUTPUT

//Sorted array:
//1 1 2 3 4 4
#include <iostream>
using namespace std;

int main() {
    int arr[5][5] = {
        {1, 2, 3, 4, 22},
        {5, 6, 7, 8, 23},
        {9, 10, 11, 12, 24},
        {13, 14, 15, 16, 25},
        {18, 19, 20, 21, 26}
    };
    int n = 5; // Size of the array
    int k = 0; // Starting row index
    int l = 0; // Starting column index

    while (k < n && l < n) {
        // Print the first row from the remaining rows
        for (int i = l; i < n; ++i) {
            cout << arr[k][i] << " ";
        }
        k++;

        // Print the last column from the remaining columns
        for (int i = k; i < n; ++i) {
            cout << arr[i][n - 1] << " ";
        }
        n--;

        // Print the last row from the remaining rows
        if (k < n) {
            for (int i = n - 1; i >= l; --i) {
                cout << arr[n][i] << " ";
            }
        }

        // Print the first column from the remaining columns
        if (l < n) {
            for (int i = n - 1; i >= k; --i) {
                cout << arr[i][l] << " ";
            }
        }
        l++;
    }

    return 0;
}

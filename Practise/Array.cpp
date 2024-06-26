#include <iostream>

void modifyArray(int arr[3], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] *= 2; 
    }
}

int main() {
    int myArray[5] = {1, 2, 3, 4, 5};

    modifyArray(myArray, 5);

    std::cout << "Modified array: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << myArray[i] << " ";
    }
     int myArray1[8] = {1, 2, 3, 4, 5,6,7,8};

    modifyArray(myArray1, 8);
    std::cout << std::endl;
    std::cout << "Modified array: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << myArray[i] << " ";
    }

    return 0;
}



// #include <iostream>
// // #include<conio.h>
// // #include<stdio.h>
// using namespace std;

// int sumWithPostIncrement(int arr[], int size) {
//     int sum = 0;
//     int count = 0;
//     for (int i = 0; i < size; i++) {
//         sum += arr[i];
//         count = i;
//         cout<<" "<<count;
//     }
//     return count;
// }

// int sumWithPreIncrement(int arr[], int size) {
//     int sum = 0;
//     int count = 0;
//     for (int i = 0; i < size; ++i) {
//         sum += arr[i];
//         count = i;
//          cout<<" "<<count;
//     }
//     return count;
// }

// int main() {
//     int arr[] = {1, 2, 3, 4, 5};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     std::cout << "Count using post-increment: " << sumWithPostIncrement(arr, size) << std::endl;
//     std::cout << "Count using pre-increment: " << sumWithPreIncrement(arr, size) << std::endl;

//     return 0;
// }

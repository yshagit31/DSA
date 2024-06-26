//Rverse an array
// if array is [1,2,3,4,5,6] reverse is [6,5,4,3,2,1]
//what we do is we swap the last two elements and then swap the last two elements with the next to last element and so on
#include <iostream>
#include<utility>

void printArray(auto arr,int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void Reverse(int *arr,int size)
{
    int temp;
 for(int i=0,j=size-1;i<(size/2);i++,j--)
 {
    temp=arr[j];
    arr[j]=arr[i];
    arr[i]=temp;
 }
}
void Reverse2(int arr[],int size)
{
    int temp;
 for(int i=0,j=size-1;i<j;i++,j--)
 {
    temp=arr[j];
    arr[j]=arr[i];
    arr[i]=temp;
    // swap(arr[j],arr[i]);
 }
}

int main() {
    int myArray[6] = {1, 2, 3,4,5,6};

   Reverse2(myArray,6);
    printArray(myArray,6);

    int anotherArray[7] = {1, 2, 3, 4, 5, 6, 7};
   Reverse2(anotherArray,7);
    printArray(anotherArray,7);

    


    return 0;
}

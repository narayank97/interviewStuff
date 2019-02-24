#include <iostream>
#include <vector>

using namespace std;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
// need to pass vectors by REFERENCE to change original vector
int partition(vector<int> &myList, int low, int high)
{

    int pivot = myList[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++)
    {
        if(myList[j] <= pivot)
        {
            i++;
            int iElement = myList[i];
            // Here I swap element i and j 
            swap(&myList[i],&myList[j]);

        }

    }
    //Here I swap element i+1 and the last element
    swap(&myList[i+1],&myList[high]);
    
    return (i+1);

}

void printArray(vector<int> &arr,int size) 
{ 
    int i;
    for(i=0; i < size; i++) 
        printf("%d,", arr[i]); 
    printf("\n"); 
} 

void quickSort(vector<int> &myList, int low, int high)
{
    // low == starting index, high = ending index
    // myArray == list of numbers
    if(low < high)
    {
        int partIndex = partition(myList,low,high);
        quickSort(myList,low,partIndex-1);
        quickSort(myList,partIndex,high);

    }
}

int main()
{
    // These 2 lines easy to hard code into vector instead of pushback multiple times.
    int myArray[] = {101,16,7,78,6};//2,44,22,3,1,10,23,45,40,21,33,35,78};//,77,29,2,1,53,67,32,10,78,45,12,65,23,24,25,26,88,29,64,90,100};
    vector<int> vec (myArray, myArray + sizeof(myArray) / sizeof(myArray[0]));
    int low = 0;
    int high = vec.size();
    cout << "Original List\n";
    printArray(vec,high);
    cout << "\n";
    quickSort(vec,low,high);
    cout << "NEW List\n";
    printArray(vec,high);
    return 0;
}
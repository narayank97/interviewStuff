#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(vector<int> &myVec, int low, int high)
{
    int i = low - 1;
    int pivot = myVec[high];
    for(int j = low; j < high; j++)
    {
        if(myVec[j] <= pivot)
        {
            i++;
            // Swap VARS here
            swap(&myVec[j],&myVec[i]);
        }
    }
    //swap pivot and i+1
    swap(&myVec[high],&myVec[i+1]);
    return (i+1);
}

void quickSort(vector<int> &myVec, int low, int high)
{
    if(low < high)
    {
        int partitionIndex = partition(myVec,low,high);
        quickSort(myVec,low,partitionIndex - 1);
        quickSort(myVec, partitionIndex, high);
    }
}


int main()
{
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(30);
    vec.push_back(23);
    vec.push_back(13);
    vec.push_back(65);
    vec.push_back(12);
    vec.push_back(23);

    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ,";
    }
    cout << "\n";
    quickSort(vec,0,vec.size()-1);
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ,";
    }
    cout << "\n";

    return 0;
}
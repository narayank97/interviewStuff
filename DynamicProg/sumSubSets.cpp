#include <iostream>

using namespace std;

int rec(int *arr, int total, int index)
{
    if(total == 0)
    {
        return 1;
    }
    else if(total < 0)
    {
        return 0;
    }
    else if(index < 0)
    {
        return 0;
    }
    else if(total < arr[index])
    {
        return rec(arr,total,index-1);
    }
    else
    {
        return rec(arr,total,index-1) + rec(arr,total - arr[index],index-1); 
    }

}

int countSets(int *arr, int total, int arraySize)
{
    return rec(arr,total,arraySize-1);
}

int main()
{
    //int myArray[4] = {2,4,6,10};
    int myArray[10] = {1,2,3,4,5,6,7,8,9,10};
    int total = 10;
    cout << "the number of sets that add to " << total
         << " is " << countSets(myArray,total,10) <<"\n";
    return 0;
}
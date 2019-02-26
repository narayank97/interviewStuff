#include <iostream>

using namespace std;

int binarySearch(int *array, int leftIndex, int rightIndex, int desired)
{
    if(rightIndex >= leftIndex)
    {
        
        int middleIndex = leftIndex + (rightIndex-leftIndex)/2;
        if(array[middleIndex] == desired)
        {
            return middleIndex;
        }
        else if(desired < array[middleIndex])
        {
            return binarySearch(array,leftIndex,middleIndex-1,desired);
            
        }
        else
        {
            return binarySearch(array,middleIndex+1,rightIndex,desired);
        }
        
    }
    else
    {
        return -1;
    }
    
}

int main()
{
    int sortedArr[11] = {1,6,17,23,45,56,78,92,112,132,142};
    int x = binarySearch(sortedArr,0,9,112);
    cout << "This is the index: " << x << "\n";
    return 0;
}
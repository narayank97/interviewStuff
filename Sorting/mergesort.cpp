#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &myVec, int leftIndx, int middleIndx, int rightIndx)
{
    int i,j,k;
    // these VARS are size of my subarray after I split main Array
    int sizeArr1 = middleIndx - leftIndx + 1;
    int sizeArr2 = rightIndx - middleIndx;

    //create leftSubArray and rightSubArray
    vector<int> leftSub;
    vector<int> rightSub;

    // copy data into the subarrays
    for(i = 0; i < sizeArr1; i++)
    {
        leftSub.push_back(myVec[leftIndx+i]);
    }
    for(j = 0; j < sizeArr2; j++)
    {
        rightSub.push_back(myVec[middleIndx+1+j]);
    } 
    // merge temp vector back to myVec
    i = 0; // inital index of leftSub
    j = 0; // inital index of rightSub
    k = leftIndx; // inital index of merged Subarray

    
    while(i < sizeArr1 && j < sizeArr2)
    {
        if(leftSub[i] <= rightSub[j])
        {
            myVec[k] = leftSub[i];
            i++;
        }
        else
        {
            myVec[k] = rightSub[j];
            j++;
        }
        k++;
    }
    // copy rest of elements in leftSub if any left
    while(i < sizeArr1)
    {
        myVec[k] = leftSub[i];
        i++;
        k++;
    } 

    // copy rest of elements in rightSub if any left
    while(j < sizeArr2)
    {
        myVec[k] = rightSub[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> &myVec, int leftIndx, int rightIndx)
{
    if(leftIndx < rightIndx)
    {
        int middleIndx = leftIndx + (rightIndx-leftIndx)/2;
        mergesort(myVec,leftIndx,middleIndx);
        mergesort(myVec,middleIndx+1,rightIndx);
        merge(myVec,leftIndx,middleIndx,rightIndx);
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
    vec.push_back(230);
    vec.push_back(123);
    vec.push_back(4523);
    vec.push_back(4);
    vec.push_back(1); 

    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ,";
    }
    cout << "\n";
    mergesort(vec,0,vec.size()-1);
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ,";
    }
    cout << "\n";
    return 0;
}
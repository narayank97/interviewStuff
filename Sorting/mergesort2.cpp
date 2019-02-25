#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &vec, int leftIndex, int middleIndex, int rightIndex)
{
    int i,j,k;
    int sizeOfVec1 = middleIndex - leftIndex + 1;
    int sizeOfVec2 = rightIndex - middleIndex;

    vector<int> vec1;
    vector<int> vec2;
    
    // make subarrays
    for(i = 0; i < sizeOfVec1; i++)
    {
        vec1.push_back(vec[leftIndex+i]);
    }
    for(j = 0; j < sizeOfVec2; j++)
    {
        vec2.push_back(vec[j+middleIndex+1]);
    }
   
    // putback sorted elements into main vector
    i = 0;
    j = 0;
    k = leftIndex;

    while(i < sizeOfVec1 && j < sizeOfVec2)
    {
        if(vec1[i] <= vec2[j])
        {
            vec[k] = vec1[i];
            i++;
        }
        else
        {
            vec[k] = vec2[j];
            j++;
        }
        k++;
    }
    //can be leftover elements
    while(i < sizeOfVec1)
    {
        vec[k] = vec1[i];
        i++;
        k++;
    }
    while(j < sizeOfVec2)
    {
        vec[k] = vec2[j];
        j++;
        k++;
    }
}
void mergesort(vector<int> &vec, int leftIndex,int rightIndex)
{
    
    if(leftIndex < rightIndex)
    {
        int middleIndex = leftIndex + (rightIndex - leftIndex)/2;
       
        mergesort(vec,leftIndex,middleIndex);
        mergesort(vec,middleIndex+1,rightIndex);
        merge(vec,leftIndex,middleIndex,rightIndex);
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
// PERFECT HASH TABLE IF ALL GOES WELL
#include <iostream>
#include <string>

using namespace std;

int hashFunc(string key)
{
    int sum = 0;
    for(int i = 0; i < key.size(); i++)
    {
        sum+=key[i];
    }
    
    return sum % 11; // 11 is the size of my array
}

int main()
{
    string listOfNames[11] = {"Mia","Tim","Bea","Zoe","Sue","Len","Moe",
                              "Lou","Rae","Max","Tod"};
    string myHashTable[11];
    for(int i = 0; i < 11; i++)
    {
        // check if the position is free
        if(myHashTable[hashFunc(listOfNames[i])] == "\0")
        {
            myHashTable[hashFunc(listOfNames[i])] = listOfNames[i];
        }
        //while the space is not free increment j. when free spot found add j to original hash func 
        else
        {
            int j = 0;
            while(myHashTable[hashFunc(listOfNames[i])+j] != "\0")
            {
                j++;
            }
            myHashTable[hashFunc(listOfNames[i])+j] = listOfNames[i];
        }
    }
    for(int i = 0; i < 11; i++)
    {
        cout << myHashTable[i] << "\n";
    }
    return 0;
}

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
    string listOfNames[11] = {"Mia","Tim","Bea","Zoe","Jan","Ada","Leo",
                              "Sam","Lou","Max","Ted"};
    string myHashTable[11];
    for(int i = 0; i < 11; i++)
    {
        myHashTable[hashFunc(listOfNames[i])] = listOfNames[i];
    }
    for(int i = 0; i < 11; i++)
    {
        cout << myHashTable[i] << "\n";
    }
    return 0;
}

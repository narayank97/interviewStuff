// TOP DOWN APPROACH
#include <iostream>
#include <vector>

using namespace std;

int fib(int n,vector<int> &cache)
{
    if(n <= cache.size())
    {
        return cache[n-1];
    }
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    else
    {
        cache.push_back(fib(n-1,cache) + fib(n-2,cache));
        return fib(n-1,cache) + fib(n-2,cache);
        
    }
}

int main()
{
    vector<int> cache;
    cache.push_back(0);
    cache.push_back(1);
    cout << fib(23,cache) << "\n";
    cout << fib(30,cache) << "\n";
    cout << fib(90,cache) << "\n";
    return 0;
}
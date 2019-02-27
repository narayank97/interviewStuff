//BOTTOM UP APPROACH
#include <iostream>
#include <vector>

using namespace std;

unsigned long long int fib(unsigned long long int n)
{
    vector<unsigned long long int> cache;
    cache.push_back(0);
    cache.push_back(1);

    for(int i = 2; i < n+1; i++)
    {
        cache.push_back(cache[i-1] + cache[i-2]);
    }

    return cache[n];
}

int main()
{
    cout << fib(93) << "\n";
    return 0;
}
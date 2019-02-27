#include <iostream>
#include <string>

using namespace std;

int LCS(string p, string q, int pIndx, int qIndx)
{
    int result = 0;
    if(pIndx == 0 || qIndx == 0)
    {
        result = 0;
    }
    else if (p[pIndx-1] == q[qIndx-1])
    {
        result = 1 + LCS(p,q,pIndx-1,qIndx-1);
    }
    else if(p[pIndx-1] != q[qIndx-1])
    {
        int temp1 = LCS(p,q,pIndx,qIndx-1);
        int temp2 = LCS(p,q,pIndx-1,qIndx);
        if(temp1 >= temp2)
        {
            result = temp1;
        }
        else
        {
            result = temp2;
        }
    }
    return result;
}

int main()
{
    string A = "ABAB";
    string B = "AAB";
    int sizeOfSubstring = LCS(A,B,A.size(),B.size());
    cout << "The size of longest substring is " << sizeOfSubstring << "\n";
    return 0;
}
#include <iostream>
#include<algorithm>
using namespace std;
void linsearch(int n, int A[])
{
    int comparisons , i , found = 0, key;
    do
    {
        cout << "Enter the key to be searched: ";
        cin >> key;
        comparisons = 0;
        for (i = 0; i < n; i++)
        {
            comparisons++;
            if (A[i] == key)
            {
                found = 1;
                break;
            }
        }
        if (found ==0)
        {
            cout << "Key not found in the array." << endl;
        }
       
        cout << "Number of comparisons made: " << comparisons << endl;
        cout<<"Do you want to search for another key? (y/n): ";
    }
}


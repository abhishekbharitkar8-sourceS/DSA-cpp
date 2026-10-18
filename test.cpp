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
        char choice;
        cin>>choice;
    }while(choice == 'y');
}
void binsearch(int n, int A[])
{
    int comparisons , i , found = 0, key;
    do
    {
        cout << "Enter the key to be searched: ";
        cin >> key;
        comparisons = 0;
        int low = 0, high = n - 1;
        while (low <= high)
        {
            comparisons++;
            int mid = low + (high - low) / 2;
            if (A[mid] == key)
            {
                found = 1;
                break;
            }
            else if (A[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (found ==0)
        {
            cout << "Key not found in the array." << endl;
        }
       
        cout << "Number of comparisons made: " << comparisons << endl;
        cout<<"Do you want to search for another key? (y/n): ";
        char choice;
        cin>>choice;
    }while(choice == 'y');
}
int main()
{
    int n , i;
    int A[10];
    int choice;
    cout << "Enter the number of elements in the array (max 10): ";
    cin >> n;
    for(i = 0 ; i , n ; i++)
    {
        cout<<
    }
}
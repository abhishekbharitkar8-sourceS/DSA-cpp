#include <iostream>
using namespace std;
void bubblesort(int n , float A[])
{
    int comparisons = 0;
    for(int p = 1 ; p<n ; p++)
    {
        for( int i = 0; i<=n-1-p ; i++)
        
        {
            comparisons++;
            if(A[i]>A[i+1])
            {
                float temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
            }
            // cout<<comparisons;
        }
            // cout<<"comparisons are :"<<comparisons;
    }
    cout<<"comparisons are :"<<comparisons;
}
void selectionsort(int n , float A[])
{
    int comparisons = 0;
    for(int i = 0 ; i<n-1 ; i++)
    {
        int min = i;
        for(int j = i+1 ; j < n ; j++)
        {
            comparisons++;
            if(A[min]> A[j])
            {
                
                 min = j;
            }
          
        }
            float temp = A[i];
            A[i] = A[min];
            A[min] = temp;
            // cout<<"comparisons are :"<<comparisons;
    }
    cout<<"comparisons are :"<<endl<<comparisons;
}
int main()
{
    float A[10];
    int choice;
    int n;
    char ch;
    cout<<" enter the total number of students";
    cin>>n;
    for(int i = 0 ; i< n ; i++)
    {
        cout<<"enter the students";
        cin>>A[i];
    }
    
    cout<<"\n\n*********MENU**********";
    cout<<"\n\n1.bubble sort";
    cout<<"\n2.seletion sort";
    cout<<"\n3.exite";
    cout<<"\nenter choice";
    cin>>choice;
    if(choice == 1)
    {
        bubblesort(n, A);
    }
    else if (choice == 2)
    {
        selectionsort(n , A);
    }
    else if(choice == 3)
    {
        cout<<"exiting";
    }
    else
    {
        cout<<"invalid";
    }
    cout<<"\n\n*********sorted array**********"<<endl;
    for(int i = 0 ; i<n ; i++)
    {
        cout<<A[i]<<" ";
    }
       
   
}
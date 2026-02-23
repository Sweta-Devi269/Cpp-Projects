//Bubble Sort uing array
/* Element is compared one by one, and swapped if they are not in proper order. */

#include<iostream>
#define MAX 20
using namespace std;
int arr[MAX];

void bubble_sort(int n){
    int i, j, temp;
    for(i = 0; i< n-1; i++){
        for(j = 0; j< n-1-i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    cout<<"Enter the size of array (max. 20) : ";
    cin>>n;

    cout<<"Enter element : ";
    for(int i = 0; i< n; i++)
        cin>>arr[i];
    
    cout<<"Array :- \n";
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<"\t";
    cout<<endl;

    bubble_sort(n);
    cout<<"\nSorted array:- \n";
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<"\t";
    cout<<endl<<endl;
}
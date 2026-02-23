//Selection sort using array
#include<iostream>
#define MAX 20
using namespace std;
int ar[MAX];

void selection_sort(int n){
    int i, j, pos, temp;

    for(i = 0; i<n-1; i++){
        int small = ar[i];
        pos = i;
        for(j = i+1; j < n; j++){
            if(ar[j] < small){
                small = ar[j];
                pos = j;
            }
        }
        temp = ar[i];
        ar[i] = ar[pos];
        ar[pos] = temp;
    }
}

int main(){
    int n;
    cout<<"Enter the size of array (max. 20) : ";
    cin>>n;

    cout<<"Enter element : ";
    for(int i = 0; i< n; i++)
        cin>>ar[i];
    
    cout<<"Array :- \n";
    for(int i = 0; i<n; i++)
        cout<<ar[i]<<"\t";
    cout<<endl;

    selection_sort(n);
    cout<<"\nSorted array:- \n";
    for(int i = 0; i<n; i++)
        cout<<ar[i]<<"\t";
    cout<<endl<<endl;
}
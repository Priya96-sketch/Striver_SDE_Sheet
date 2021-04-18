#include<iostream>
using namespace std;

//Swap Function
void swap(int arr[], int i,int j)
{
int temp= arr[i];
arr[i] = arr[j];
arr[j] = temp;
}

//Main Function
void dnfSort(int arr[], int n)
{
int low =0;
int mid=0;
int high = n-1;

//Now loop for conditions

while(mid<=high)
{
    if(arr[mid]==0){
        swap(arr, low, mid);
        mid++;
        low++;
        }
        
    else if(arr[mid]==1){
        mid++;
        }
        
    else{
        swap(arr, high, mid)
        mid++;
        high--;
        }
}
}

int main()
{
int arr[] ={1,1,0,2,0,2,2,1};
dnfSort(arr[],8)

for(int i=0;i<8;i++)
{
    cout<<arr[i]<<" ";
}
return 0;
}

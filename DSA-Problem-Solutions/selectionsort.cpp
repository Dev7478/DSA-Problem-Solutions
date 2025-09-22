#include <iostream>
using namespace std;

void display(int arr[], int n) {
  cout << "This is a selection sort program" << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

void selectionSort(int arr[], int n){
  for(int i=0;i<n-1;i++){
    int minIndex=i;
    for(int j=i+1;j<n;j++){
      if(arr[j]<arr[minIndex])
        minIndex = j;
    }
    if(minIndex != i){
      swap(arr[i],arr[minIndex]);
      display(arr,n);
      cout<<endl;
    }
}
}
int main() {
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;
  int arr[n];
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  selectionSort(arr, n);
  cout << "Sorted array: ";
  display(arr, n);
  return 0;
}
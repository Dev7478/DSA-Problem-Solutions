#include <iostream>
using namespace std;

void display(int arr[], int n) {
  cout << "This is a bubble sort program" << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}
void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    int flag = 0;
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        display(arr, n);
        cout << endl;
        flag = 1;
      }
    }
    if (flag == 0)
      break;
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
  bubbleSort(arr, n);
  cout << "Sorted array: ";
  display(arr, n);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct Array
{
  int *A;
  int size;
  int length;
};

void display(struct Array arr)
{
  cout << "The elements of the array are: ";
  for (int i = 0; i < arr.length; i++)
  {
    cout << arr.A[i] << " ";
  }
  cout << "\n";
}
void insertSorted(Array &arr, int key)
{
  int i = arr.length - 1;
  while (arr.A[i] > key)
  {
    arr.A[i + 1] = arr.A[i];
    i--;
  }
  arr.A[i + 1] = key;
  arr.length++;
}
int main()
{
  Array arr;
  int n;
  cout << "Enter the size of the array: ";
  cin >> arr.size;
  arr.A = new int[arr.size];
  cout << "Enter the number of numbers: ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr.A[i];
  }
  arr.length = n;
  insertSorted(arr, 5);
  display(arr);
}
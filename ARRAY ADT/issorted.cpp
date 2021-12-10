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

int isSorted(struct Array arr)
{
  int i;
  for (i = 0; i < arr.length - 1; i++)
  {
    if (arr.A[i] > arr.A[i + 1])
      return 0;
  }
  return 1;
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
  if (isSorted(arr) == 1)
    cout << "Sorted\n";
  display(arr);
}
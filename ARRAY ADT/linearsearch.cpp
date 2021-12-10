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
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int linearSearch(Array arr, int key)
{
  for (int i = 0; i < arr.length; i++)
  {
    if (key == arr.A[i])
    {
      swap(&arr.A[i], &arr.A[0]);
      return i;
    }
  }
  return -1;
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
  int x = linearSearch(arr, 4);
  if (x != -1)
    cout << "element found" << endl;
  else
    cout << "Element not found";
  display(arr);
}
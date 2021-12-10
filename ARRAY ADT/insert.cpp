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

void append(Array &arr, int x)
{
  if (arr.length < arr.size)
    arr.A[arr.length] = x;
}

void insert(Array &arr, int index, int x)
{
  if (index >= 0 && index <= arr.length)
  {
    for (int i = arr.length; i > index; i--) //start at index after last last element being there copy previous elements , until it reaches the given index where space will be created
    {
      arr.A[i] = arr.A[i - 1];
    }
    arr.A[index] = x;
    arr.length++;
  }
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
  insert(arr, 4, 7);
  display(arr);
}
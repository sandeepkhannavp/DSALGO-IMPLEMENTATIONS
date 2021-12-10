#include <bits/stdc++.h>
using namespace std;
struct Array
{
  int *A;
  int size;
  int length;
};
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void display(struct Array arr)
{
  cout << "The elements of the array are: ";
  for (int i = 0; i < arr.length; i++)
  {
    cout << arr.A[i] << " ";
  }
  cout << "\n";
}
void oneSide(Array &arr)
{
  int i = 0;
  int j = arr.length - 1;
  while (i < j)
  {
    while (arr.A[i] < 0)
      i++;
    while (arr.A[j] >= 0)
      j--;
    if (i < j)
      swap(arr.A[i], arr.A[j]);
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
  oneSide(arr);
  display(arr);
}
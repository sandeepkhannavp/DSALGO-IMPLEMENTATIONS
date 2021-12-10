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
int Get(struct Array arr, int index)
{
  if (index >= 0 && index < arr.length)
    return arr.A[index];
  return -1;
}
void Set(struct Array &arr, int index, int x)
{
  if (index >= 0 && index < arr.length)
    arr.A[index] = x;
}
int Max(struct Array arr)
{
  int max = arr.A[0];
  int i;
  for (i = 1; i < arr.length; i++)
  {
    if (arr.A[i] > max)
      max = arr.A[i];
  }
  return max;
}
int Min(struct Array arr)
{
  int min = arr.A[0];
  int i;
  for (i = 1; i < arr.length; i++)
  {
    if (arr.A[i] < min)
      min = arr.A[i];
  }
  return min;
}
int Sum(struct Array arr)
{
  int s = 0;
  int i;
  for (i = 0; i < arr.length; i++)
    s += arr.A[i];
  return s;
}
float Avg(struct Array arr)
{
  return (float)Sum(arr) / arr.length;
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
  display(arr);
}
//we can perform it in two ways
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
//first way is using auxillary array-copy in reverse to auxillary array and again copy back
void Reverse(struct Array &arr)
{
  int *B;
  int i, j;
  B = new int[arr.length];
  for (i = arr.length - 1, j = 0; i >= 0; i--, j++)
    B[j] = arr.A[i];
  for (i = 0; i < arr.length; i++)
    arr.A[i] = B[i];
}
//second way-scan from two ends of the array and interchange, stop when i becomes greater than j
void Reverse2(struct Array &arr)
{
  int i, j;
  for (i = 0, j = arr.length - 1; i < j; i++, j--)
  {
    swap(&arr.A[i], &arr.A[j]);
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
  Reverse2(arr);
  display(arr);
}
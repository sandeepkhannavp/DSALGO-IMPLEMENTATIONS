//there are three ways for performing binary search
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
// first way
int BinarySearch(struct Array arr, int key)
{
  int l, mid, h;
  l = 0;
  h = arr.length - 1;
  while (l <= h)
  {
    mid = (l + h) / 2;
    if (key == arr.A[mid])
      return mid;
    else if (key < arr.A[mid])
      h = mid - 1;
    else
      l = mid + 1;
  }
  return -1;
}

//second way
int RBinSearch(int a[], int l, int h, int key)
{
  int mid = 0;
  if (l <= h)
  {
    mid = (l + h) / 2;
    if (key == a[mid])
      return mid;
    else if (key < a[mid])
      return RBinSearch(a, l, mid - 1, key);
    else
      return RBinSearch(a, mid + 1, h, key);
  }
  return -1;
}

//third way
int A_binarysearch(int arr[], int key, int n)
{
  int k = 0;
  for (int b = n / 2; b >= 1; b /= 2)
  {
    while (k + b < n && arr[k + b] <= key)
      k += b;
  }
  if (arr[k] == key)
    return 1;
  else
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
  cout << A_binarysearch(arr.A, 5, arr.length) << endl;
  ;
  display(arr);
}
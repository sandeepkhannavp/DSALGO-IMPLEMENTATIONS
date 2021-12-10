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
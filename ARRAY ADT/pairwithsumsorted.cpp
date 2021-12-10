#include <bits/stdc++.h>
using namespace std;
void findSum(int arr[], int n, int k)
{
  int i = 0;
  int j = n - 1;
  while (i <= j)
  {
    if (arr[i] + arr[j] == k)
    {
      cout << arr[i] << "+" << arr[j] << "=" << k << endl;
      i++;
      j--;
    }
    else if (arr[i] + arr[j] < k)
      i++;
    else if (arr[i] + arr[j] > k)
      j--;
  }
}
int main()
{
  int arr[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
  findSum(arr, sizeof(arr) / sizeof(arr[0]), 10);
}
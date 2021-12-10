#include <bits/stdc++.h>
using namespace std;
void findsum(int arr[], int n, int k)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] + arr[j] == k)
        cout << arr[i] << "+" << arr[j] << "=" << k << endl;
    }
  }
}
void hashSum(int arr[], int n, int key)
{
  int x = *max_element(arr, arr + n);
  int H[x] = {0};
  for (int i = 0; i < n; i++)
  {
    if (H[key - arr[i]] != 0 && (key - arr[i] >= 0))
    {
      cout << arr[i] << "+" << key - arr[i] << "=" << key << endl;
    }
    H[arr[i]]++;
  }
}
int main()
{
  int arr[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
  hashSum(arr, sizeof(arr) / sizeof(arr[0]), 10);
  return 0;
}
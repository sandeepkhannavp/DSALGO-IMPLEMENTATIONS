#include <bits/stdc++.h>
using namespace std;
void duplicate(int arr[], int n)
{
  int lastDuplicate;
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] == arr[i + 1] && arr[i] != lastDuplicate)
    {
      cout << arr[i] << " ";
      lastDuplicate = arr[i];
    }
  }
}

void countDuplicate(int arr[], int n)
{
  int j;
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] == arr[i + 1])
    {
      j = i + 1;
      while (arr[j] == arr[i])
        j++;
      cout << arr[i] << " occurs " << j - i << endl;
      i = j - 1;
    }
  }
}

//method 2-using hashtable
void hashDuplicate(int arr[], int n)
{
  int l = *max_element(arr, arr + n);
  int H[l] = {0};
  for (int i = 0; i < n; i++)
    H[arr[i]]++;
  for (int i = 0; i < l; i++)
  {
    if (H[i] > 1)
      cout << i << " occurs " << H[i] << endl;
  }
}
int main()
{
  int arr[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
  // duplicate(arr, sizeof(arr) / sizeof(arr[0]));
  hashDuplicate(arr, sizeof(arr) / sizeof(arr[0]));
  return 0;
}
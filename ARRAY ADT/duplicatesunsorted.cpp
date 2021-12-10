#include <bits/stdc++.h>
using namespace std;
void duplicate(int arr[], int n)
{

  for (int i = 0; i < n - 1; i++)
  {
    int count = 1;
    if (arr[i] != -1)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (arr[j] == arr[i])
        {
          count++;
          arr[j] = -1;
        }
      }
      if (count > 1)
        cout << arr[i] << " occurs " << count << endl;
    }
  }
}
//method2-using hashtable
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
  hashDuplicate(arr, sizeof(arr) / sizeof(arr[0]));
  return 0;
}
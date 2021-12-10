#include <bits/stdc++.h>
using namespace std;
void find(int arr[], int n)
{
  int diff = arr[0] - 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] - i != diff)
    {
      while (diff < arr[i] - i)
      {
        cout << i + diff << " ";
        diff++;
      }
    }
  }
}
//using hashing
void find2(int arr[], int n)
{
  int x = *max_element(arr, arr + n);
  int l = *min_element(arr, arr + n);
  int H[x] = {0};
  for (int i = 0; i < n; i++)
  {
    H[arr[i]]++;
  }
  for (int i = l; i < x; i++)
  {
    if (H[i] == 0)
      cout << i << " ";
  }
}
int main()
{
  int arr[] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19}; //in multiple missing elements we update the new difference
  //if the difference was 6 and new diff if 7, one element is missing
  //if diff is 7 and new diff is 9, two elements are missing
  int arr2[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
  //using hashtable
  find2(arr2, sizeof(arr2) / sizeof(arr2[0]));
  //  find(arr, sizeof(arr) / sizeof(arr[0]));
}
#include <bits/stdc++.h>
using namespace std;
void find(int array[], int n)
{
  int best = 0, sum = 0;
  for (int k = 0; k < n; k++)
  {
    sum = max(array[k], sum + array[k]);
    best = max(best, sum);
  }
  cout << best << "\n";
}
int main()
{
  int arr[] = {-10, 5, 6, 7, -20, -15, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  find(arr, n);
}
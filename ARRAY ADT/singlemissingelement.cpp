#include <bits/stdc++.h>
using namespace std;
//if it starts from 1-we can find the sum of all the elements of the array and subtract orginal sum from the sum we got- first n natural numbers
void find(int arr[], int n)
{
  int sum = 0, s = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  int x = *max_element(arr, arr + n);
  s = (x * (x + 1)) / 2;
  cout << "The missing element is " << s - sum << endl;
}
//second method - if the array starts from some other number
void find2(int arr[], int n)
{
  int l = *min_element(arr, arr + n);
  int diff = l - 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] - i != diff)
    {
      cout << "The missing element is " << i + diff;
      break;
    }
  }
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11};
  int arr1[] = {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17}; //the difference between number and index is constant that is the idea 6-0=7-1=8-2 ; //13-6 we get 7,to get missing element add 6 to index 6+6=12;
  find2(arr1, sizeof(arr1) / sizeof(arr1[0]));
  find(arr, sizeof(arr) / sizeof(arr[0]));
}
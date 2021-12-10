#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
void Bubble(int A[], int n)
{
  int i, j, flag = 0;

  for (i = 0; i < n - 1; i++)
  {
    flag = 0;
    for (j = 0; j < n - i - 1; j++)
    {
      if (A[j] > A[j + 1])
      {
        swap(&A[j], &A[j + 1]);
        flag = 1;
      }
    }
    if (flag == 0)
      break;
  }
  for (i = 0; i < 10; i++)
    cout << A[i] << " ";
  cout << endl;
}

void Insertion(int A[], int n)
{
  int j, x;

  for (int i = 1; i < n; i++)
  {
    j = i - 1;
    x = A[i];
    while (j > -1 && A[j] > x)
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = x;
  }
  for (int i = 0; i < 10; i++)
    cout << A[i] << " ";
  cout << endl;
}

void SelectionSort(int A[], int n)
{
  int k;

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = k = i; j < n; j++)
    {
      if (A[j] < A[k])
        k = j;
    }
    swap(&A[i], &A[k]);
  }
}

int main()
{
  int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
  cout << "Enter your choice 1)Bubble sort 2)Insertion sort 3)Selection sort \n";
  int x;
  cin >> x;
  switch (x)
  {
  case 1:
    Bubble(A, n);
    break;
  case 2:
    Insertion(A, n);
    break;
  case 3:
    SelectionSort(A, n);
    break;
  }

  return 0;
}
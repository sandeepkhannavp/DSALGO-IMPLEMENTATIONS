#include <iostream>
int main()
{
  int i, j, coins[4] = {2, 3, 5, 10}, amount = 5, arr_2D[4][amount];
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < amount; j++)
    {
      if (i == 0)
      {
        if ((j + 1) % coins[i] == 0)
        {
          arr_2D[i][j] = 1;
        }
        else
        {
          arr_2D[i][j] = 0;
        }
      }
      else
      {
        if (coins[i] > j + 1)
        {
          arr_2D[i][j] = arr_2D[i - 1][j];
        }
        else if (j + 1 - coins[i] == 0)
        {
          arr_2D[i][j] = arr_2D[i - 1][j] + 1;
        }
        else if (j + 1 - coins[i] > 0)
        {
          arr_2D[i][j] = arr_2D[i - 1][j] + arr_2D[i][j - coins[i]];
        }
      }
    }
  }
  printf("\nThere are %d possible combinations to give change of %d Rs.", arr_2D[3][amount - 1], amount);
  return 0;
}
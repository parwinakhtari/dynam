/**
 * Given a total and coins of certain denomination with infinite supply, what is the minimum number
 * of coins it takes to form this total.
 *
 * Time complexity - O(coins.size * total)
 * Space complexity - O(coins.size * total)
 *
 * Youtube video -
 * Topdown DP - https://youtu.be/Kf_M7RdHr1M
 * Bottom up DP - https://youtu.be/Y0ZqKpToTic
 */
int count( int coins[], int total )
{
    int i, j, x, y;
    int m=coins.size() ;
    // We need n+1 rows as the table
    // is constructed in bottom up
    // manner using the base case 0
    // value case (total = 0)
    int table[total + 1][m];
     
    // Fill the enteries for 0
    // value case (total = 0)
    for (i = 0; i < m; i++)
        table[0][i] = 0;
 
    // Fill rest of the table entries
    // in bottom up manner
    for (i = 1; i <= total ; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including coins[j]
            x = (i >=coins[j]) ? table[i - coins[j]][j] : 0;
 
            // Count of solutions excluding coins[j]
            y = (j >= 1) ? table[i][j - 1] : 0;
 
            // total count
            table[i][j] = x + y;
        }
    }
    return table[total][m - 1];
}

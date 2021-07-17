/**
 *
 * Given two strings how many minimum edits(update, delete or add) is needed to convert one string to another
 *
 * Time complexity is O(l1*l2)
 * Space complexity is O(l1*l2)
 *
 * References:
 * http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
 * https://en.wikipedia.org/wiki/Edit_distance
 * Video explanation https://www.youtube.com/watch?v=We3YDTzNXEk&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=6
 */
// Utility function to find the minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }
 
int editDistDP(string str1, string str2, int l1, int l2)
{
    // Create a table to store results of subproblems
    int dp[l1 + 1][l2 + 1];
 
    // Fill d[][] in bottom up manner
    for (int i = 0; i <= l1; i++) {
        for (int j = 0; j <= l2; j++) {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j
 
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
 
            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j]
                    = 1
                      + min(dp[i][j - 1], // Insert
                            dp[i - 1][j], // Remove
                            dp[i - 1][j - 1]); // Replace
        }
    }
 
    return dp[l1][l2];
}

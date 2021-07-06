Question link: https://www.codingninjas.com/codestudio/problems/friends-pairing-problem_1214625

int numberOfWays(int N)
{
	// Base Conditions
	if (N == 1 || N == 2)
	{
		return N;
	}

	// For storing answers to the subproblems
	vector<int> dp(N + 1);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	int mod = 1e9 + 7;

	// Iterating and calculating for every value of i = 3 to N
	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + (1LL * (i - 1) * (dp[i - 2] % mod)) % mod) % mod;
	}

	return dp[N];


}

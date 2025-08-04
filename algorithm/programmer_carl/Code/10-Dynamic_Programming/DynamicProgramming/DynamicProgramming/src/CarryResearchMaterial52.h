#pragma once

#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	int n, v;
	std::cin >> n >> v;
	std::vector<int> weights(n);
	std::vector<int> values(n);
	for (int i = 0; i < n; i++)
		std::cin >> weights[i] >> values[i];

	std::vector<int> dp(v + 1, 0);

	for (int i = 0; i < n; i++)
		for (int j = 1; j <= v; j++)
		{
			if (j >= weights[i])
				dp[j] = std::max(dp[j], dp[j - weights[i]] + values[i]);
		}

	std::cout << dp[v] << std::endl;
}


int main()
{
	int n, v;
	std::cin >> n >> v;
	std::vector<int> weights(n);
	std::vector<int> values(n);
	for (int i = 0; i < n; i++)
		std::cin >> weights[i] >> values[i];

	std::vector<std::vector<int>> dp(n, std::vector<int>(v + 1, 0));
	for (int i = 0; i <= v; i++)
	{
		if (i >= weights[0])
			dp[0][i] = dp[0][i - weights[0]] + values[0];
	}

	for (int i = 1; i < n; i++)
		for (int j = 1; j <= v; j++)
		{
			if (j < weights[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - weights[i]] + values[i]);
		}

	std::cout << dp[n - 1][v] << std::endl;
}

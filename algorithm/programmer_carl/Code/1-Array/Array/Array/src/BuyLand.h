#pragma once


//#include <iostream>
//#include <vector>
//#include <numeric>

//int main()
//{
//	int n, m;
//	scanf_s("%d%d", &n, &m);
//
//	std::vector<int> rowSum;
//	std::vector<int> rowPreSum;
//	rowSum.resize(n);
//	rowPreSum.resize(n);
//	std::vector<int> colSum;
//	std::vector<int> colPreSum;
//	colSum.resize(m);
//	colPreSum.resize(m);
//
//	std::vector<std::vector<int>> nums;
//	nums.resize(n);
//	int num;
//	int sum = 0;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			scanf_s("%d", &num);
//			nums[i].push_back(num);
//			rowSum[i] += num;
//			colSum[j] += num;
//			sum += num;
//		}
//	}
//
//
//	rowPreSum[0] = rowSum[0];
//	for (int i = 1; i < n; i++)
//		rowPreSum[i] = rowPreSum[i - 1] + rowSum[i];
//	colPreSum[0] = colSum[0];
//	for (int i = 1; i < m; i++)
//		colPreSum[i] = colPreSum[i - 1] + colSum[i];
//
//	for (int i = 0; i < n; i++)
//		std::cout << "rowPreSum[i]" << rowPreSum[i] << std::endl;
//	for (int i = 0; i < m; i++)
//		std::cout << "colPreSum[i]" << colPreSum[i] << std::endl;
//
//
//	int result = INT32_MAX;
//	for (int i = 1; i < n; i++)
//	{
//		int diff = std::abs(rowPreSum[i - 1] - (rowPreSum[n - 1] - rowPreSum[i - 1]));
//		result = result < diff ? result : diff;
//	}
//	for (int i = 1; i < m; i++)
//	{
//		int diff = std::abs(colPreSum[i - 1] - (colPreSum[m - 1] - colPreSum[i - 1]));
//		result = result < diff ? result : diff;
//	}
//	printf("%d", result);
//}
#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <unordered_set>


// BFS
//int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//void BFS(int x, int y, std::vector<std::vector<int>>& grid,
//	std::vector<std::vector<int>>& mark, int curIslandIndex, int& curArea)
//{
//	std::queue<std::pair<int, int>> queue;
//	queue.push({ x, y });
//
//	while (!queue.empty())
//	{
//		std::pair<int, int> curPos = queue.front();
//		queue.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nextX = curPos.first + dir[i][0];
//			int nextY = curPos.second + dir[i][1];
//
//			if (nextX < 0 || nextX > grid.size() - 1 || nextY < 0 || nextY > grid[0].size() - 1
//				|| grid[nextX][nextY] == 0)
//				continue;
//
//			curArea += 1;
//			grid[nextX][nextY] = 0;
//			mark[nextX][nextY] = curIslandIndex;
//			queue.push({ nextX, nextY });
//		}
//	}
//}
//
//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	std::vector<std::vector<int>> grid(N, std::vector<int>(M, 0));
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			std::cin >> grid[i][j];
//
//	std::vector<int> islandAreas;
//	std::vector<std::vector<int>> mark(N, std::vector<int>(M, -1));
//	int curArea = 0;
//	int curIslandIndex = 0;
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (grid[i][j] == 0)
//				continue;
//
//			curArea = 1;
//			grid[i][j] = 0;
//			mark[i][j] = curIslandIndex;
//			BFS(i, j, grid, mark, curIslandIndex, curArea);
//			islandAreas.push_back(curArea);
//			curIslandIndex += 1;
//		}
//	}
//
//	int result = 0;
//	if (!islandAreas.empty())
//	{
//		auto maxIt = std::max_element(islandAreas.begin(), islandAreas.end());
//		result = *maxIt;
//	}
//
//	int newIslandArea = 0;
//	std::unordered_set<int> newIslandMarks;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//		{
//			if (mark[i][j] == -1)
//			{
//				newIslandArea = 1;
//				newIslandMarks.clear();
//
//				for (int k = 0; k < 4; k++)
//				{
//					int nextX = i + dir[k][0];
//					int nextY = j + dir[k][1];
//					if (nextX < 0 || nextX > N - 1 || nextY < 0 || nextY > M - 1
//						|| mark[nextX][nextY] == -1)
//						continue;
//
//					newIslandMarks.insert(mark[nextX][nextY]);
//				}
//
//				for (int areaMark : newIslandMarks)
//					newIslandArea += islandAreas[areaMark];
//
//				result = std::max(result, newIslandArea);
//			}
//		}
//
//	std::cout << result << std::endl;
//}


// DFS
//int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//void DFS(int x, int y, std::vector<std::vector<int>>& grid,
//	std::vector<std::vector<int>>& mark, int curIslandIndex, int& curArea)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		int nextX = x + dir[i][0];
//		int nextY = y + dir[i][1];
//
//		if (nextX < 0 || nextX > grid.size() - 1 || nextY < 0 || nextY > grid[0].size() - 1
//			|| grid[nextX][nextY] == 0)
//			continue;
//
//		curArea += 1;
//		grid[nextX][nextY] = 0;
//		mark[nextX][nextY] = curIslandIndex;
//		DFS(nextX, nextY, grid, mark, curIslandIndex, curArea);
//	}
//}
//
//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	std::vector<std::vector<int>> grid(N, std::vector<int>(M, 0));
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			std::cin >> grid[i][j];
//
//	std::vector<int> islandAreas;
//	std::vector<std::vector<int>> mark(N, std::vector<int>(M, -1));
//	int curArea = 0;
//	int curIslandIndex = 0;
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (grid[i][j] == 0)
//				continue;
//
//			curArea = 1;
//			grid[i][j] = 0;
//			mark[i][j] = curIslandIndex;
//			DFS(i, j, grid, mark, curIslandIndex, curArea);
//			islandAreas.push_back(curArea);
//			curIslandIndex += 1;
//		}
//	}
//
//	int result = 0;
//	if (!islandAreas.empty())
//	{
//		auto maxIt = std::max_element(islandAreas.begin(), islandAreas.end());
//		result = *maxIt;
//	}
//
//	int newIslandArea = 0;
//	std::unordered_set<int> newIslandMarks;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//		{
//			if (mark[i][j] == -1)
//			{
//				newIslandArea = 1;
//				newIslandMarks.clear();
//
//				for (int k = 0; k < 4; k++)
//				{
//					int nextX = i + dir[k][0];
//					int nextY = j + dir[k][1];
//					if (nextX < 0 || nextX > N - 1 || nextY < 0 || nextY > M - 1
//						|| mark[nextX][nextY] == -1)
//						continue;
//
//					newIslandMarks.insert(mark[nextX][nextY]);
//				}
//
//				for (int areaMark : newIslandMarks)
//					newIslandArea += islandAreas[areaMark];
//
//				result = std::max(result, newIslandArea);
//			}
//		}
//
//	std::cout << result << std::endl;
//}

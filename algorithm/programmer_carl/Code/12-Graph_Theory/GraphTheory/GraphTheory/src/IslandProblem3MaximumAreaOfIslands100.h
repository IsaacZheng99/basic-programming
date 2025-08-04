#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

// BFS
//int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//void BFS(int x, int y, std::vector<std::vector<int>>& grid,
//	std::vector<std::vector<bool>>& visited, int& curArea)
//{
//	std::queue<std::pair<int, int>> queue;
//	queue.push({ x, y });
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
//			if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()
//				|| grid[nextX][nextY] == 0 || visited[nextX][nextY] == true)
//				continue;
//
//			visited[nextX][nextY] = true;
//			curArea += 1;
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
//	int result = 0;
//	int curArea = 0;
//	std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//		{
//			if (grid[i][j] == 0 || visited[i][j] == true)
//				continue;
//
//			visited[i][j] = true;
//			curArea = 1;
//			BFS(i, j, grid, visited, curArea);
//			result = std::max(result, curArea);
//		}
//
//	std::cout << result << std::endl;
//}


// DFS
//int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//void DFS(std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited,
//	int x, int y, int& curArea, int& result)
//{
//	curArea += 1;
//
//	for (int i = 0; i < 4; i++)
//	{
//		int nextX = x + dir[i][0];
//		int nextY = y + dir[i][1];
//		if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()
//			|| grid[nextX][nextY] == 0 || visited[nextX][nextY] == true)
//			continue;
//
//		visited[nextX][nextY] = true;
//		DFS(grid, visited, nextX, nextY, curArea, result);
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
//	int result = 0;
//	int curArea = 0;
//	std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//		{
//			if (grid[i][j] == 0 || visited[i][j] == true)
//				continue;
//
//			curArea = 0;
//			visited[i][j] = true;
//			DFS(grid, visited, i, j, curArea, result);
//			result = std::max(result, curArea);
//		}
//
//	std::cout << result << std::endl;
//}

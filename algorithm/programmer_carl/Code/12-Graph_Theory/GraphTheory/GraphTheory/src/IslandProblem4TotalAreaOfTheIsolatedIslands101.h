#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>


// BFS
//int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//void BFS(int x, int y, std::vector<std::vector<int>>& grid)
//{
//	grid[x][y] = 0;
//
//	std::queue<std::pair<int, int>> queue;
//	queue.push({ x, y });
//
//	while (!queue.empty())
//	{
//		std::pair<int, int> curPos = queue.front();
//		queue.pop();
//
//		int curX = curPos.first;
//		int curY = curPos.second;
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nextX = curX + dir[i][0];
//			int nextY = curY + dir[i][1];
//
//			if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()
//				|| grid[nextX][nextY] == 0)
//				continue;
//
//			grid[nextX][nextY] = 0;
//			queue.push({ nextX, nextY });
//		}
//
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
//
//	for (int i = 0; i < N; i++)
//	{
//		if (grid[i][0] == 1)
//			BFS(i, 0, grid);
//
//		if (grid[i][M - 1] == 1)
//			BFS(i, M - 1, grid);
//	}
//
//
//	for (int j = 0; j < M; j++)
//	{
//		if (grid[0][j] == 1)
//			BFS(0, j, grid);
//
//		if (grid[N - 1][j] == 1)
//			BFS(N - 1, j, grid);
//	}
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//		{
//			if (grid[i][j] == 1)
//				result += 1;
//		}
//
//	std::cout << result << std::endl;
//}


// DFS
//int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//void DFS(int x, int y, std::vector<std::vector<int>>& grid)
//{
//	grid[x][y] = 0;
//
//	for (int i = 0; i < 4; i++)
//	{
//		int nextX = x + dir[i][0];
//		int nextY = y + dir[i][1];
//
//		if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()
//			|| grid[nextX][nextY] == 0)
//			continue;
//
//		grid[nextX][nextY] = 0;
//		DFS(nextX, nextY, grid);
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
//
//	for (int i = 0; i < N; i++)
//	{
//		if (grid[i][0] == 1)
//			DFS(i, 0, grid);
//
//		if (grid[i][M - 1] == 1)
//			DFS(i, M - 1, grid);
//	}
//
//
//	for (int j = 0; j < M; j++)
//	{
//		if (grid[0][j] == 1)
//			DFS(0, j, grid);
//
//		if (grid[N - 1][j] == 1)
//			DFS(N - 1, j, grid);
//	}
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//		{
//			if (grid[i][j] == 1)
//				result += 1;
//		}
//
//	std::cout << result << std::endl;
//}


// BFS
//int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//void BFS(int x, int y, std::vector<std::vector<int>>& grid,
//	std::vector<std::vector<bool>>& visited, int& curArea)
//{
//	std::queue<std::pair<int, int>> queue;
//	queue.push({ x, y });
//	curArea += 1;
//
//	while (!queue.empty())
//	{
//		std::pair<int, int> curPos = queue.front();
//		queue.pop();
//
//		int curX = curPos.first;
//		int curY = curPos.second;
//
//		if (curArea == -1 || curX == 0 || curX == grid.size() - 1 || curY == 0 || curY == grid[0].size() - 1)
//			curArea = -1;
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nextX = curX + dir[i][0];
//			int nextY = curY + dir[i][1];
//
//			if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()
//				|| grid[nextX][nextY] == 0 || visited[nextX][nextY] == true)
//				continue;
//
//			visited[nextX][nextY] = true;
//			if (curArea != -1)
//				curArea += 1;
//			queue.push({ nextX, nextY });
//		}
//
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
//			curArea = 0;
//			BFS(i, j, grid, visited, curArea);
//			if (curArea != -1)
//				result += curArea;
//		}
//
//	std::cout << result << std::endl;
//}


// DFS
//int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//void DFS(int x, int y, std::vector<std::vector<int>>& grid,
//	std::vector<std::vector<bool>>& visited, int& curArea)
//{
//	if (curArea == -1 || x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size() - 1)
//		curArea = -1;
//	else
//		curArea += 1;
//
//	for (int i = 0; i < 4; i++)
//	{
//		int nextX = x + dir[i][0];
//		int nextY = y + dir[i][1];
//
//		if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()
//			|| grid[nextX][nextY] == 0 || visited[nextX][nextY] == true)
//			continue;
//
//		visited[nextX][nextY] = true;
//		DFS(nextX, nextY, grid, visited, curArea);
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
//			curArea = 0;
//			DFS(i, j, grid, visited, curArea);
//			if (curArea != -1)
//				result += curArea;
//		}
//
//	std::cout << result << std::endl;
//}

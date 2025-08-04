#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <stack>


//int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//void DFS(int x, int y,
//	std::vector<std::vector<int>>& matrix,
//	std::vector<std::vector<bool>>& visited)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		int nextX = x + dir[i][0];
//		int nextY = y + dir[i][1];
//		if (nextX < 0 || nextX >= matrix.size() || nextY < 0 || nextY >= matrix[0].size()
//			|| matrix[nextX][nextY] == 0 || visited[nextX][nextY] == true)
//			continue;
//
//		visited[nextX][nextY] = true;
//		DFS(nextX, nextY, matrix, visited);
//	}
//}
//
//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	std::vector<std::vector<int>> matrix(N, std::vector<int>(M, 0));
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			std::cin >> matrix[i][j];
//
//	std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
//	std::stack<std::pair<int, int>> stack;
//	int result = 0;
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//		{
//			if (matrix[i][j] == 0 || visited[i][j] == true)
//				continue;
//
//			result += 1;
//			visited[i][j] = true;
//			DFS(i, j, matrix, visited);
//		}
//
//	std::cout << result << std::endl;
//}


int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> matrix(N, std::vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			std::cin >> matrix[i][j];

	int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
	std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
	std::stack<std::pair<int, int>> stack;
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (matrix[i][j] == 0 || visited[i][j] == true)
				continue;

			result += 1;

			visited[i][j] = true;
			stack.push({ i, j });
			while (!stack.empty())
			{
				std::pair<int, int> cur = stack.top();
				stack.pop();

				for (int i = 0; i < 4; i++)
				{
					int nextX = cur.first + dir[i][0];
					int nextY = cur.second + dir[i][1];
					if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M
						|| matrix[nextX][nextY] == 0 || visited[nextX][nextY] == true)
						continue;

					stack.push({ nextX, nextY });
					visited[nextX][nextY] = true;
				}
			}
		}
	}

	std::cout << result << std::endl;
}

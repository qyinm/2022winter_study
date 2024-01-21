#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int new_map[30][30];
int visited[30][30];
int house_cnt[300] = { 0, };

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void dfs(int x, int y, int v, int size) {
	visited[y][x] = 1;
	house_cnt[v]++;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
		if (visited[ny][nx] || !new_map[ny][nx])	continue;


		dfs(nx, ny, v, size);
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	int size;
	cin >> size;

	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			scanf("%1d", &new_map[i][j]);
		}
	}

	int v = 0;
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			if (visited[i][j] || !new_map[i][j]) continue;
			dfs(j, i, v, size);
			v++;
		}
	}

	sort(house_cnt, house_cnt + v );
	
	cout << v << "\n";
	for (int i = 0; i < v; i++) {
		cout << house_cnt[i] << "\n";
	}
}

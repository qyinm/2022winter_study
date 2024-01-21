#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int map[70][70];
int visited[70][70] = { 0, };

int n, m;
void showVisited() {
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (map[i][j] == 1)	cout << "*";
			else {

			cout << visited[i][j];
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	int r, c, d;
	int element;

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> element;
			map[i][j] = element;
		}
	}

	visited[r][c] = 1;

	
	showVisited();
	int stop = 0;
	while (stop == 0) {

		switch (d) {
		case 0:
			if (visited[r][c - 1] == 0 && map[r][c - 1] != 1) {
				d = 3;
				visited[r][c - 1] = 1;
				c = c - 1;
				break;
			}
			if (visited[r + 1][c] == 0 && map[r + 1][c] != 1) {
				d = 2;
				visited[r + 1][c] = 1;
				r = r + 1;
				break;
			}
			if (visited[r][c + 1] == 0 && map[r][c + 1] != 1) {
				d = 1;
				visited[r][c + 1] = 1;
				c = c + 1;
				break;
			}
			if (visited[r - 1][c] == 0 && map[r - 1][c] != 1) {
				d = 0;
				visited[r - 1][c] = 1;
				r = r - 1;
				break;
			}

			if (map[r + 1][c] == 1) {
				stop++;
				break;
			}
			d = 0;
			r = r + 1;
			break;
			
		case 1:
			if (visited[r - 1][c] == 0 && map[r - 1][c] != 1) {
				d = 0;
				visited[r - 1][c] = 1;
				r = r - 1;
				break;
			}
			if (visited[r][c - 1] == 0 && map[r][c - 1] != 1) {
				d = 3;
				visited[r][c - 1] = 1;
				c = c - 1;
				break;
			}
			if (visited[r + 1][c] == 0 && map[r + 1][c] != 1) {
				d = 2;
				visited[r + 1][c] = 1;
				r = r + 1;
				break;
			}
			if (visited[r][c + 1] == 0 && map[r][c + 1] != 1) {
				d = 1;
				visited[r][c + 1] = 1;
				c = c + 1;
				break;
			}

			if (map[r][c - 1] == 1) {
				stop++;
				break;
			}
			d = 1;
			c = c - 1;
			break;

		case 2:
			if (visited[r][c + 1] == 0 && map[r][c + 1] != 1) {
				d = 1;
				visited[r][c + 1] = 1;
				c = c + 1;
				break;
			}
			if (visited[r - 1][c] == 0 && map[r - 1][c] != 1) {
				d = 0;
				visited[r - 1][c] = 1;
				r = r - 1;
				break;
			}
			if (visited[r][c - 1] == 0 && map[r][c - 1] != 1) {
				d = 3;
				visited[r][c - 1] = 1;
				c = c - 1;
				break;
			}
			if (visited[r + 1][c] == 0 && map[r + 1][c] != 1) {
				d = 2;
				visited[r + 1][c] = 1;
				r = r + 1;
				break;
			}

			if (map[r - 1][c] == 1) {
				stop++;
				break;
			}
			d = 2;
			r = r - 1;
			break;

		case 3:
			if (visited[r + 1][c] == 0 && map[r + 1][c] != 1) {
				d = 2;
				visited[r + 1][c] = 1;
				r = r + 1;
				break;
			}
			if (visited[r][c + 1] == 0 && map[r][c + 1] != 1) {
				d = 1;
				visited[r][c + 1] = 1;
				c = c + 1;
				break;
			}
			if (visited[r - 1][c] == 0 && map[r - 1][c] != 1) {
				d = 0;
				visited[r - 1][c] = 1;
				r = r - 1;
				break;
			}
			if (visited[r][c - 1] == 0 && map[r][c - 1] != 1) {
				d = 3;
				visited[r][c - 1] = 1;
				c = c - 1;
				break;
			}

			if (map[r][c + 1] == 1) {
				stop++;
				break;
			}
			d = 3;
			c = c + 1;
			break;

		}
		showVisited();
	}

	int result = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (visited[i][j] == 1) result++;
		}
	}

	cout << result;
}

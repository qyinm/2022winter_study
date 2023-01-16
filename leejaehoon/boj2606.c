##define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int vertex;
	struct node* link;
};

int cnt;

//그래프 연결
void connect(int vi, int vj, struct node** graph) {
	struct node* from = (struct node*)malloc(sizeof(struct node));
	struct node* to = (struct node*)malloc(sizeof(struct node));
	
	from->vertex = vj;
	from->link = graph[vi]->link;
	graph[vi]->link = from;

	to->vertex = vi;
	to->link = graph[vj]->link;
	graph[vj]->link = to;
}

void dfs(int v, int* visited, struct node** graph) {
	struct node* w;
	visited[v] = 1;
	printf("%-5d", v);
	for (w = graph[v];w;w = w->link)
		if (!visited[w->vertex]) {
			dfs(w->vertex, visited, graph);
			cnt++;
		}

}

int main() {
	int com, line;
	scanf_s("%d", &com);
	scanf_s("%d", &line);

	int* visited = (int*)malloc(com * sizeof(int));
	//포인터를 가리키는 포인터(배열)
	struct node* graph = (struct node**)malloc(com * sizeof(struct node*));


	int vi, vj;
	for (int i = 0;i < line;i++) {
		scanf_s("%d %d", &vi, &vj);
		connect(vi, vj, graph);
		printf("connect 성공\n");
	}
	printf("양방향 연결\n");
	
	dfs(1, visited, graph);
}define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int vertex;
	struct node* link;
};

int cnt;

//그래프 연결
void connect(int vi, int vj, struct node** graph) {
	struct node* from = (struct node*)malloc(sizeof(struct node));
	struct node* to = (struct node*)malloc(sizeof(struct node));
	
	from->vertex = vj;
	from->link = graph[vi]->link;
	graph[vi]->link = from;

	to->vertex = vi;
	to->link = graph[vj]->link;
	graph[vj]->link = to;
}

void dfs(int v, int* visited, struct node** graph) {
	struct node* w;
	visited[v] = 1;
	printf("%-5d", v);
	for (w = graph[v];w;w = w->link)
		if (!visited[w->vertex]) {
			dfs(w->vertex, visited, graph);
			cnt++;
		}

}

int main() {
	int com, line;
	scanf_s("%d", &com);
	scanf_s("%d", &line);

	int* visited = (int*)malloc(com * sizeof(int));
	//포인터를 가리키는 포인터(배열)
	struct node* graph = (struct node**)malloc(com * sizeof(struct node*));


	int vi, vj;
	for (int i = 0;i < line;i++) {
		scanf_s("%d %d", &vi, &vj);
		connect(vi, vj, graph);
		printf("connect 성공\n");
	}
	printf("양방향 연결\n");
	
	dfs(1, visited, graph);
}

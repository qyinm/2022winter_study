#include <stdio.h>
#include <stdlib.h>

int virus;

int Dfs(int v, int n, int** A,int* V ) {
    int seek;
    V[v] = 1;
    virus++;

    for (int i = 1; i <= n; i++)
    {
        if (A[v][i] == 1)
        {
            seek = i;

            if (V[seek] == 0 )
            {
                Dfs(seek,n,A,V);
            }
        }
    }
}

int main() {
    int node;
    int line;
    int x,y;
    scanf("%d", &node);
    scanf("%d",&line);

    int** arr = (int**)malloc(sizeof(int*) * (node+1));

    int* visited = (int*) malloc(sizeof (int)*(node+1));

    for (int i = 0; i < node+1; i++) {
        arr[i] = (int*)malloc(sizeof(int) * (node+1));
    }

    for (int i = 0; i < node+1; i++) {
        for (int j = 0; j < node+1; j++) {
            arr[i][j] = 0;
        }
    }

    for(int i = 1; i<=line; i++){
        scanf("%d %d",&x, &y);
        arr[x][y]=1;
        arr[y][x]=1;
    }



    Dfs(1,node,arr,visited);

    printf("%d",virus-1);



    for (int i = 0; i < node+1; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;


}


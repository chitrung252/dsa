#include <iostream>

using namespace std;

const int MAX = 5;

struct Vertex {
    char label;
    bool visited;
};

int stack[MAX];
int top = -1;

struct Vertex *lstVertices[MAX];

int adjMatrix[MAX][MAX];

int vertexCount = 0;

void push(int label) {
    stack[++top] = label;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

bool isStackEmpty() {
    return top == -1;
}

void addVertex(char label) {
    Vertex *vertex = (struct Vertex *)malloc(sizeof(Vertex));
    vertex->label = label;
    vertex->visited = false;
    lstVertices[vertexCount++] = vertex;
}

void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

// hien thi dinh
void displayVertex(int vertexIndex) {
    cout << lstVertices[vertexIndex]->label << " ";
}

int getAdjUnvisitedVertex(int vertexIndex) {
    int i;

    for (i = 0; i < vertexCount; i++) {
        if (adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
            return i;
        }
    }

    return -1;
}

void dfs() {
    lstVertices[0]->visited = true;
    displayVertex(0);

    push(0);

    while (!isStackEmpty()) {
        int topStack = peek();
        int unvisitedVertex = getAdjUnvisitedVertex(topStack);
        if (unvisitedVertex == -1) {
            pop();
        } else {
            lstVertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);

            push(unvisitedVertex);
        }
    }

    for (int i = 0; i < vertexCount; i++) {
        lstVertices[i]->visited = false;
    }
}

int main() {
    int i, j;

    for (i = 0; i < MAX; i++) {   // thiet lap cac gia tri
        for (j = 0; j < MAX; j++) // cua ma tran ke la 0
            adjMatrix[i][j] = 0;
    }

    addVertex('S');
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');

    addEdge(0, 1); // S -> A
    addEdge(0, 2); // S -> B
    addEdge(0, 3); // S -> C
    addEdge(1, 4); // A -> D

    dfs();

    return 0;
}
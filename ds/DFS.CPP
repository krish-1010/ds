#include <iostream.h>
#include <conio.h>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void dfs(int startVertex);
    void printVertices();

private:
    int vertices;
    int **adjacencyMatrix; // Use a matrix for adjacency representation
};

Graph::Graph(int vertices) {
    this->vertices = vertices;

    // Allocate memory for the adjacency matrix
    adjacencyMatrix = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjacencyMatrix[i] = new int[vertices];
        for (int j = 0; j < vertices; ++j)
            adjacencyMatrix[i][j] = 0;
    }
}

void Graph::addEdge(int v, int w) {
    adjacencyMatrix[v][w] = 1;
    adjacencyMatrix[w][v] = 1; // Assuming an undirected graph
}

void Graph::dfs(int startVertex) {
    int *stack = new int[vertices];
    int top = -1;

    int *visited = new int[vertices];
    for (int i = 0; i < vertices; ++i)
        visited[i] = 0;

    stack[++top] = startVertex;
    visited[startVertex] = 1;

    while (top != -1) {
        int currentVertex = stack[top--];
        cout << currentVertex << " ";

        for (int i = vertices - 1; i >= 0; --i) {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }

    delete[] visited;
    delete[] stack;
}

void Graph::printVertices() {
    cout << "Vertices and their neighbors:\n";
    for (int i = 0; i < vertices; ++i) {
        cout << i << ": ";
        for (int j = 0; j < vertices; ++j) {
            if (adjacencyMatrix[i][j] == 1)
                cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    clrscr();

    // Example usage
    Graph g(6);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    // Print vertices
    g.printVertices();

    cout << "\nDFS starting from vertex 0: ";
    g.dfs(0);

    getch();
    return 0;
}

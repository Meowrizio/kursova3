#include iostream
#include vector
#include queue
#include climits

using namespace std;

const int INF = INT_MAX;
const int MAX_V = 1000;

struct Edge {
    int to, capacity, reverseEdge;
};

vectorvectorEdge graph(MAX_V);
vectorint parent(MAX_V);

void addEdge(int u, int v, int cap) {
    Edge forward = { v, cap, static_castint(graph[v].size()) };
    Edge backward = { u, 0, static_castint(graph[u].size()) };
    graph[u].emplace_back(forward);
    graph[v].emplace_back(backward);
}

bool findAugmentingPath(int source, int sink) {
    fill(parent.begin(), parent.end(), -1);
    queuepairint, int q;
    q.push({ source, INF });

    while (!q.empty()) {
        int current = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (const Edge& edge  graph[current]) {
            int to = edge.to;
            if (parent[to] == -1 && edge.capacity  0) {
                int new_flow = min(flow, edge.capacity);
                parent[to] = edge.reverseEdge;
                if (to == sink) {
                    return true;
                }
                q.push({ to, new_flow });
            }
        }
    }

    return false;
}

int fordFulkerson(int source, int sink) {
    int maxFlow = 0;
    while (findAugmentingPath(source, sink)) {
        int pathFlow = INF;
        for (int v = sink; v != source; v = graph[v][parent[v]].to) {
            int u = graph[v][parent[v]].to;
            pathFlow = min(pathFlow, graph[u][graph[v][parent[v]].reverseEdge].capacity);
        }

        for (int v = sink; v != source; v = graph[v][parent[v]].to) {
            int u = graph[v][parent[v]].to;
            graph[u][graph[v][parent[v]].reverseEdge].capacity -= pathFlow;
            graph[v][parent[v]].capacity += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int numOfVertices, numOfEdges, sourceVertex, sinkVertex;
    cout  Vvdite kolichestvo vershin, reber, vershin-istochnikov i vershin-stokov ;
    cin  numOfVertices  numOfEdges  sourceVertex  sinkVertex;

    for (int i = 0; i  numOfEdges; ++i) {
        int u, v, cap;
        cout  Vhodnaya gran ;
        cin  u  v  cap;
        addEdge(u, v, cap);
    }

    int maxFlow = fordFulkerson(sourceVertex, sinkVertex);
    cout  maximalniy rashod   maxFlow  endl;

    return 0;
}

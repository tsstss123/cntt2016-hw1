#include <algorithm>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

static const int INF = 0x3f3f3f3f;

class FlowGraph {
  public:
    int n = 0;
    int s = -1;
    int t = -1;
    std::vector<std::vector<std::tuple<int, int, int>>> edge;

    FlowGraph() { }
    FlowGraph(int n_, int s_, int t_) : n(n_), s(s_), t(t_), edge(n) { }

    void addEdge(int x, int y, int w);
    int maxFlow();

  private:
    std::vector<int> dist;
    std::vector<int> curedge;

    void BFSDist();
    int DFSFlow(int x, int pre);
};

void FlowGraph::addEdge(int x, int y, int w)
{
    int idx = edge[x].size();
    int idy = edge[y].size();
    edge[x].push_back(std::make_tuple(y, w, idy));
    edge[y].push_back(std::make_tuple(x, 0, idx));
}

int FlowGraph::maxFlow()
{
    dist.resize(n);
    curedge.resize(n);
    int flow = 0;
    while (true) {
        BFSDist();
        if (dist[s] == INF) {
            break;
        }
        std::fill(curedge.begin(), curedge.end(), 0);
        flow += DFSFlow(s, INF);
    }
    return flow;
}

void FlowGraph::BFSDist()
{
    std::queue<int> que;
    que.push(t);
    std::fill(dist.begin(), dist.end(), INF);
    dist[t] = 0;
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        for (auto e : edge[x]) {
            int y = std::get<0>(e);
            if (dist[y] == INF && std::get<1>(edge[y][std::get<2>(e)])) {
                dist[y] = dist[x] + 1;
                que.push(y);
            }
        }
    }
}

int FlowGraph::DFSFlow(int x, int pre)
{
    if (x == t) {
        return pre;
    }
    int sum = 0;
    for (int &i = curedge[x]; i < (int)edge[x].size(); i++) {
        auto &e = edge[x][i];
        int y = std::get<0>(e);
        int w = std::get<1>(e);
        if (w && dist[x] == dist[y] + 1) {
            int u = std::min(pre, w);
            int v = DFSFlow(y, u);
            sum += v;
            pre -= v;
            std::get<1>(e) -= v;
            std::get<1>(edge[y][std::get<2>(e)]) += v;
            if (!pre) {
                break;
            }
        }
    }
    return sum;
}

class TheTilesDivOne {
  public:
    int find(std::vector<std::string> board);
};

int TheTilesDivOne::find(std::vector<std::string> board)
{
    static const int DIRS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int n = board.size();
    int m = board[0].length();
    FlowGraph g(2 * n * m + 2, 2 * n * m, 2 * n * m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '.') {
                if (i % 2 == 0 && j % 2 == 1) {
                    g.addEdge(g.s, i * m + j, 1);
                    for (int k = 0; k < 4; k++) {
                        int x = i + DIRS[k][0];
                        int y = j + DIRS[k][1];
                        if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == '.') {
                            // Cell (i, j) can match with cell (x, y)
                            g.addEdge(i * m + j, x * m + y, 1);
                        }
                    }
                } else if (i % 2 == 1 && j % 2 == 0) {
                    g.addEdge(i * m + j, g.t, 1);
                    for (int k = 0; k < 4; k++) {
                        int x = i + DIRS[k][0];
                        int y = j + DIRS[k][1];
                        if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == '.') {
                            // Cell (i, j) can match with cell (x, y)
                            g.addEdge(x * m + y + n * m, i * m + j, 1);
                        }
                    }
                } else {
                    // Black cell
                    g.addEdge(i * m + j, i * m + j + n * m, 1);
                }
            }
        }
    }
    return g.maxFlow();
}

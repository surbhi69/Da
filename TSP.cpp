#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

#define INF 999

class Graph {
    int w[20][20], n;
    string city[20];
    vector<int> bestPath;
    int min_cost = INT_MAX;

public:
    void initialize() {
        cout << "Enter number of cities:\n";
        cin >> n;
        cout << "Enter city names:\n";
        for (int i = 0; i < n; i++) cin >> city[i];
        
        cout << "Enter weighted matrix:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cout << "Enter distance between " << city[i] << " and " << city[j] << " (999 if none): ";
                cin >> w[i][j];
                if (i == j) w[i][j] = 0;
            }
    }

    void TSP() {
        vector<int> currPath = {0};
        bool visited[20] = {false};
        visited[0] = true;
        tspRecursive(0, visited, 1, 0, currPath);
        
        cout << "Minimum cost: " << min_cost << "\nPath: ";
        for (int i : bestPath) cout << city[i] << " -> ";
        cout << city[0] << endl;
    }

private:
    int reduceMatrix(int matrix[20][20], bool isRow) {
        int reductionCost = 0;
        for (int i = 0; i < n; i++) {
            int minVal = INF;
            for (int j = 0; j < n; j++) 
                minVal = min(minVal, isRow ? matrix[i][j] : matrix[j][i]);
            
            if (minVal != INF && minVal != 0) {
                reductionCost += minVal;
                for (int j = 0; j < n; j++) 
                    if (isRow) matrix[i][j] -= minVal;
                    else matrix[j][i] -= minVal;
            }
        }
        return reductionCost;
    }

    void tspRecursive(int pos, bool visited[], int count, int cost, vector<int>& path) {
        if (count == n) {
            int totalCost = cost + w[pos][0];
            if (totalCost < min_cost) {
                min_cost = totalCost;
                bestPath = path;
            }
            return;
        }

        int tempMatrix[20][20];
        copy(&w[0][0], &w[0][0] + 20 * 20, &tempMatrix[0][0]);
        for (int i = 0; i < n; i++) if (visited[i]) for (int j = 0; j < n; j++) tempMatrix[i][j] = INF;

        int lowerBound = cost + reduceMatrix(tempMatrix, true) + reduceMatrix(tempMatrix, false);
        if (lowerBound >= min_cost) return;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && w[pos][i] != INF) {
                visited[i] = true;
                path.push_back(i);
                tspRecursive(i, visited, count + 1, cost + w[pos][i], path);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
};

int main() {
    Graph g;
    g.initialize();
    g.TSP();
    return 0;
}

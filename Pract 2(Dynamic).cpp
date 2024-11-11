#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& profits, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nDP Table (Matrix Form):" << endl;
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            cout << dp[i][w] << "\t";
        }
        cout << endl;
    }

    int maxProfit = dp[n][W];
    int w = W;
    vector<int> fraction(n, 0);

    for (int i = n; i > 0 && maxProfit > 0; i--) {
        if (maxProfit != dp[i - 1][w]) {
            fraction[i - 1] = 1;
            maxProfit -= profits[i - 1];
            w -= weights[i - 1];
        }
    }

    cout << "\nFraction of each item used:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": " << fraction[i] << endl;
    }

    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the capacity of knapsack: ";
    cin >> W;

    vector<int> profits(n);
    vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter profit and weight of item " << i + 1 << ": ";
        cin >> profits[i] >> weights[i];
    }

    int maxProfit = knapsack(W, weights, profits, n);
    cout << "\nMaximum Profit: " << maxProfit << endl;

    return 0;
}

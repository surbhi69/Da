#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int profit, weight;
    double ratio;
};

bool compare(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

int main() {
    int capacity, n;
    cout << "Enter knapsack capacity and number of items: ";
    cin >> capacity >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> items[i].profit >> items[i].weight;
        items[i].ratio = double(items[i].profit) / items[i].weight;
    }

    sort(items.begin(), items.end(), compare);

    double maxProfit = 0.0;
    vector<double> fractions(n, 0.0);

    for (int i = 0; i < n && capacity > 0; ++i) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            maxProfit += items[i].profit;
            fractions[i] = 1.0;
        } else {
            fractions[i] = double(capacity) / items[i].weight;
            maxProfit += items[i].profit * fractions[i];
            break;
        }
    }

    cout << "\nMax Profit: " << maxProfit << "\nFractions of items used:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << ": " << fractions[i] << "\n";
    }

    return 0;
}

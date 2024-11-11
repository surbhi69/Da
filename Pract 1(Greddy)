#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int profit;
    int weight;
    double fraction;
    int index; // To track original index for output
};

// Function to compare items by their profit/weight ratio
bool compare(Item a, Item b) {
    return a.fraction > b.fraction;
}

int main() {
    int w, n;

    cout << "Enter the capacity of knapsack (weight): ";
    cin >> w;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<Item> items(n);
    vector<double> value(n, 0.0); // Initialize value array to 0 for fractions

    for (int i = 0; i < n; i++) {
        cout << "Enter Profit and Weight for item " << i + 1 << ":\n";
        cin >> items[i].profit >> items[i].weight;
        items[i].fraction = double(items[i].profit) / double(items[i].weight);
        items[i].index = i;
    }

    // Sort items by profit-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);

    double maxProfit = 0.0;

    for (int i = 0; i < n; i++) {
        if (w >= items[i].weight) {
            w -= items[i].weight;
            maxProfit += items[i].profit;
            value[items[i].index] = 1.0; // Full item taken
        } else {
            // Take a fraction of the item
            maxProfit += items[i].profit * ((double) w / items[i].weight);
            value[items[i].index] = (double) w / items[i].weight;
            w = 0; // Knapsack is now full
            break;
        }
    }

    // Output results
    cout << "\nMax Profit: " << maxProfit << "\n";
    cout << "Fraction of each item used:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": " << value[i] << "\n";
    }

    return 0;
}

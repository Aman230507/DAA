//AMIT RAJ 25/DA/013
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Item {
    int id;
    double weight;
    double value;
    double ratio;
};

double fractionalKnapsack(vector<Item>& items, double capacity) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
    });

    double totalValue = 0.0;
    double remaining = capacity;

    cout << "Item selection order (by value/weight ratio):" << endl;

    for (auto& item : items) {
        if (remaining <= 0)
            break;

        if (item.weight <= remaining) {
            remaining -= item.weight;
            totalValue += item.value;

            cout << " Item " << item.id << ": took 100% "
                 << "(weight=" << item.weight
                 << ", value=" << item.value << ")" << endl;
        } else {
            double fraction = remaining / item.weight;
            totalValue += item.value * fraction;

            cout << " Item " << item.id << ": took "
                 << fixed << setprecision(1)
                 << (fraction * 100) << "% "
                 << "(weight=" << item.weight
                 << ", value=" << item.value << ")" << endl;

            remaining = 0;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = {
        {1, 10, 60, 0},
        {2, 20, 100, 0},
        {3, 30, 120, 0}
    };

    for (auto& it : items)
        it.ratio = it.value / it.weight;

    double capacity = 50;

    cout << "===== Fractional Knapsack (Greedy) =====" << endl << endl;

    cout << "Items (id, weight, value, value/weight ratio):" << endl;

    for (auto& it : items)
        cout << " Item " << it.id
             << ": weight=" << it.weight
             << ", value=" << it.value
             << ", ratio=" << fixed << setprecision(2)
             << it.ratio << endl;

    cout << endl;
    cout << "Knapsack capacity: " << capacity << endl << endl;

    double maxValue = fractionalKnapsack(items, capacity);

    cout << endl << "Maximum value obtainable: "
         << fixed << setprecision(2)
         << maxValue << endl;

    return 0;
}
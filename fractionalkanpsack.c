#include <stdio.h>

// Function to swap two elements
void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
}

// Function to sort items by their value-to-weight ratio
void sortByRatio(double value[], double weight[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio1 = value[i] / weight[i];
            double ratio2 = value[j] / weight[j];
            if (ratio1 < ratio2) {
                swap(&value[i], &value[j]);
                swap(&weight[i], &weight[j]);
            }
        }
    }
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int W, double value[], double weight[], int n) {
    sortByRatio(value, weight, n);  // Sort items by value/weight ratio

    double totalValue = 0.0;        // Total value accumulated in knapsack
    int currentWeight = 0;          // Current weight in the knapsack

    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= W) {
            // If adding the whole item, take it completely
            currentWeight += weight[i];
            totalValue += value[i];
        } else {
            // If the whole item can't be added, take fraction of it
            int remainingWeight = W - currentWeight;
            totalValue += value[i] * (remainingWeight / weight[i]);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, W;

    // Input number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    double value[n], weight[n];

    // Input the weights and values of the items
    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%lf", &weight[i]);
        printf("Item %d - Value: ", i + 1);
        scanf("%lf", &value[i]);
    }

    // Input the capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    // Get the maximum value that can be carried
    double maxValue = fractionalKnapsack(W, value, weight, n);

    // Output the result
    printf("Maximum value in Knapsack = %.2lf\n", maxValue);

    return 0;
}

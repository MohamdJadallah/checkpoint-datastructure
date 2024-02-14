//problem 1

#include <iostream>
using namespace std;

int sum_of_distinct_elements(int set1[], int set1_size, int set2[], int set2_size) {
    int sum = 0;

    // Compare elements of set1 with set2 and add to sum if not present in set2
    for (int i = 0; i < set1_size; ++i) {
        bool found = false;
        for (int j = 0; j < set2_size; ++j) {
            if (set1[i] == set2[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            sum += set1[i];
        }
    }

    // Compare elements of set2 with set1 and add to sum if not present in set1
    for (int i = 0; i < set2_size; ++i) {
        bool found = false;
        for (int j = 0; j < set1_size; ++j) {
            if (set2[i] == set1[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            sum += set2[i];
        }
    }

    return sum;
}

int main() {
    int set1[] = {3, 1, 7, 9};
    int set1_size = sizeof(set1) / sizeof(set1[0]);
    int set2[] = {2, 4, 1, 9, 3};
    int set2_size = sizeof(set2) / sizeof(set2[0]);

    cout << "Output: " << sum_of_distinct_elements(set1, set1_size, set2, set2_size) << endl;

    return 0;
}


//problem 2





#include <iostream>
#include <cmath>
using namespace std;

// Procedure to calculate dot product of two vectors
double dot_product(const double v1[], const double v2[], int size) {
    double result = 0;
    for (int i = 0; i < size; ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

// Function to check if two vectors are orthogonal
bool are_orthogonal(const double v1[], const double v2[], int size) {
    return (dot_product(v1, v2, size) == 0);
}

int main() {
    const int num_pairs = 3; // Number of pairs of vectors
    const int size = 3; // Size of each vector

    double vectors[num_pairs][size] = {
        {1, 0, 0},
        {0, 1, 0},
        {1, 1, 0}
    };

    // Check orthogonality of each pair of vectors
    for (int i = 0; i < num_pairs; ++i) {
        for (int j = i + 1; j < num_pairs; ++j) {
            bool orthogonal = are_orthogonal(vectors[i], vectors[j], size);
            cout << "Vectors (" << i+1 << ") and (" << j+1 << ") are ";
            cout << (orthogonal ? "orthogonal" : "not orthogonal") << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Query {
    int l, r, idx;
};

bool compare(const Query& q1, const Query& q2) {
    int sqrtN = sqrt(8); // Ajustar según el tamaño del arreglo
    int block1 = q1.l / sqrtN;
    int block2 = q2.l / sqrtN;
    if (block1 == block2)
        return q1.r < q2.r;
    return block1 < block2;
}

vector<int> moAlgorithm(const vector<int>& arr, vector<Query>& queries) {
    int n = arr.size();
    int q = queries.size();
    vector<int> results(q);

    sort(queries.begin(), queries.end(), compare);

    int currentL = 0, currentR = -1, currentSum = 0;

    for (const auto& query : queries) {
        int l = query.l, r = query.r;

        while (currentR < r) currentSum += arr[++currentR];
        while (currentR > r) currentSum -= arr[currentR--];
        while (currentL < l) currentSum -= arr[currentL++];
        while (currentL > l) currentSum += arr[--currentL];

        results[query.idx] = currentSum;
    }

    return results;
}

int main() {
    vector<int> arr = {1, 3, 4, 8, 6, 1, 4, 2};
    vector<Query> queries = {{0, 4, 0}, {1, 3, 1}, {2, 5, 2}};
    vector<int> results = moAlgorithm(arr, queries);

    for (int res : results)
        cout << res << endl;

    return 0;
}

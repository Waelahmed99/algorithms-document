#include "algorithms.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define print(text) (std::cout << text)
#define get(x) (std::cin >> x)
#define ll long long

std::vector<int> vec;

void getArray() {
    int size;
    print("Enter array size: ");
    get(size);

    vec.clear();
    print("Enter array elements:\n");
    for(int i = 0, entry; i < size && get(entry); i++)
        vec.push_back(entry);
}

void printArray() {
    for (int i : vec)
        std::cout << i << " ";
}

void selectionSort() {
    getArray();

    int minPos, size = vec.size();
    for (int i = 0; i < size - 1; i++) {
            minPos = i;
        for (int j = i+1; j < size; j++)
            if (vec[j] < vec[minPos])
                minPos = j;
        std::swap(vec[minPos], vec[i]);
        std::cout << " | swap " << vec[minPos] << " with " << vec[i] << std::endl;
        printArray();
    }
}

void bubbleSort() {
    getArray();

    int size = vec.size();
    for (int i = 0; i < (size - 1); i++)
        for (int j = 0; j <  (size - i - 1); j++)
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
                std::cout << " | swap " << vec[j] << " with " << vec[j + 1] << std::endl;
                printArray();
            }
}

void insertionSort() {
    getArray();

    int size = vec.size(), j;
    for (int i = 1, j; i < size; i++)
    {
        int iVal = i, prevI = vec[i];
        bool swapped = false;
        for (j = i - 1; j >= 0 && vec[j] > vec[i]; j--)
            std::swap(vec[i], vec[j]), i--, swapped = true;
        if (swapped) std::cout << " | moving " << prevI << " after " << vec[j] << std::endl;
        i = iVal;
        printArray();
        print("\n");
    }
}

int partition(int low, int high) {
    int pivot = vec[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (vec[j] < pivot) {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[high]);
    return i + 1;
}

void performQuick(int low, int high) {
    if (low < high) {
        int pivot = partition(low, high);
        performQuick(low, pivot - 1);
        performQuick(pivot + 1, high);
    }
}

void quickSort() {
    getArray();

    print("Can't explain that here :c\n");
    performQuick(0, vec.size() - 1);
    printArray();
}

string getString(string str, int start, int end) {
    string res = "";
    for (int i = start; i < start+end; i++)
        res += str[i];
    return res;
}

void patternMatching() {
    string str, pattern;
    print("Enter first string: "), get(str);
    print("Enter pattern: "), get(pattern);

    int pattern_length = pattern.size();
    int str_length = str.size();
    bool found = false;
    for (int i = 0; i <= (str_length - pattern_length); i++) {
        string checker = getString(str, i, pattern_length);
        if (checker == pattern) {
            found = true;
            cout << "Pattern found at: " << i + 1<< endl;
        }
    }
    if (!found) print("No pattern found in this string\n");
}

void sequentialSearch() {
    getArray();

    int val;
    bool found = false;
    print("Enter value you want to search for: "), get(val);
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] == val) {
            found = true;
            cout << "Value found at position: " << i + 1 << endl;
            break;
        }
    if (!found)
        print("No result");
}

struct Node
{
    int data;
    struct Node* left, *right;
    Node() {
        left = right = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

void postorder(struct Node* node)
{
    if (node == nullptr)
        return;
    // L R V
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void inorder(struct Node* node)
{
    if (node == nullptr)
        return;
    // L V R
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void preorder(struct Node* node)
{
    if (node == nullptr)
        return;
    // V L R
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void tree() {
    print("Tree insertion not yet implemented\nPreorder,Inorder,Postorder functions are implemented in aglorithms.cpp");
}

#define SIZE 9

void shortestPath() {
    // Sample graph.
    int graph[SIZE][SIZE] = {{0, 4,  0, 0,  0,  0,  0, 8,  0},
                             {4, 0,  8, 0,  0,  0,  0, 11, 0},
                             {0, 8,  0, 7,  0,  4,  0, 0,  2},
                             {0, 0,  7, 0,  9,  14, 0, 0,  0},
                             {0, 0,  0, 9,  0,  10, 0, 0,  0},
                             {0, 0,  4, 14, 10, 0,  2, 0,  0},
                             {0, 0,  0, 0,  0,  2,  0, 1,  6},
                             {8, 11, 0, 0,  0,  0,  1, 0,  7},
                             {0, 0,  2, 0,  0,  0,  6, 7,  0}};

    print("\n");
    ll cost[SIZE + 5][SIZE + 5];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << graph[i][j] << setw(5);
            if (i == j) {  // No cost from travelling to the same place.
                cost[i][j] = 0;
            }
            else {
                if (graph[i][j] == 0) // If there is no path from i to j make it maximum value.
                    cost[i][j] = 1e15;
                else    // if there is a path from i to j, assign its cost.
                    cost[i][j] = graph[i][j];
            }
        }
        cout << "\n";
    }

    int start = 0, end = SIZE - 1;
    print("\nKindly from [0 to 8]\n");
    print("Enter the point you want to start from: "), get(start);
    print("Enter the point you want to travel to: "), get(end);

    if (start < 0 || start > 8) start = 0;
    if (end < 0 || end > 8) end = SIZE - 1;
    // Check path from i to j, and path from [i to k] then [k to j].
    for (int k = 0; k < SIZE; ++k)
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

    print("Shortest distance between every node:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            if (cost[i][j] == 1e15)
                cout << "INF" << setw(5);
            else
                cout << cost[i][j] << setw(5);
        cout << endl;
    }

    cout << "\nShortest path cost: " << cost[start][end] << endl;
    print("\nPlease see Graph sample in algorithms.cpp\n");
}


//
//void shortestPath() {
//    // Sample graph.
//    int graph[SIZE][SIZE] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
//                              { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
//                              { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
//                              { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
//                              { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
//                              { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
//                              { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
//                              { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
//                              { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
//    vector<vector<pair<int, int>>> adjList(SIZE + 5);
//    for (int i = 0; i < SIZE; i++) {
//        for (int j = 0; j < SIZE; j++) {
//            cout << graph[i][j] << " ";
//            if (graph[i][j] == 0)
//                continue;
//            adjList[i].push_back({j, graph[i][j]});
//        }
//        cout << endl;
//    }
//
//    ll cost[SIZE + 5];
//    int parent[SIZE + 5];
//    for (int i = 0; i <= SIZE; i++)
//        cost[i] = 1e15, parent[i] = -1;
//
//    int start = 2, end = 5;
//    cost[start] = 0;
//    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
//    pq.push({0, start});
//    while (pq.size()) {
//        int node = pq.top().second;
//        pq.pop();
//        for (auto next : adjList[node]) {
//            ll nxtCost = cost[node] + next.second;
//            if (nxtCost < cost[next.first]) {
//                cost[next.first] = nxtCost;
//                pq.push({nxtCost, next.first});
//                parent[next.first] = node;
//            }
//        }
//    }
//    cout << cost[end] << '\n';
//    vector<int> path;
//    int curr = end;
//    while (curr != start) {
//        path.push_back(curr);
//        curr = parent[curr];
//    }
//    path.push_back(start);
//    reverse(path.begin(), path.end());
//    for (auto &x : path)
//        cout << x << ' ';
//    cout << '\n';
//    print("\nPlease see Graph sample in algorithms.cpp\n");
//}
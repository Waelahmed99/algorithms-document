#include "algorithms.h"
#include <iostream>
#include <bits/stdc++.h>

#define print(text) (std::cout << text)
#define get(x) (std::cin >> x)

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

void quickSort() {
    getArray();
}

void patternMatching() {

}

void sequentialSearch() {

}

void tree() {

}

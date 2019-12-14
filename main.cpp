#include <iostream>
#include "algorithms.h"

#define print(text) (cout << (text))  // easier cout.

using namespace std;

void mainScreen() {
    print("Welcome to my Algorithms document\n");
    print("please choose algorithm nubmer to try it\n\n");
    print("1.Selection sort\n");
    print("2.Bubble sort\n");
    print("3.Insertion sort\n");
    print("4.Quick sort\n");
    print("5.Pattern matching\n");
    print("6.Sequential search\n");
    print("7.Tree algorithms\n");
    print("8.Exit program\n");
}

int main() {
    mainScreen();
    int ch;
    do {
        cin >> ch;
        switch (ch) {
            case 1:
                selectionSort();
                break;
            case 2:
                bubbleSort();
                break;
            case 3:
                insertionSort();
                break;
            case 4:
                quickSort();
                break;
            case 5:
                patternMatching();
                break;
            case 6:
                sequentialSearch();
                break;
            case 7:
                tree();
                break;
            case 8:
                exit(0);
                break;
            default:
                mainScreen();
                break;
        }
    } while (true);
}

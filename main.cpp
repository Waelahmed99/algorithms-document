#include <iostream>
#include "algorithms.h"

#define print(text) (cout << (text))  // easier cout.

using namespace std;

void mainScreen() {
    print("\n\n************************************");
    print("\nWelcome to my Algorithms document\n");
    print("please choose algorithm nubmer to try it\n\n");
    print("1.Selection sort\n");
    print("2.Bubble sort\n");
    print("3.Insertion sort\n");
    print("4.Quick sort\n");
    print("5.Pattern matching\n");
    print("6.Sequential search\n");
    print("7.Tree algorithms\n");
    print("8.Shortest path (FloydWarshal)\n");
    print("9.Exit program\n");
}

int main() {
    mainScreen();
    int ch;
    do {
        cin >> ch;
        switch (ch) {
            case 1:
                selectionSort();
                mainScreen();
                break;
            case 2:
                bubbleSort();
                mainScreen();
                break;
            case 3:
                insertionSort();
                mainScreen();
                break;
            case 4:
                quickSort();
                mainScreen();
                break;
            case 5:
                patternMatching();
                mainScreen();
                break;
            case 6:
                sequentialSearch();
                mainScreen();
                break;
            case 7:
                tree();
                mainScreen();
                break;
            case 8:
                shortestPath();
                mainScreen();
                break;
            case 9:
                print("Thank you! :)");
                exit(0);
                break;
            default:
                mainScreen();
                break;
        }
    } while (true);
}

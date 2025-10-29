//
// Created by Justin Nguyen on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        // (note that data is our minheap)
        if (size >= 64) return; // full

        data[size] = idx; // Insert the given index at the end of the heap array (data[size])
        // Increment the heap size
        size++;
        // Restore the min-heap property by calling upheap() using weightArr[] for comparisons
        upheap(size - 1, weightArr);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        if (size == 0) return -1;  // heap is empty
        int index = data[0]; //root value
        data[0] = data[size - 1]; // get the element at the bottom of the heap and replace root with it
        size--; // get rid of last element by shrinking heap
        if (size > 0) { //dont want to downheap at 0 size or we downheap nothing
            downheap(0, weightArr);
        } //restore minheap, start at root b/c just replaced it

        // Replace root with last element, then call downheap()
        return index;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        if (pos == 0) {
            return; //cannot access negative index
        }
        //recursive implementation
        //  int parent = (pos - 1) / 2;
        // if (weightArr[data[pos]] < weightArr[data[parent]]) { // this means our element is
        //     //smaller than parent
        //     // before swap: parent <-- above pos
        //     swap(data[pos], data[parent]);
        //     // now: pos <-- above parent
        //     upheap(parent, weightArr); //keep moving up if not at top yet
        // }

        while (pos > 0) {
            int parent = (pos - 1) / 2;
            //smaller than parent
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                swap(data[pos], data[parent]);
                pos = parent;
            }
            else {
                return; // break loop
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        // int left = 2 * pos + 1;
        // int right = 2 * pos + 2;
        // int min = pos; // start smallest at our position index
        // // left < size and right < size ensure our child nodes exists
        // if (left < size && weightArr[data[left]] < weightArr[data[min]]) {
        //     min = left;
        // }
        // if (right < size && weightArr[data[right]] < weightArr[data[min]]) {
        //     min = right;
        // }
        // // this means we did not move min or we are in the right spot
        // if (min != pos) {
        //     swap(data[pos], data[min]);
        //     downheap(min, weightArr);
        // }
        while (true) {
            // same format as recursive
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int min = pos;
            if (left < size && weightArr[data[left]] < weightArr[data[min]]) {
                min = left;
            }
            if (right < size && weightArr[data[right]] < weightArr[data[min]]) {
                min = right;
            }
            if (min != pos) {
                swap(data[min], data[pos]);
                pos = min; // just need this so we actually move down tree for more operations
            }
            else {
                return; // exit
            }
        }
    }
};

#endif
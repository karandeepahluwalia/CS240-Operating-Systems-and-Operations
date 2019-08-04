right#include <iostream>
#include "MinHeap.h"

using namespace std;


Heap::Heap(){
     size = 0;
}
Heap::~Heap(){
}
void Heap::heapDown(int root, int last){
  int max;
  int right;
  int left;
  Pair temp;

  left = root * 2 + 1;          // Get index of root's left child
  right = root * 2 + 2;          // Get index of root's right child

     // Check base case in recursive calls.  If left's index is less
     // than or equal to the bottom index we have not finished recursively
     // reheaping.
  if(left <= last){
    if(left == last)          // If this root has no right child then
    {
      max = left;     //     left must hold max key
    }else{     // Get the one lowest in the tree (highest index in the array)
      if(head[left] <= head[right]){
        max = right;
      }else{
        max = left;
      }
    }
    if(head[root] < head[max])
    {
          // Swap these two elements
      temp = head[root];
      head[root] = head[max];
      head[max] = temp;
      // Make recursive call till reheaping completed
      heapDown(max, bottom);
    }
  }
}
void Heap::heapUp(int root, int last){
  int parent;
  Pair temp;
  if (last>root){
    parent = (last-1)/2;
    if(head[parent]<head[last]){
      temp = head[parent];
      head[parent] = head[last];
      head[last] = temp;
      heapUp(root, parent);
    }
  }
}
bool Heap::push(Pair newNode){
  if(size<head.size()){
  head[size] = newNode;
  }else{
  head.push_back(newNode);
  }
  heapUp(0,size);
  size++;
  return true;
}
bool Heap::push(int data, int costs){
  Pair temp = Pair(data,costs);
  return push(temp);
}
Pair Heap::pop(){
  Pair temp = head[0];
  size--;
  head[0] = head[size];
  heapDown(0,size-1);
  if(size = 0){
    return NULL;
  }else{
    return temp;
  }
}
bool Heap::isEmpty(){
  return size==0;
}

//
// Created by amucz0 on 9/22/24.
//

#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <list>
#include <unordered_map>
using namespace std;

typedef struct Node{
    int key;
    int value;
} Node;

class LRUCache {
private:
    list<Node> list;
    unordered_map<int, Node*> ptrs;
    int size;

public:
    LRUCache();
    explicit LRUCache(int maxSize);

    Node* getLRU();
    Node* get(int key);
    void put(int key, int value);
    void remove(int key);
};


#endif //LRUCACHE_H

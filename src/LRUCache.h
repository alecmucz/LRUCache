//
// Created by amucz0 on 9/22/24.
//

#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    list<int> data;
    unordered_map<int, int> ptrs;
    int size;

public:
    LRUCache();
    explicit LRUCache(int maxSize);

    int getLRU();
    int get(int key);
    void put(int key, int value);
    void remove(int key);
};


#endif //LRUCACHE_H

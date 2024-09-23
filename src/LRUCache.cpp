//
// Created by amucz0 on 9/22/24.
//
#include "LRUCache.h"
#include <iostream>
using namespace std;

LRUCache::LRUCache() {
    size = 0;
}

LRUCache::LRUCache(const int maxSize) {
    size = maxSize;
}

Node* LRUCache::getLRU() {
    return nullptr;
}

Node* LRUCache::get(const int key) {
    if(auto const element = ptrs.find(key); element != ptrs.end()) {
        return element->second;
    }
    std::cout << "Item Does Not Exist" << endl;
    return nullptr;
}

void LRUCache::put(const int key,const int value) {
    if(ptrs.find(key) != ptrs.end()) {
        //TO-DO: Delete Node
    }
    cacheList.push_front(Node{key,value});
    ptrs[key] = &(*cacheList.begin());

}

void LRUCache::remove(const int key) {

}


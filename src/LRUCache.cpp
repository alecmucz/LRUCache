//
// Created by amucz0 on 9/22/24.
//
#include "LRUCache.h"
#include <iostream>
using namespace std;

LRUCache::LRUCache(const int maxSize) {
    this->size = maxSize;
}

int LRUCache::getLRU() {
    cacheList.splice(cacheList.begin(),cacheList,cacheList.end());
    return ptrs[1]->value;
}

int LRUCache::get(const int key) {
    if(auto const element = ptrs.find(key); element != ptrs.end()) {
        cacheList.splice(cacheList.begin(),cacheList,element->second);
        return element->second->value;
    }
    return -1;
}

void LRUCache::put(const int key,const int value) {
    if(auto const element = ptrs.find(key); element != ptrs.end()) {
        element->second->value = value;
        cacheList.splice(cacheList.begin(),cacheList,element->second);
    } else {
        if(cacheList.size() >= size) {
            Node elem = cacheList.back();
            cacheList.pop_back();
            ptrs.erase(elem.key);
        }
        cacheList.push_front(Node{key,value});
        ptrs[key] = cacheList.begin();
    }
}

void LRUCache::remove(const int key) {
    if (ptrs.find(key) != ptrs.end()) {
        cacheList.erase(ptrs[key]);
        ptrs.erase(key);
    }
}


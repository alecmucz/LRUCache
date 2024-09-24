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
    const int temp = ptrs.end()->second->value;
    //To-Do: Move back element to the front

    return temp;
}

int LRUCache::get(const int key) {
    if(auto const element = ptrs.find(key); element != ptrs.end()) {
        cacheList.splice(cacheList.begin(),cacheList,element->second);
        return element->second->value;
    }
    return -1;
}

void LRUCache::put(const int key,const int value) {
    auto const element = ptrs.find(key);
    if(element != ptrs.end()) {
        element->second->value = value;
        cacheList.splice(cacheList.begin(),cacheList,element->second);
    } else {
        if(cacheList.size() >= size) {
            auto element = cacheList.back();
            cacheList.pop_back();
            ptrs.erase(element.key);
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


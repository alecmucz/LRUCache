//
// Created by amucz0 on 9/22/24.
//
#include "LRUCache.h"
#include <iostream>
using namespace std;

LRUCache::LRUCache() {
    this->size = 0;
}

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
        // To-Do: Fix this monstrocity using splice
        cacheList.erase(element->second);
        ptrs.erase(element->first);
        cacheList.push_front(Node{key,element->second->value});
        ptrs.insert(key, element->second->value);
        return element->second->value;
    }
    std::cout << "Item Does Not Exist" << endl;
    return -1;
}

void LRUCache::put(const int key,const int value) {
    if(ptrs.find(key) != ptrs.end()) {
        //TO-DO: Delete Node
        const auto it = ptrs[key];
        cacheList.erase(ptrs[key]);
    }
    cacheList.push_front(Node{key,value});
    //ptrs[key] = &(*cacheList.begin());

}

void LRUCache::remove(const int key) {
    if (ptrs.find(key) != ptrs.end()) {
        cacheList.erase(ptrs[key]);
        ptrs.erase(key);
    }
}


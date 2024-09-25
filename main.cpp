#include <iostream>
#include "src/LRUCache.h"

int main() {
    LRUCache cache (10);

    cache.put(1,100);
    cache.put(2,200);
    cache.put(3,300);
    cache.put(4,400);
    cache.put(5,500);
    cache.put(6,100);
    cache.put(7,200);
    cache.put(8,300);
    cache.put(9,400);
    cache.put(10,500);

    for (int i = 0; i < 10; ++i) {
        cout << cache.get(i) << "\n";
    }
        cout << cache.getLRU() << "\n";
    return 0;
}

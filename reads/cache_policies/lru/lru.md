# LRU cache

Design and implement a data structure for Least recently used cache. It should
support the following operations: `get` and `put`.

- `get(key)`: Get the value (will always be possitive) of the key if the key
exists in the cache, otherwise return -1.
- `put(key, value)`: set or inset the value if the key is nor already present.
When the cache reached its capacity, it should invalidate the least recently
used item before inserting a new item.

### Note

Could both operations be implemented in `O(1)` time complexity?

### eg:

```cpp
UCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
```

/*
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (19.03%)
 * Total Accepted:    154.6K
 * Total Submissions: 812.4K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * 
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * LRUCache cache = new LRUCache( 2 /* capacity */ );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 */
class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) touch(it); //如果所插入的元素已经在used链表中，调整该元素的位置，将其放在链表头部。
        else { //如果这个元素没在used也就是cache中
			if (cache.size() == _capacity) { //如果cache已经满了就删除used 链表中的最后一个元素，和cache中该元素所对应的pair。
				cache.erase(used.back());
				used.pop_back();
			}
            used.push_front(key); //如果没有满就将该元素插入到链表的最前端
        }
        cache[key] = { value, used.begin() }; //将该元素的pair 存入到cache中
    }
    
private:
    typedef list<int> LI; // 缓存的物理存储。
    typedef pair<int, LI::iterator> PII; //缓存中的元素，及指向该元素所在链表中位置的指针。
    typedef unordered_map<int, PII> HIPII; //
    
    void touch(HIPII::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();//每一次被访问，就将该元素放到used链表前并更新HIPII的指针。
    }
    
    HIPII cache;
    LI used;
    int _capacity;
};

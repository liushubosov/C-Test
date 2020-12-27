/*
* 706. 设计哈希映射
*
不使用任何内建的哈希表库设计一个哈希映射

具体地说，你的设计应该包含以下的功能

put(key, value)：向哈希映射中插入(键,值)的数值对。如果键对应的值已经存在，更新这个值。
get(key)：返回给定的键所对应的值，如果映射中不包含这个键，返回-1。
remove(key)：如果映射中存在这个键，删除这个数值对。


示例：
    MyHashMap hashMap = new MyHashMap();
    hashMap.put(1, 1);          
    hashMap.put(2, 2);         
    hashMap.get(1);            // 返回 1
    hashMap.get(3);            // 返回 -1 (未找到)
    hashMap.put(2, 1);         // 更新已有的值
    hashMap.get(2);            // 返回 1 
    hashMap.remove(2);         // 删除键为2的数据
    hashMap.get(2);            // 返回 -1 (未找到) 

注意：
    所有的值都在 [0, 1000000]的范围内。
    操作的总数目在[1, 10000]范围内。
    不要使用内建的哈希库。

* 
* 解题思路： 
*   与上一题705. 设计哈希集合类似。
*   使用除法散列，哈希冲突采用链表。总数目是10000，因此定一个 1000 左右的质数，这样即便碰撞，查找次数不算太多。
*/

class MyHashMap {
public:
    struct Node{
        Node* next;
        Node* prev;
        int key;
        int val;
        Node(int k, int v): prev(nullptr), next(nullptr), key(k), val(v){}
    };
    vector<Node*> myList;
    int m_nSize;
    /** Initialize your data structure here. */
    MyHashMap() {
        m_nSize = 1001;
        myList.resize(m_nSize);
    }

    ~MyHashMap() {
        for(Node* p : myList)
        {
            while(p)
            {
                Node* next = p->next;
                delete p;
                p = next;
            }
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int nPos = key % m_nSize;
        if(myList[nPos] == nullptr)
        {
            Node* p = new Node(key, value);
            myList[nPos] = p;
        }else
        {
            Node* p = myList[nPos];
            while(p){
                if(p->key == key)
                { 
                    p->val = value;
                    return;
                }
                p = p->next;
            }
            p = new Node(key, value);
            p->next = myList[nPos]->next;
            if(myList[nPos]->next)
                myList[nPos]->next->prev = p;
            myList[nPos]->next = p;
            p->prev = myList[nPos];
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int nPos = key % m_nSize;
        if(myList[nPos] == nullptr)
            return -1;
        Node* p = myList[nPos];
        while(p){
            if(p->key == key)
                return p->val;
            p = p->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int nPos = key % m_nSize;
        if(myList[nPos] == nullptr)
            return;
        Node* p = myList[nPos];
        while(p){
            if(p->key == key)
            {
                if(p->prev)
                    p->prev->next = p->next;
                else
                    myList[nPos] = p->next;
                if(p->next)
                    p->next->prev = p->prev;
                delete p;
                p = nullptr;
                return;
            }
            p = p->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
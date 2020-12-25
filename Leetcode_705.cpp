/*
* 705. 设计哈希集合
*
不使用任何内建的哈希表库设计一个哈希集合
具体地说，你的设计应该包含以下的功能

add(value)：向哈希集合中插入一个值。
contains(value) ：返回哈希集合中是否存在这个值。
remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。


示例：
    MyHashSet hashSet = new MyHashSet();
    hashSet.add(1);         
    hashSet.add(2);         
    hashSet.contains(1);    // 返回 true
    hashSet.contains(3);    // 返回 false (未找到)
    hashSet.add(2);          
    hashSet.contains(2);    // 返回 true
    hashSet.remove(2);          
    hashSet.contains(2);    // 返回  false (已经被删除)

注意：
    所有的值都在 [0, 1000000]的范围内。
    操作的总数目在[1, 10000]范围内。
    不要使用内建的哈希集合库。

* 
* 解题思路： 
*   使用除法散列，哈希冲突采用链表。总数目是10000，因此定一个 1000 左右的质数，这样即便碰撞，查找次数不算太多。
*/

class MyHashSet {
public:
    struct Node{
        Node* next;
        int val;
        Node(){
            next = nullptr;
        }
        Node(int a){
            next = nullptr;
            val = a;
        }
    };
    vector<Node*> myList;
    int m_nSize;
    /** Initialize your data structure here. */
    MyHashSet() {
        m_nSize = 1001;
         myList.resize(m_nSize);
    }

    ~MyHashSet() {
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
   
    void add(int key) {
        int nPos = key%m_nSize;
        if(myList[nPos] == nullptr){
            Node* p = new Node(key);
            myList[nPos] = p;
        }else
        {
            Node * p = myList[nPos];
            while(p)
            {
                if(p->val == key)
                    return;
                p = p->next;
            }
            p = new Node(key);
            p->next = myList[nPos]->next;
            myList[nPos]->next = p;
        }
    }
    
    void remove(int key) {
        int nPos = key%m_nSize;
        if(myList[nPos] == nullptr)
            return;
        Node * p = myList[nPos];
        Node* prev = nullptr;
        while(p)
        {
            if(p->val == key)
            {
                if(prev)
                    prev->next = p->next;
                else
                    myList[nPos] = p->next;
                delete p;
                p = nullptr;
                return;
            }
            prev = p;
            p = p->next;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int nPos = key%m_nSize;
        if(myList[nPos] == nullptr)
            return false;
        Node * p = myList[nPos];
        while(p)
        {
            if(p->val == key)
                return true;
            p = p->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


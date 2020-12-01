/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */
#include <iostream>
#include <unordered_map>

using namespace std;

// @lc code=start
class DoubleList{
public:
    DoubleList(){
        dummy_->next = tail_;
        tail_->prev = dummy_;
    }
    struct Node{
        Node* next;
        Node* prev;
        int key;
        int val;
        Node(): next(nullptr), prev(nullptr), key(-1), val(-1){}
        Node(int k, int v) : next(nullptr), prev(nullptr), key(k), val(v){}
    };

    void Remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        size_--;
    }

    void PushBack(Node* node){
        auto end = tail_->prev;
        end->next = node; 
        node->prev = end;
        node->next = tail_;
        tail_->prev = node;
        size_++;
    }

    int RemoveFront(){
        if(dummy_->next != tail_){
            auto curr = dummy_->next;
            dummy_->next = curr->next;
            curr->next->prev = dummy_;
            int key = curr->key;
            delete curr;
            size_--;
            return key;
        }
        return -1;
    }

    int Size(){
        return size_;
    }

private:
    int size_ = 0;
    Node dummy_node_, tail_node_;
    Node *dummy_= &dummy_node_, *tail_ = &tail_node_;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        key_map_.reserve(capacity);
    }

    int get(int key) {
        if(key_map_.count(key) == 0){
            return -1;
        }
        auto node = key_map_[key];
        put(node->key, node->val);
        return node->val;
    }
    
    void put(int key, int value) {
        auto new_node = new DoubleList::Node(key, value);
        if(key_map_.count(key) == 0){
            if(val_queue_.Size() == capacity_){
                int key = val_queue_.RemoveFront();
                key_map_.erase(key);
            }
            key_map_.insert({key, new_node});
            val_queue_.PushBack(new_node);
        }
        else{
            auto node = key_map_[key];
            val_queue_.Remove(node);
            key_map_[key] = new_node;
            val_queue_.PushBack(new_node);
        }
    }

private:
    unordered_map<int, DoubleList::Node*> key_map_;
    DoubleList val_queue_;
    int capacity_ = -1;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main(int argc, char** argv){
    auto solution = new LRUCache(2);
    
    cout << "Example 1\n";
    solution->put(1,1);
    solution->put(2,2);
    cout << solution->get(1) << endl;
    solution->put(3,3);
    cout << solution->get(2) << endl;
    solution->put(4,4);
    cout << solution->get(1) << endl;
    cout << solution->get(3) << endl;
    cout << solution->get(4) << endl;
    return 0;
}

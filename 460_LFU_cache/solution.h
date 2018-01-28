//
// Created by wesley shi on 2018/1/19.
//

#ifndef INC_460_LFU_CACHE_SOLUTION_H
#define INC_460_LFU_CACHE_SOLUTION_H


#include <vector>
#include <map>
using namespace std;

struct pair{
    int key;
    int val;
    pair(){
        key = 0;
        val = 0;
    }
    pair(int k, int v){
        key = k;
        val = v;
    }
};

struct node{
    int key;
    int val;
    node* next = nullptr;
    node* pre = nullptr;
    void* fre = nullptr;

    node(int k, int v){
        key = k;
        val = v;
    }

};

struct freq{
    int f;
    node* head = nullptr;
    node* tail = nullptr;
    freq* pre = nullptr;
    freq* next = nullptr;
    freq(int fr){
        f = fr;
    }
};

class LFUCache{
public:
    int cap;
    map<int, node*> m;
    freq *head;

    LFUCache(int capacity) {
        cap = capacity;
        head = new freq(1);

    }

    int get(int key) {
        auto itr = m.find(key);
        if (itr == m.end()) return -1;
        node* knode = itr->second;
        freq* kfreq = (freq*)knode->fre;
        if (knode->pre != nullptr){
            knode->pre->next = knode->next;
        } else {
            kfreq->head = knode->next;
        }
        if (knode->next != nullptr){
            knode->next->pre = knode->pre;
        } else {
            kfreq->tail = knode->pre;
        }

        freq* fcur;
        if (kfreq->next == nullptr || kfreq->next->f != kfreq->f+1){
            // insert a new node
            fcur = new freq(kfreq->f+1);
            fcur->pre = kfreq;
            fcur->next = kfreq->next;
            if (fcur->next != nullptr) fcur->next->pre = fcur;
            kfreq->next = fcur;
        } else {
            fcur = kfreq->next;
        }

        // if kfreq is empty, delete it
        if (kfreq->head == nullptr){
            if (kfreq->pre != nullptr){
                kfreq->pre->next = kfreq->next;
            }
            if (kfreq->next != nullptr){
                kfreq->next->pre = kfreq->pre;
            }
            delete(kfreq);
        }

        knode->next = fcur->head;
        knode->pre = nullptr;
        knode->fre = fcur;
        fcur->head = knode;
        if (fcur->tail == nullptr) fcur->tail = knode;
        return knode->val;
    }

    void put(int key, int value) {
        if (m.size() == cap){

        }
        node* knode = new node(key, value);

    }
};


#endif //INC_460_LFU_CACHE_SOLUTION_H

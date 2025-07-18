// https://leetcode.com/problems/design-hashset/

#include <bits/stdc++.h>
using namespace std;

typedef struct MyListNode
{
    int val;
    MyListNode *next, *prev;
} MyListNode;

class MyHashSet
{
private:
    vector<MyListNode *> mpp;

public:
    MyHashSet()
    {
        mpp.resize(10);
        for (int i = 0; i < 10; i++)
            mpp[i] = newNode(-1);
    }

    MyListNode *newNode(int val)
    {
        MyListNode *node = new MyListNode();
        node->val = val;
        node->next = node->prev = NULL;
        return node;
    }

    void add(int key)
    {
        if(contains(key))   return;

        MyListNode *node = newNode(key);
        int idx = key % 10;
        MyListNode *itr = mpp[idx];


        if (!itr->next)
        {
            itr->next = node;
            node->prev = itr;
        }
        else
        {
            node->next = itr->next;
            node->prev = itr;
            itr->next->prev = node;
            itr->next = node;
        }
    }

    void remove(int key)
    {
        int idx = key % 10;
        MyListNode *itr = mpp[idx];

        while (itr && itr->val != key)
            itr = itr->next;

        if (itr)
        {
            itr->prev->next = itr->next;
            if (itr->next)
                itr->next->prev = itr->prev;
            delete itr;
        }
    }

    bool contains(int key)
    {
        int idx = key % 10;
        MyListNode *itr = mpp[idx];

        while (itr && itr->val != key)
            itr = itr->next;

        return (itr != NULL);
    }

    void printHashSet()
    {
        for(int i = 0; i <= 9; i++)
        {
            cout<<i<<": ";
            MyListNode *itr = mpp[i]->next;

            while(itr)
            {
                cout<<itr->val<<"->";
                itr = itr->next;
            }
            cout<<endl;
        }
    }
};


int main()
{
    MyHashSet st;

    st.add(1);
    st.add(2);

    cout<<st.contains(1)<<endl;
    cout<<st.contains(3)<<endl;
    
    st.add(2);
    cout<<st.contains(2)<<endl;
    
    st.remove(2);
    cout<<st.contains(2)<<endl;

    return 0;
}
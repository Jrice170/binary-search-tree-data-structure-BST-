#ifndef MYMAP_H
#define MYMAP_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include "Dictionary.h"
#include "TreeNode.h"

using std::cout;
using std::endl;

/*
Writes to a string array containing: 
    * the your (the student author’s) Campus Username in lowercase (at index 0)
    * and Student ID# (at index 1).
Takes as input a pre-existing length-2 string array.
*/
void get_identity(std::string my_id[]);
      

template <typename K, typename V>
class MyMap: public Dictionary<K, V>
{
    private:
        TreeNode<MyPair<K, V>> *root;

        V & at_helper(TreeNode<MyPair<K, V>> *&rt, const K &key);

        int size_helper(TreeNode<MyPair<K, V>> *rt) const;

        void clear_helper(TreeNode<MyPair<K, V>> *&rt);

        void insert_helper(TreeNode<MyPair<K, V>> *&rt, const MyPair<K, V> &init_pair);

        TreeNode<MyPair<K, V>> * get_min(TreeNode<MyPair<K, V>> *rt);

        void erase_helper(TreeNode<MyPair<K, V>> *&rt, const K &key);

        MyPair<K, V> * find_helper(TreeNode<MyPair<K, V>> *rt, const K &key) const;

        void print_helper(TreeNode<MyPair<K, V>> *rt, std::string indent) const;

        int count_helper(TreeNode<MyPair<K, V>> *rt, const K &key) const;

        TreeNode<MyPair<K, V>> * clone(const TreeNode<MyPair<K, V>> *rt);


    public:
        MyMap();

        ~MyMap();

        MyMap(const MyMap<K, V> &source);

        MyMap<K, V> & operator=(const MyMap<K, V> &source);

        V & at(const K &key);

        V & operator[](const K &key);

        bool empty() const;

        int size() const;

        void clear();

        void insert(const MyPair<K, V> &init_pair);

        void erase(const K &key);

        MyPair<K, V> * find(const K &key) const;

        void print() const;

        int count(const K &key) const;
};

#include "MyMap.hpp"

#endif


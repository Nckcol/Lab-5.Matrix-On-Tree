#pragma once

#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class Node
{
    vector<Node *> _children;
    Node * _parent;
    T * _data;
public:
    Node(Node * parent): _parent(parent), _data(nullptr){}

    Node(Node * parent, T * data) : _parent(parent), _data(data) {}

    Node(Node * parent, T * data, initializer_list<Node *> children) : _parent(parent), _data(data)
    {
        _children.insert(_children.begin(), children.begin(), children.end());
    }

    Node(Node * parent, T * data, int size) : _parent(parent), _data(data)
    {
        _children.resize(size);
    }

    Node * child(int i)
    {
        return _children[i];
    }

    void child(int i, Node * child)
    {
        if(i < _children.size())
            _children[i] = child;
    }

    void child(Node * child)
    {
        _children.push_back(child);
    }

    void data(T * data)
    {
        _data = data;
    }

    T * data()
    {
        return _data;
    }

};

template<typename T>
class Tree
{
    Node<T> * _root;
public:
    Tree()
    {

    }

    ~Tree()
    {

    }

    Node<T> * root()
    {
        return _root;
    }

    void root(Node<T> * node)
    {
        _root = node;
    }
};


template<typename T>
class TreeIterator
{

};


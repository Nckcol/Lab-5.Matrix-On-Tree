#pragma once
#include "Tree.h"

template<typename T>
class Row
{
    Node<T> * _node;
public:

    Row(Node<T> * node) : _node(node) {}

    T & operator[] (int n)
    {
        T * data = _node->child(n)->data();

        if (!data)
        {
            data = new T();
            _node->child(n)->data(data);
        }

        return *data;
    }
};

template<typename T>
class Matrix :
    public Tree<T>                                                   
{
    vector<Row<T> *> _rows;
public:
    Matrix(int sizeN, int sizeM)
    {
        root(new Node<T>(nullptr, nullptr, sizeN));
        _rows.resize(sizeM, nullptr);
        for (int i = 0; i < sizeN; i++)
        {
            root()->child(i, new Node<T>(root(), nullptr, sizeM));
            for (int j = 0; j < sizeM; j++)
                root()->child(i)->child(j, new Node<T>(root()->child(i), nullptr, 0));
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < _rows.size(); i++) 
            delete _rows[i];
    }

    Row<T> & operator[] (int n)
    {
        if (!_rows[n])
        {
             _rows[n] = new Row<T>(root()->child(n));
        }

        return *_rows[n];
    }
};


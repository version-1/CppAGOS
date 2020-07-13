//
//  Queue.hpp
//  Iterator
//
//  Created by Administlator on 2020/07/13.
//  Copyright © 2020 Administlator. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp


#include <stdio.h>
#include <vector>
#include "QueueIterator.hpp"

template <class T>
class Queue {
    int count = 0;
    std::vector<T> list;
public:
    void enque (T e);
    T deque ();
    T peek();
    bool isEmpty();
    QueueIterator<T> makeIterator();
};

#endif /* Queue_hpp */

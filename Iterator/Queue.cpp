//
//  Queue.cpp
//  Iterator
//
//  Created by Administlator on 2020/07/13.
//  Copyright © 2020 Administlator. All rights reserved.
//


#include <vector>
#include "Queue.hpp"

template <class T>
void Queue<T>::enque (T e) {
    count++;
    list.push_back(e);
}
template <class T>
T Queue<T>::deque () {
    if (isEmpty()) {
        return;
    }
    count--;
    Queue<T> *ele = list.begin();
    list = std::vector<T>(list.begin() + 1, list.end());
    return list.begin();
}

template <class T>
T Queue<T>::peek () {
    return list.begin();
}

template <class T>
bool Queue<T>::isEmpty () {
    return count == 0;
}

template <class T>
QueueIterator<T> Queue<T>::makeIterator() {
    if (isEmpty()) {
        return new QueueIterator<T>();
    }
    QueueIterator<T> head = new QueueIterator<T>();
    QueueIterator<T> iterator = head;
    for (int i = 0 ;i < list.size(); i++) {
        iterator.data = list.at(i);
        if (list.at(i+1)) {
            iterator.next = *list.at(i+1);
        }
        iterator = &iterator.next;
    }
    return head;
}

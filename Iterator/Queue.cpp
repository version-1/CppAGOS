//
//  Queue.cpp
//  Iterator
//
//  Created by Administlator on 2020/07/13.
//  Copyright © 2020 Administlator. All rights reserved.
//


#include <vector>
#include "Queue.hpp"

template <>
bool Queue<int>::isEmpty () {
    return count == 0;
}

template <>
void Queue<int>::enqueue (int e) {
    count++;
    list.push_back(e);
}

template <>
int Queue<int>::dequeue () {
    if (isEmpty()) {
        return NULL;
    }
    count--;
    int ele = list.at(0);
    list = std::vector<int>(list.begin() + 1, list.end());
    return ele;
}

template <>
int Queue<int>::peek () {
    return list.at(0);
}

template <>
QueueIterator<int> Queue<int>::makeIterator() {
    if (isEmpty()) {
        return *(new QueueIterator<int>());
    }
    QueueIterator<int> *head = new QueueIterator<int>();
    QueueIterator<int> *iterator = head;
    for (int i = 0 ;i < list.size(); i++) {
        iterator->data = list.at(i);
        if (list.size() -1 > i) {
            QueueIterator<int> *q = new QueueIterator<int>();
            q->data = list.at(i+1);
            iterator->next = q;
        }
        iterator = iterator->next;
    }
    return *head;
}

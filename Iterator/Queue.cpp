//
//  Queue.cpp
//  Iterator
//
//  Created by Administlator on 2020/07/13.
//  Copyright © 2020 Administlator. All rights reserved.
//


#include <vector>
#include "Queue.hpp"

template <typename T>
bool Queue<T>::isEmpty () {
    return count == 0;
}

template <>
bool Queue<int>::isEmpty () {
    return count == 0;
}

template <typename T>
void Queue<T>::enque (T e) {
    count++;
    list.push_back(e);
}

template <>
void Queue<int>::enque (int e) {
    count++;
    list.push_back(e);
}

template <typename T>
T Queue<T>::deque () {
    if (isEmpty()) {
        return;
    }
    count--;
    T ele = list.begin();
    std::vector<T>(list.begin() + 1, list.end());
    return ele;
}

template <>
int Queue<int>::deque () {
    if (isEmpty()) {
        return NULL;
    }
    count--;
    int ele = list.at(0);
    list = std::vector<int>(list.begin() + 1, list.end());
    return ele;
}

template <typename T>
T Queue<T>::peek () {
    return list.begin();
}


template <typename T>
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
            q->data = list.at(1+1);
            iterator->next = q;
        }
        iterator = iterator->next;
    }
    return *head;
}

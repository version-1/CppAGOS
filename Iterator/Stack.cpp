//
//  Stack.cpp
//  Iterator
//
//  Created by Administlator on 2020/07/13.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include "Stack.hpp"


template <>
bool Stack<int>::isEmpty () {
    return count == 0;
}

template <>
void Stack<int>::push (int e) {
    count++;
    list.push_back(e);
}

template <>
int Stack<int>::pop () {
    if (isEmpty()) {
        return NULL;
    }
    count--;
    int ele = list.at(list.size() - 1);
    list.pop_back();
    return ele;
}

template <typename T>
T Stack<T>::peek () {
    return list.end();
}


template <>
StackIterator<int> Stack<int>::makeIterator() {
    if (isEmpty()) {
        return *(new StackIterator<int>());
    }
    StackIterator<int> *head = new StackIterator<int>();
    StackIterator<int> *iterator = head;
    for (int i = 0 ;i < list.size(); i++) {
        iterator->data = list.at(i);
        if (list.size() -1 > i) {
            StackIterator<int> *s = new StackIterator<int>();
            s->data = list.at(i+1);
            iterator->next = s;
        }
        iterator = iterator->next;
    }
    return *head;
}

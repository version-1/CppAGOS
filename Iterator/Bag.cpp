//
//  Bag.cpp
//  Iterator
//
//  Created by Administlator on 2020/07/13.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include "Bag.hpp"
#include "BagIterator.hpp"

template <>
bool Bag<int>::isEmpty () {
    return count == 0;
}

template <>
void Bag<int>::add(int item) {
    list.push_back(item);
    count++;
}


template <>
BagIterator<int> Bag<int>::makeIterator() {
    if (isEmpty()) {
        return *(new BagIterator<int>());
    }
    BagIterator<int> *head = new BagIterator<int>();
    BagIterator<int> *iterator = head;
    for (int i = 0 ;i < list.size(); i++) {
        iterator->data = list.at(i);
        if (list.size() -1 > i) {
            BagIterator<int> *q = new BagIterator<int>();
            q->data = list.at(i+1);
            iterator->next = q;
        }
        iterator = iterator->next;
    }
    return *head;
}

//
//  main.cpp
//  Iterator
//
//  Created by Administlator on 2020/07/13.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>
#include "Bag.hpp"
#include "Queue.hpp"

void testBag() {
    Bag<int> *b = new Bag<int>();
    b->add(1);
    b->add(2);
    b->add(3);
    
    BagIterator<int> iterator = b->makeIterator();
    BagIterator<int> *it = &iterator;
    for (int i = 0; i < 3; i++) {
        std::cout << std::to_string(it->data) + "\n";
        it = it->next;
    }
}


void testQueue() {
    Queue<int> *q = new Queue<int>();
    q->enque(1);
    q->enque(2);
    q->enque(3);
    
    QueueIterator<int> iterator = q->makeIterator();
    QueueIterator<int> *it = &iterator;
    while(it != NULL) {
        std::cout << std::to_string(it->data) + "\n";
        it = it->next;
    }
    
    while(!q->isEmpty()) {
        std::cout << std::to_string(q->deque()) + "\n";
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    testBag();
//    testQueue();
    
    return 0;
}


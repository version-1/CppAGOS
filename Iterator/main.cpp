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
#include "Stack.hpp"

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

void testStack() {
    Stack<int> *s = new Stack<int>();
    s->push(1);
    s->push(2);
    s->push(3);
    
    StackIterator<int> iterator = s->makeIterator();
    StackIterator<int> *it = &iterator;
    while(it != NULL) {
        std::cout << std::to_string(it->data) + "\n";
        it = it->next;
    }
    
    while(!s->isEmpty()) {
        std::cout << std::to_string(s->pop()) + "\n";
    }
}



void testQueue() {
    Queue<int> *q = new Queue<int>();
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    
    QueueIterator<int> iterator = q->makeIterator();
    QueueIterator<int> *it = &iterator;
    while(it != NULL) {
        std::cout << std::to_string(it->data) + "\n";
        it = it->next;
    }
    
    while(!q->isEmpty()) {
        std::cout << std::to_string(q->dequeue()) + "\n";
    }
}


int main(int argc, const char * argv[]) {
    std::cout << "Bag >>>>>>>>\n";
    testBag();
    std::cout << "\nStack >>>>>>>>\n";
    testStack();
    std::cout << "\nQueue >>>>>>>>\n";
    testQueue();
    
    return 0;
}


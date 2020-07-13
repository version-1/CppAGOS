//
//  main.cpp
//  Iterator
//
//  Created by Administlator on 2020/07/13.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>
#include "Queue.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
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
    
    return 0;
}

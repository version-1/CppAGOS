//
//  Stack.hpp
//  Iterator
//
//  Created by Administlator on 2020/07/13.
//  Copyright © 2020 Administlator. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <vector>
#include "StackIterator.hpp"

template <typename T>
class Stack {
    int count = 0;
    std::vector<T> list;
public:
    void push (T e);
    T pop ();
    T peek();
    bool isEmpty();
    StackIterator<T> makeIterator();
};


#endif /* Stack_hpp */

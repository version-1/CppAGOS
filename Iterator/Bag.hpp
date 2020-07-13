//
//  Bag.hpp
//  Iterator
//
//  Created by Administlator on 2020/07/13.
//  Copyright © 2020 Administlator. All rights reserved.
//

#ifndef Bag_hpp
#define Bag_hpp

#include <stdio.h>
#include <vector>
#include "BagIterator.hpp"

template <class T>
class Bag {
    int count;
    std::vector<T> list;
public:
    void add(T item);
    bool isEmpty();
    BagIterator<T> makeIterator();
};

#endif /* Bag_hpp */

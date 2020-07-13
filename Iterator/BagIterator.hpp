//
//  BagIterator.hpp
//  Iterator
//
//  Created by Administlator on 2020/07/13.
//  Copyright © 2020 Administlator. All rights reserved.
//

#ifndef BagIterator_hpp
#define BagIterator_hpp

#include <stdio.h>
template<class T>
class BagIterator {
public:
    T data;
    BagIterator<T> *next;
};
#endif /* BagIterator_hpp */

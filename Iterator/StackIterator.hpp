//
//  StackIterator.hpp
//  Iterator
//
//  Created by Administlator on 2020/07/13.
//  Copyright © 2020 Administlator. All rights reserved.
//

#ifndef StackIterator_hpp
#define StackIterator_hpp

#include <stdio.h>
template <class T>
class StackIterator {
public:
    T data;
    StackIterator<T>* next;
};
#endif /* StackIterator_hpp */

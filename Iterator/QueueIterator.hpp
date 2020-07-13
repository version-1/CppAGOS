//
//  QueueIterator.hpp
//  Iterator
//
//  Created by Administlator on 2020/07/13.
//  Copyright © 2020 Administlator. All rights reserved.
//

#ifndef QueueIterator_hpp
#define QueueIterator_hpp

#include <stdio.h>
template <class T>
class QueueIterator {
public:
    T data;
    QueueIterator<T>* next;
};
#endif /* QueueIterator_hpp */

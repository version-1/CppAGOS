//
//  main.cpp
//  TopSort
//
//  Created by Administlator on 2020/07/30.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>
#include "CoursesSchedule.hpp"

int main(int argc, const char * argv[]) {
    vector<vector<int> > vect{
        { 0, 1 },
        { 1, 2 },
        { 2, 3 },
        { 3, 2 }
    };
    CoursesSchedule cs;
    cout << cs.canFinish(5, vect);
    
    return 0;
}

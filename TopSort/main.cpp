//
//  main.cpp
//  TopSort
//
//  Created by Administlator on 2020/07/30.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>
#include "CoursesSchedule.hpp"
#include "CoursesSchedule2.hpp"

int main(int argc, const char * argv[]) {
//    vector<vector<int> > vect{
//        { 0, 1 },
//        { 1, 0 },
//    };
//    CoursesSchedule cs;
//    cout << cs.canFinish(4, vect);
    
    vector<vector<int> > vect2{
        { 0, 1 },
    };
    CoursesSchedule2 cs2;
    cs2.findOrder(2, vect2);
    
    return 0;
}

//
//  CoursesSchedule2.cpp
//  TopSort
//
//  Created by Administlator on 2020/07/30.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include "CoursesSchedule2.hpp"

#include <stdio.h>
#include <vector>

void CoursesSchedule2::topsort(vector<int> *ordering, vector<bool> *visited, vector<vector<int>> prerequisites, int index) {
    if (visited->at(index)) {
        return;
    }
    visited->at(index) = true;
    
    for (int i = 0; i < prerequisites.size(); i++) {
        topsort(ordering, visited, prerequisites, prerequisites[i][0]);
    }
    
    ordering->push_back(index);
}

vector<int> CoursesSchedule2::findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ordering;
    vector<bool> visited(numCourses, false);
    
    for (int i =0; i < numCourses; i++) {
      topsort(&ordering, &visited, prerequisites, i);
    }
    reverse(ordering.begin(), ordering.end());
    
    return ordering;
}

//
//  CoursesSchedule.cpp
//  TopSort
//
//  Created by Administlator on 2020/07/30.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include "CoursesSchedule.hpp"
#include <vector>
#include <iostream>

using namespace std;

void CoursesSchedule::topsort(vector<int> *ordering, vector<bool> *visited, vector<vector<int>> prerequisites, int index, bool  *sortable) {
    if (!sortable) {
        return;
    }
    
    for (int i = 0; i < prerequisites.size(); i++) {
        if (prerequisites[i][0] == index) {
            if (visited->at(index)) {
                *sortable = false;
                return;
            }
            visited->at(index) = true;
            topsort(ordering, visited, prerequisites, prerequisites[i][1], sortable);
        }
    }
    
    
    ordering->push_back(index);
}


bool CoursesSchedule::canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ordering;
    vector<bool> visited(numCourses, false);
    
    bool sortable = true;
    topsort(&ordering, &visited, prerequisites, 0, &sortable);
  
    return sortable;
};


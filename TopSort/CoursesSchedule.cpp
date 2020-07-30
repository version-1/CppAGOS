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

void CoursesSchedule::dfs(vector<int> *ordering, vector<bool> *visited, vector<vector<int>> prerequisites, int index) {
    
    for (int i = 0; i < prerequisites.size(); i++) {
        if (prerequisites[i][0] == index) {
            visited->at(index) = true;
            dfs(ordering, visited, prerequisites, prerequisites[i][1]);
        }
    }
    
    ordering->push_back(index);
}


bool CoursesSchedule::canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ordering;
    vector<bool> visited(numCourses, false);
    
    dfs(&ordering, &visited, prerequisites, 0);
    for (int num: ordering) {
        cout << num << "\n";
    }
    
    return true;
};


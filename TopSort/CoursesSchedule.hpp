//
//  CoursesSchedule.hpp
//  TopSort
//
//  Created by Administlator on 2020/07/30.
//  Copyright © 2020 Administlator. All rights reserved.
//

#ifndef CoursesSchedule_hpp
#define CoursesSchedule_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class CoursesSchedule {
    void dfs(vector<int> *ordering, vector<bool> *visited, vector<vector<int>> prerequisites, int index);
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites); 
};
#endif /* CoursesSchedule_hpp */

//
//  CoursesSchedule2.hpp
//  TopSort
//
//  Created by Administlator on 2020/07/30.
//  Copyright © 2020 Administlator. All rights reserved.
//

#ifndef CoursesSchedule2_hpp
#define CoursesSchedule2_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class CoursesSchedule2 {
    void topsort(vector<int> *ordering, vector<bool> *visited, vector<vector<int>> prerequisites, int index);
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);
};

#endif /* CoursesSchedule2_hpp */

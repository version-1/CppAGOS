//
//  main.cpp
//  Greedy
//
//  Created by Administlator on 2020/07/31.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int twoCitySchedCost (vector<vector<int>> costs) {
    vector<int> score;
    int sum = 0;
    for (int i = 0; i < costs.size(); i++) {
        sum += costs[i][0];
        score.push_back(costs[i][1] - costs[i][0]);
    }
    sort(score.begin(), score.end());
    
    for (int i = 0; i < score.size() / 2; i++) {
        sum += score[i];
    }
    return sum;
}

int leastInterval (vector<char>& tasks, int n) {
    vector<int> chars(27, 0);
    int maxCount = 0;
    int maxNum = 0;
    
    for (int i = 0; i < tasks.size(); i ++) {
        int ascii = (int)tasks.at(i);
        int code = ascii - 65;
        chars[code]++;
        
        if (chars[code] > maxNum) {
            maxNum  = chars[code];
            maxCount = 1;
        } else if (maxNum == chars[code]) {
            maxCount++;
        }
    }
    int minTaskCount = (maxNum - 1) * (n + 1) + maxCount;
    return minTaskCount < tasks.size() ? tasks.size(): minTaskCount;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    vector<vector<int>> costs({
//        { 10, 20 },
//        { 30, 200 },
//        { 400, 50 },
//        { 30, 20 }
//    });
//    cout << twoCitySchedCost(costs);
    
    vector<char> vect({
        65,
        65,
        65,
        66,
        66,
        66,
    });
    cout << leastInterval(vect, 2);
    return 0;
}

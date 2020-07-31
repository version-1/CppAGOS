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

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int currentTank = 0;
    int totalTank = 0;
    int pos = 0;
    for (int i = 0; i < gas.size(); i++) {
        currentTank += gas[i] - cost[i];
        totalTank += gas[i] - cost[i];
        if (currentTank < 0) {
            currentTank = 0;
            pos = i + 1;
        }
    }
    return totalTank < 0 ? - 1 : pos;
}

vector<int> partitionLabels(string S) {
    vector<int> last(26, -1);
    vector<int> partitions;
    int anchor = 0;
    int end = 0;
    
    for (int i = 0; i < S.length(); i++) {
        last[(int)S[i] - 97] = i;
    }
    
    for (int i = 0; i < S.length(); i++) {
        end = max(end, last[(int)S[i] - 97]);
        if (i == end) {
            partitions.push_back(i - anchor + 1);
            anchor = i + 1;
        }
    }
    return partitions;
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
    
//    vector<char> vect({
//        65,
//        65,
//        65,
//        66,
//        66,
//        66,
//    });
//    cout << leastInterval(vect, 2);
    
//    vector<int> gas({
//        1, 2, 3, 4, 5
//    });
//    vector<int> cost({
//        3, 4, 5, 1, 2
//    });
//
//    cout << canCompleteCircuit(gas, cost);
//    vector<int> gas({
    //        1, 2, 3, 4, 5
    //    });
    //    vector<int> cost({
    //        3, 4, 5, 1, 2
    //    });
    //
//        cout << canCompleteCircuit(gas, cost);
    return 0;
}

//
//  main.cpp
//  TomatoFarm
//
//  Created by Administlator on 2020/07/30.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool included (int width, int height, int col, int row) {
    if (col < 0 || width <= col) {
        return false;
    }
    if (row < 0 || height <= row) {
        return false;
    }
    return  true;
}

bool isolated (vector<vector<int>> *storage, int col, int row) {
    int height = storage->size();
    int width =  storage->at(0).size();
    int up = row - 1 < 0 || storage->at(row-1)[col] == -1;
    int down = row + 1 >= height || storage->at(row+1)[col] == -1;
    int right = col + 1 >= width || storage->at(row)[col+1] == -1;
    int left = col - 1 < 0 || storage->at(row)[col-1] == -1;
    
    return  up && right && left && down;
}


bool floodfil(vector<vector<int>> *storage, int col, int row, int *count) {
    if (!included(storage->at(0).size(), storage->size(), col, row)) {
        return false;
    }
    if (storage->at(row)[col] == -1) {
        return false;
    }
    
    if (storage->at(row)[col] == 0) {
        count++;
        storage->at(row)[col] = *count;
        return floodfil(storage, col, row, count);
    }
    
    bool right = floodfil(storage, col + 1, row, count);
    bool left = floodfil(storage, col - 1, row, count);
    bool up = floodfil(storage, col, row - 1, count);
    bool down = floodfil(storage, col , row + 1, count);
    
    return down || left || up || right;
}

int main(int argc, const char * argv[]) {
    cout << "input :\n";
    int m, n;
    cin >> m >> n;
    vector<vector<int>> storage(n, vector<int> (0));
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int num;
            cin >> num;
            storage[i].push_back(num);
        }
    }
    int count = 0;
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < m; j ++) {
        if (storage[i][j] == 1) {
          floodfil(&storage, j, i, &count);
        }
      }
    }
    
    return 0;
}

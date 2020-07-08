//
//  main.cpp
//  QuickSort
//
//  Created by Administlator on 2020/07/08.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

std::vector<int> quickSort(std::vector<int> array) {
    if (array.size() <= 1) {
        return array;
    }
    
    if (array.size() == 2) {
        if (array.at(0) > array.at(1)) {
            int tmp = array.at(0);
            array.assign(0, array.at(1));
            array.assign(1, tmp);
            return array;
        }
        return array;
    }
    
    int pivot = array.at(round(array.size() / 2));
    std::vector<int> smaller{};
    std::vector<int> greater{};
    
    for (int i = 0; i < array.size(); i++) {
        if (array.at(i) > pivot) {
            greater.push_back(array.at(i));
        } else {
            smaller.push_back(array.at(i));
        }
    }
    std::vector<int> left = quickSort(smaller);
    std::vector<int> right = quickSort(greater);
    
    left.insert(left.end(), right.begin(), right.end());
    return left;
}


int main(int argc, const char * argv[]) {
    std::vector<int> data{5, 7, 9, 4, 3, 1, 2};
    std::vector<int> _data = quickSort(data);
    std::string tmp;
    
    
    for (int i = 0; i < _data.size(); i++) {
        std::cout << _data.at(i) << ", ";
    }
    std::cout << "\n";
    return 0;
}




//
//  main.swift
//  MiniProject1
//
//  Created by Administlator on 2020/06/25.
//  Copyright © 2020 Administlator. All rights reserved.
//

import Foundation

let char1 = "├─";
let char2 = "└─";
let char3 = "│ ";
let indent = "  ";

let currentPath = FileManager.default.currentDirectoryPath;
let fm = FileManager.default;

var file = 0;
var folder = 0;

func printNode(path: String, parents: [Bool]) {
    let items = getContents(path: path)
    let last = items.count > 0 ? items[items.count - 1] : nil
    for item in items {
        
        var isDir : ObjCBool = false
        fm.fileExists(atPath: path + "/" + item, isDirectory: &isDir);
        
        let isLast = last == item;
        var currentPrefix = ""
        for parent in parents {
            currentPrefix += parent ? indent + indent : " " + char3
        }
        let char = isLast ? char2 : char1
        
        if (isDir.boolValue) {
            let nextPath = path + "/" + item;
            let parents = parents + [isLast]
            print("\(currentPrefix) \(char) \(item)");
            printNode(path: nextPath, parents: parents);
            folder += 1
        } else {
            print("\(currentPrefix) \(char) \(item)");
            file += 1
        }
        
    }
}

func getContents(path: String) -> [String] {
    do {
        return try fm.contentsOfDirectory(atPath: path)
    } catch {
        print("permission denied: \(path)")
        return [];
    }
}

print("path: " + currentPath)
printNode(path: currentPath,  parents: [])
print("\n \(folder) directories, \(file) files")

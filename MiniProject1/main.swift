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

func printNode(path: String, prefix: String) {
    let items = getContents(path: path)
    let last = items.count > 0 ? items[items.count - 1] : nil
    for item in items {
        
        var isDir : ObjCBool = false
        fm.fileExists(atPath: path + "/" + item, isDirectory: &isDir);
        
        let isLast = last == item;
        let currentPrefix = isLast ? prefix.prefix(prefix.count - 2) + char2 : prefix
        
        if (isDir.boolValue) {
            let nextPrefix = char3 + indent + prefix;
            let nextPath = path + "/" + item;
            print("\(currentPrefix) \(item)");
            printNode(path: nextPath, prefix: nextPrefix);
            folder += 1
        } else {
            print("\(currentPrefix) \(item)")
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
printNode(path: currentPath,  prefix: char1)
print("\n \(folder) directories, \(file) files")

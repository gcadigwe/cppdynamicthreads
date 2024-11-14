//
//  main.cpp
//  concurrent-queue
//
//  Created by Godswill Adigwe on 14/11/2024.
//

#include <iostream>
#include <queue>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main(int argc, const char * argv[]) {
    std::queue<std::function<int()>> funcQueue;
    funcQueue.push(std::bind(add, 10, 3));
    funcQueue.push(std::bind(subtract, 7, 4));
    
    while (!funcQueue.empty()) {
        int result = funcQueue.front()();
        std::cout << "Result: " << result << std::endl;
        funcQueue.pop();
    }
  
    return 0;
}

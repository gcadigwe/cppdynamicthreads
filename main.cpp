//
//  main.cpp
//  concurrent-queue
//
//  Created by Godswill Adigwe on 14/11/2024.
//

#include <iostream>
#include <queue>
#include <thread>

std::mutex mtx;

void getDataAndExec (std::queue<int>& queue, int id) {
    std::lock_guard<std::mutex> lock(mtx);
    
    std::cout << "Thread ID: " << id << " Queue Data: " << queue.front() << std::endl;

    queue.pop();
}


int main(int argc, const char * argv[]) {
    std::queue<int> queue;
    std::vector<std::thread> threads;
    
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.push(6);
    
    long size = queue.size();
    
    std::cout << "queue size: " << size << std::endl;
    
    for(int i = 0; i < size; i++) {
        threads.emplace_back(getDataAndExec,std::ref(queue), i);
//        std::cout << "Created Thread with ID: " << threads.back().get_id() << std::endl;
    }
    
    for (auto& t: threads) {
        std::cout << "Original Thread id: " << t.get_id() << std::endl;
        t.join();
    }
  
    return 0;
}

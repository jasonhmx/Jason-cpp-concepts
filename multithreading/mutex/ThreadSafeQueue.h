#include <mutex>
#include <queue>

class ThreadSafeQueue {
private:
    std::queue<int> rawQueue;
    std::mutex m;

public:

    int retrieve_and_delete() {
        int front_value = 0;
        std::lock_guard<std::mutex> lg(m); // lockguard manages the mutex using RAII, so processes won't be blocked indefinitely

        // m.lock(); // mutex locks the thread, following operation atomic
        if (!rawQueue.empty()) {
            front_value = rawQueue.front();
            rawQueue.pop();
        }
        // m.unlock();
        return front_value;
    }
    
    void push(int val){
        std::lock_guard<std::mutex> lg(m);
        rawQueue.push(val);
        // m.unlock();
    }
};

#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>

class SharedData {
public:
    SharedData() : data(0) {}
    void setData(int val){
        std::unique_lock lock(m);
        data = val;
    }

    int getData(){
        std::shared_lock lock(m);
        return data;
    }

private:
    int data;
    std::shared_mutex m;
};

int main() {
    SharedData test;
    std::thread t1([&test](){
        for (int i = 0; i < 5; i++){
            int data = test.getData();
            std::cout << "Data read in thread 1 as " << data << std::endl;
        }
    });

    std::thread t2([&test](){
        for (int i = 0; i < 5; i++){
            int data = test.getData();
            std::cout << "Data read in thread 2 as " << data << std::endl;
        }
    });

    std::thread t3([&test](){
        for (int i = 0; i < 5; i++){
            test.setData(i);
            std::cout << "Data set as " << i << std::endl;
        }
    });

    t1.join();
    t2.join();
    t3.join();
    return 0;
}
#include <semaphore>
#include <iostream>

class SharedResource {
private:
    // declare a semaphore tha manages at most 3 access to the resource
    // default initialised as 0
    std::counting_semaphore<1> semaphore;

public:
    SharedResource() : semaphore(1) {}

    void accessResource(int id){
        std::cout << "Thread " << id << " is waiting..." << std::endl;
        semaphore.acquire();  // Acquire the semaphore, decrementing its count

        std::cout << "Thread " << id << " is accessing the shared resource." << std::endl;
        // Code for accessing the shared resource goes here

        std::cout << "Thread " << id << " is releasing the semaphore." << std::endl;
        semaphore.release();  // Release the semaphore, incrementing its count
    }

};
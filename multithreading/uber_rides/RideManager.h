#include <semaphore>
#include <mutex>
#include <vector>

struct Passenger {

};

struct Republican : Passenger{

};

struct Democrat : Passenger{

};

class RideManager {
private:
    std::counting_semaphore<4> waitingDemocrats{4};
    std::counting_semaphore<4> waitingRepublicans{4};
    const int capacity; // when capacity is reached, go
    std::vector<Passenger*> passengers(nullptr, 4);
    int countR;
    int countD;
    std::mutex mut; // mutex gives exclusive access to update capacity

public:
    void seated() {

    }

    void seatDemocrat() {
        // first acquire from semaphores. If we can't we wait
        waitingDemocrats.acquire();
        std::unique_lock<std::mutex> lock(mut); // lock with mutex
        if (countD == 1){

        }
    }

    void seatRepublican() {

    }

    void drive() {

    }

};
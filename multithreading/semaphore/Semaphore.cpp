#include <thread>
#include "sharedResource.h"

int main() {
    SharedResource resource;

    std::thread t1(&SharedResource::accessResource, &resource, 1);
    std::thread t2(&SharedResource::accessResource, &resource, 2);
    std::thread t3(&SharedResource::accessResource, &resource, 3);
    std::thread t4(&SharedResource::accessResource, &resource, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
#pragma once

class Singleton {
private:
    Singleton() {

    }
// can add locks and mutexes to protect multi-threaded access

public:
    static Singleton& getInstance(){
        static Singleton instance; // thread safe because it is only created once the first time it is called
        return instance;
    }
};
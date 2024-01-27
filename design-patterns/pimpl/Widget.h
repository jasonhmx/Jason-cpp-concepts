#pragma once
#include <memory>


class Widget {
public: // public interface defined here
    Widget();
    void setField(const int& val);
    int getField();

private:
    class Implementation;
    std::unique_ptr<Implementation> pImpl;
};
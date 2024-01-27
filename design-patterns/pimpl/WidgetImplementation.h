
#include "Widget.h"

class Widget::Implementation {
private:
    int field;

public:
    Implementation(){

    }

    void setField(const int& val){
        field = val;
    }

    int getField(){
        return field;
    }
};
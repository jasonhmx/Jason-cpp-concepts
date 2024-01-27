#include "Widget.h"
#include "WidgetImplementation.h"
#include <iostream>

int main(){
    Widget widget;
    widget.setField(0);
    std::cout << widget.getField() << "\n";
}
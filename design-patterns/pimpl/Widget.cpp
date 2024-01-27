
#include "WidgetImplementation.h"

int Widget::getField(){
    return pImpl->getField();
}

void Widget::setField(const int& val){
    pImpl->setField(val);
}

Widget::Widget(){
    pImpl = std::make_unique<Widget::Implementation>();
}
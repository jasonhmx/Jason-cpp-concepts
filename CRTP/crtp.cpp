#include "crtp.h"

int main(){
    Derived1 d1;
    DerivedDef ddef;
    crtpPrint(d1);
    crtpPrint(ddef);
    return 0;
}
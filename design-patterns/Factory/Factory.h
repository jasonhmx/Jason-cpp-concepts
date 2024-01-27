#pragma once
#include <memory>

class Product {
public:
    Product() {}
    virtual void do_thing() {}
};

class ProdCar : public Product {
public:
    ProdCar() {}
    void do_thing() override {}
private:
    int fieldCar;
};

class ProdBoat : public Product {
public:
    ProdBoat() {}
    void do_thing() override {}
private:
    int fieldBoat;
};

class Factory {
public:
    virtual std::unique_ptr<Product> makeProduct() {}

};

class CarFactory : public Factory {
public:
    std::unique_ptr<Product> makeProduct() override {
        return std::make_unique<ProdCar>();
    }
};

class BoatFactory : public Factory {
public:
    std::unique_ptr<Product> makeProduct() override {
        return std::make_unique<ProdBoat>();
    }
};
#include <iostream>
#include <map>

class AbstractProduct {
public:
    virtual void DoSomething() = 0;
};

// 定义一个产品类，该类必须是 AbstractProduct 类的派生类
class ProductA : public AbstractProduct {
public:
    void DoSomething() override { std::cout << "ProductA does something." << std::endl; }
};

class ProductB : public AbstractProduct {
public:
    void DoSomething() override { std::cout << "ProductB does something." << std::endl; }
};

template <typename IdentifierType, class AbstractProduct,
          class ProductCreator = AbstractProduct *(*)(),
          class MapContainer = std::map<IdentifierType, ProductCreator>>
class Factory {
public:
    void Register(const IdentifierType& id, ProductCreator creator) {
        creators_[id] = creator;
    }

    AbstractProduct* Create(const IdentifierType& id) {
        auto it = creators_.find(id);
        if (it != creators_.end()) {
            return (it->second)();
        } else {
            return nullptr;
        }
    }

private:
    MapContainer creators_;
};

// 定义一个函数，用于创建产品对象。该函数返回值必须是 AbstractProduct 的指针类型，并且无参数
AbstractProduct* CreateProductA() {
    return new ProductA();
}
AbstractProduct* CreateProductB() {
    return new ProductB();
}

int main() {
    // 注册产品创建函数到工厂中
    // Factory<std::string, AbstractProduct, AbstractProduct* (*)()> factory;
    Factory<std::string, AbstractProduct> factory;
    factory.Register("ProductA", CreateProductA);
    factory.Register("ProductB", CreateProductB);

    // 使用工厂创建产品对象
    AbstractProduct* productA = factory.Create("ProductA");
    if (productA) {
        productA->DoSomething();
        delete productA;
    }

    AbstractProduct* productB = factory.Create("ProductB");
    if (productB) {
        productB->DoSomething();
        delete productB;
    }

    return 0;
}

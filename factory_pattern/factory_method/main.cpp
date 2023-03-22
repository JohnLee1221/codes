#include <memory>
#include "product.h"
#include "apple.h"
#include "hawei.h"

int main() {
  std::shared_ptr<Product> product1 = std::make_shared<Apple>(Apple("Apple", 8888));
  product1->Producting();
  product1->PrintInfo();
  std::cout << "------------------------------------" << std::endl;
  std::shared_ptr<Product> product2 = std::make_shared<Hawei>(Hawei("Huawei", 9999));
  product2->Producting();
  product2->PrintInfo();

  return 0;
}
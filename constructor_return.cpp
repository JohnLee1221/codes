class MyClass {
public:
    MyClass(int value) {
        if (value > 0) {
            data = value;
            return;
        } else {
            data = 0;
            return;
        }
    }

private:
    int data;
};

int main() {
  MyClass m(10);

  return 0;
}


#ifndef ENUM_H_
#define ENUM_H_

class Test
{
public:
    Test() = default;
    void func();

private:
    enum {num_ = 100};
    int arr[num_];
};

#endif
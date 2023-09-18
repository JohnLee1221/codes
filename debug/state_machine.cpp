#include <iostream>

// 状态基类
class State {
public:
    virtual ~State() {}
    virtual void HandleEvent(class StateMachine* machine) = 0;
};

// 状态机基类
class StateMachine {
public:
    StateMachine() : state_(nullptr) {}
    void SetState(class State* state) {
        state_ = state;
    }
    void HandleEvent() {
        state_->HandleEvent(this);
    }
    void ChangeState(class State* state) {
        state_ = state;
    }
private:
    class State* state_;
};


// 状态A
class StateA : public State {
public:
    virtual void HandleEvent(class StateMachine* machine) {
        std::cout << "Handle event in state A" << std::endl;
        machine->ChangeState(new StateB);
    }
};

// 状态B
class StateB : public State {
public:
    virtual void HandleEvent(class StateMachine* machine) {
        std::cout << "Handle event in state B" << std::endl;
        machine->ChangeState(new StateA());
    }
};

int main() {
    StateMachine machine;
    machine.SetState(new StateA);

    // 循环处理事件，状态会不断在A和B之间切换
    for (int i = 1; i <= 10; ++i) {
        machine.HandleEvent();
    }

    return 0;
}

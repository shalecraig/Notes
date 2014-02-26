// Are **Stack** and **CountStack** substitutable?
class Stack {
    log *items_;
    int tos_;
public:
    Stack();
    Stack(int);
    ~Stack();
    long top() const;
    long pop();
    virtual void push(long);
};

class CountStack : public Stack {
    int count_;
public:
    CountStack() { count_ = 0; }
    void push(long);
    int numPushes() const;
};

int CountStack::numPushes() {
    return count_;
}

void CountStack::push(long l) {
    Stack::push(l);
    count_ += 1;
}

// TL;DR: Yes, they are.
// ---------------------------------------------------------------------------------
// 
// Bounded stack ex (no code):
// 
// Push has a precondition of a limit of the size of the elements in the stack.
/*Then, BoundedStack is not substitutable.*/
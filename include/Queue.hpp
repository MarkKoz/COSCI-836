#ifndef ASSIGNMENT_3_QUEUE_HPP
#define ASSIGNMENT_3_QUEUE_HPP

const int MAX = ??;  //To do: determine appropriate number

struct Passenger {
    char name[80];
};

class CQueue {
public:
    CQueue();
    bool IsEmpty(void);
    bool IsFull(void);
    void Enqueue(Passenger);
    Passenger Front(void);
    void Dequeue(void);

private:
    int front;
    int rear;
    Passenger passengers[MAX];
};

#endif

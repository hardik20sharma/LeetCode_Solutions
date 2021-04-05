class MyCircularQueue {
private:
    int size, items[1001], front, rear;

public:
    MyCircularQueue(int k)
    {
        size = k;
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value)
    {
        if(isFull())
            return false;

        if(front == -1)
        {
            front = 0;
            rear = 0;
        }
        
        else
            rear = (rear + 1) % size;

        items[rear] = value;

        return true;
    }
    
    bool deQueue()
    {
        if(isEmpty())
            return false;

        if(front == rear)
        {
            front = -1; rear = -1;
        }
        
        else
            front = (front + 1) % size;

        return true;
    }

    int Front()
    {
        return (front == -1) ? -1 : items[front];
    }

    int Rear()
    {
        return (rear == -1) ? -1 : items[rear];
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return (front == 0 && rear == size - 1 || front == rear + 1);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

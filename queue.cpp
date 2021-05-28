class Queue
{
private:
    int arr[5];
    int rear;
    int front;
public:
    Queue()
    {
        front = -1;
        rear = -1;
        for(int i =0;i<5;i++)
        {
            arr[i]=0;
        }
    }
    bool isEmpty()
    {
        if(front==-1 && rear ==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }    
    bool isFull()
    {
        if(rear==4) 
        {
            return true;
        }
        else
        {
                return false;
        }
    }

    void enqueue(int value)
    {
        if(isFull()) return;
        else if(isEmpty)
        {
            rear = front = 0; 
        }
        else{
            rear++;
        }
        arr[rear] = value;
    }
    int dequeue()
    {
        int x = 0;
        if(isEmpty) return;
        else if(front == rear)
        {
            x = arr[front];
            front = rear = -1;
        }
        else
        {
            x = arr[front];
            front++;
        }
        return x;
    }
    int count()
    {
        return (rear-front+1);
    }
};

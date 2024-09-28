public class MyCircularDeque
{
    private int[] deque;
    private int front;
    private int rear;
    private int size;
    private int capacity;

    public MyCircularDeque(int k)
    {
        capacity = k + 1; // Allocate extra space to differentiate between full and empty
        deque = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    // Adds an item at the front of Deque. Returns true if successful.
    public bool InsertFront(int value)
    {
        if (IsFull())
        {
            return false;
        }

        front = (front - 1 + capacity) % capacity; // Circular decrement
        deque[front] = value;
        size++;
        return true;
    }

    // Adds an item at the rear of Deque. Returns true if successful.
    public bool InsertLast(int value)
    {
        if (IsFull())
        {
            return false;
        }

        deque[rear] = value;
        rear = (rear + 1) % capacity; // Circular increment
        size++;
        return true;
    }

    // Deletes an item from the front of Deque. Returns true if successful.
    public bool DeleteFront()
    {
        if (IsEmpty())
        {
            return false;
        }

        front = (front + 1) % capacity; // Circular increment
        size--;
        return true;
    }

    // Deletes an item from the rear of Deque. Returns true if successful.
    public bool DeleteLast()
    {
        if (IsEmpty())
        {
            return false;
        }

        rear = (rear - 1 + capacity) % capacity; // Circular decrement
        size--;
        return true;
    }

    // Gets the front item from the Deque. Returns -1 if deque is empty.
    public int GetFront()
    {
        if (IsEmpty())
        {
            return -1;
        }
        return deque[front];
    }

    // Gets the last item from the Deque. Returns -1 if deque is empty.
    public int GetRear()
    {
        if (IsEmpty())
        {
            return -1;
        }
        return deque[(rear - 1 + capacity) % capacity];
    }

    // Returns true if the deque is empty.
    public bool IsEmpty()
    {
        return size == 0;
    }

    // Returns true if the deque is full.
    public bool IsFull()
    {
        return size == capacity - 1;
    }
}

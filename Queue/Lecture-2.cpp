/*
    Implementation of Circular Queue using Array

    Enqueue() 
        rear = (front + size - 1) % capacity;
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size ++ ;
    
    Dequeue()
        front = (front + 1) % capacity;
        size -- ;
*/
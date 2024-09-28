import java.util.Deque;
import java.util.LinkedList;

class MyCircularDeque {

    private Deque<Integer> deque;
    private int capacity;

    public MyCircularDeque(int k) {
        this.capacity = k;
        this.deque = new LinkedList<>();
    }

    public boolean insertFront(int value) {
        if (deque.size() == capacity) return false;
        deque.addFirst(value);
        return true;
    }

    public boolean insertLast(int value) {
        if (deque.size() == capacity) return false;
        deque.addLast(value);
        return true;
    }

    public boolean deleteFront() {
        if (deque.isEmpty()) return false;
        deque.pollFirst();
        return true;
    }

    public boolean deleteLast() {
        if (deque.isEmpty()) return false;
        deque.pollLast();
        return true;
    }

    public int getFront() {
        return deque.isEmpty() ? -1 : deque.peekFirst();
    }

    public int getRear() {
        return deque.isEmpty() ? -1 : deque.peekLast();
    }

    public boolean isEmpty() {
        return deque.isEmpty();
    }

    public boolean isFull() {
        return deque.size() == capacity;
    }
}

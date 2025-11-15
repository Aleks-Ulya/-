// Создание мультисписка (вложенного списка):
public class Node {
    int data;
    Node prev;
    Node next;

    public Node(int data)
    {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

public class DoublyLinkedList {
    Node head;
    Node tail;

    public DoublyLinkedList()
    {
        this.head = null;
        this.tail = null;
    }
}


// Создание очереди:
Queue<String> queue = new LinkedList<>();
queue.add("клубника"); 
queue.add("апельсин"); 
queue.add("арбуз"); 


//Создание дека:
Deque<Integer> stack = new ArrayDeque<>();
stack.push(1); 
stack.push(2); 
stack.push(3); 


//Создание приоритетной очереди:
PriorityQueue<Integer> minHeap = new PriorityQueue<>();
minHeap.offer(20); 
minHeap.offer(15); 
minHeap.offer(25); 
minHeap.offer(4); 


//Создание приоритетной очереди с компаратором:
PriorityQueue<Task> priorityQueue = new PriorityQueue<>(idComparator);
priorityQueue.add(new Task(10001, "Task 1", 15)); 
priorityQueue.add(new Task(10003, "Task 3", 20)); 
priorityQueue.add(new Task(10002, "Task 2", 2)); 

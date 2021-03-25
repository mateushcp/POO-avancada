#ifndef QUEUE_H
#define QUEUE_H

struct Node{

 public:
    Node() {};
    Node(int item) : item(item), next(nullptr) {}
    int GetItem() { return item; };
    void SetItem(int newItem) { item = newItem; };
    Node* GetNext() { return next; };
    void SetNext(Node *newNext) { next = newNext; };

private:
    int item;
    Node *next;
};


// Fila de números inteiros.
class Queue{
public:
    Queue();
    ~Queue();
    class EmptyException {};
    void push(int item);
    void pop();
    int front();
    int back();
    int count() const;
    bool IsEmpty();

protected:
    Node *front_;
    Node *back_;
    int size;
};

#endif 
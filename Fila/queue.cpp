#include "queue.h"



Queue::Queue() {
    size = 0;
    front_ = new Node();
    back_ = front_;
}

Queue::~Queue() {
    Node *p;
    p = front_->GetNext();
    while(p != nullptr){
        front_->SetNext(p->GetNext());
        delete p;
        p = front_->GetNext();
    }
    back_ = front_;
    size = 0;
    delete front_;
}

void Queue::push(int k) {
  Node *newNode = new Node(k);

    back_->SetNext(newNode);
    back_ = newNode;
    size++;
}

void Queue::pop() {
   if (IsEmpty())
        throw EmptyException();

    Node *p;
    int poppedItem;

    poppedItem = front_->GetNext()->GetItem();
    p = front_;
    front_ = front_->GetNext();
    delete p;
    size--;
}

int Queue::front(){
  if (IsEmpty())
        throw EmptyException();
return front_->GetNext()->GetItem();
}

int Queue::back(){
 if (IsEmpty())
        throw EmptyException();
return back_->GetItem();
}

int Queue::count() const{
   return size;
}
bool Queue::IsEmpty() {
    return size == 0;
}
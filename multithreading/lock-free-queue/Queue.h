#include <atomic>
#include <memory>

template <typename T>
class LockFreeQueue{
// a lock-free queue implementation which is node-based. Allows concurrent read and write operations
private:
    struct Node {
        // a node contains a shared pointer to the underlying data, allowing concurrent reads
        std::shared_ptr<T> data;
        std::atomic<Node*> next;
        Node(const T& t){
            data = std::make_shared<T>(t);
            next = nullptr;
        }
    };
    std::atomic<Node*> head;
    std::atomic<Node*> tail;

public:
    void push(const T& data_){
        Node* newNode = new Node(data_);
/*      if we are pushing at head
        Node* h = head;
        do {
            newNode->next = h;
        } while (!head.compare_exchange_strong(h, newNode));
         */

        // if we are pushing at tail
        Node* old_tail = tail;
        while(!old_tail->next.compare_exchange_strong(nullptr, newNode)){
            old_tail = tail;
        }
        // if the CAS succeeded in this thread, we have to update tail, otherwise other threads can't proceed
        // because other threads' old_tail -> next just won't be nullptr

        // recommended to use CAS operation to update tail.
        // there shouldn't be contention here since we are the only thread that got this far.
        tail.compare_exchange_strong(old_tail, newNode);
    }

    std::shared_ptr<T> pop(){
        Node* old_head = head;
        while (old_head && !head.compare_exchange_strong(old_head, old_head->next)){
            // does there need to be anything here since old_head is always updated to head anyways?
        }
        return old_head ? old_head->data : std::make_shared<T>();
    }
};
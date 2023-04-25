// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
    T* head = nullptr;

 public:
    void push(const T& data) {
        if (isEmpty()) {
            head = new T;
            head->ch = data.ch;
            head->prior = data.prior;
            head->next = nullptr;
        } else {
          if (!head->next) {
             T* temp = new T;
             temp->ch = data.ch;
             temp->prior = data.prior;
             head->next = temp;
             temp->next = nullptr;
          } else {
              if (head->prior < data.prior) {
                T* temp = new T;
                temp->ch = data.ch;
                temp->prior = data.prior;
                temp->next = head;
                head = temp;
              } else {
                T* cur = head;
                while (cur->next && cur->next->prior >= data.prior) {
                    cur = cur->next;
                }
                if (!cur->next) {
                    T* temp = new T;
                    temp->ch = data.ch;
                    temp->prior = data.prior;
                    cur->next = temp;
                    temp->next = nullptr;
                } else {
                    if (cur->next->prior < data.prior) {
                        T* temp = new T;
                        temp->ch = data.ch;
                        temp->prior = data.prior;
                        temp->next = cur->next;
                        cur->next = temp;
                  }
                }
              }
          }
        }
    }
    const T& pop() {
        if (isEmpty()) {
            throw std::string("empty");
        } else {
            T* temp = head;
            head = head->next;
            return *temp;
        }
    }
    bool isEmpty() const {
        return !head;
    }
};

struct SYM {
    char ch;
    int prior;
    struct SYM* next;
};
#endif  // INCLUDE_TPQUEUE_H_

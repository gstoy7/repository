#ifndef _List_h_
#define _List_h_

template <class T>
class Queue;

template <class T>
class ConstQueueIterator;


template <class T>
class QueueNode
// T is the type of element stored in the List.
{
public:
    QueueNode() : element(), next(nullptr), previous(nullptr) {}
    QueueNode(const T & e, QueueNode * next0, QueueNode * previous0):
        element(e), next(next0), previous(previous0) {}

    ~QueueNode() { next = previous = nullptr; }

    T element;
    QueueNode<T> * next;
    QueueNode<T> * previous;
};

template <class T>
class QueueIterator
// T is the type of element stored in the List.
{
   friend class Queue<T>;
   friend class ConstQueueIterator<T>;
public:
    QueueIterator() : current_node_(nullptr) {}
    T & operator*() const { return current_node_->element; }
    T * operator->() const { return &(current_node_->element); }
    bool operator==(const QueueIterator & rhs) const
    {
        return (current_node_ == rhs.current_node_);
    }
    bool operator!=(const QueueIterator & rhs) const
    {
        return (current_node_ != rhs.current_node_);
    }
    QueueIterator & operator++();  // prefix version (++itr)
    QueueIterator & operator--();
private:
    explicit QueueIterator(QueueNode<T> * p) : current_node_(p) {}
    QueueNode<T> * current_node_;
};

template <class T>
inline QueueIterator<T> & QueueIterator<T>::operator++()
{
    current_node_ = current_node_->next;
    return *this;
}

template <class T>
inline QueueIterator<T> & QueueIterator<T>::operator--()
{
    current_node_ = current_node_->previous;
    return *this;
}

template <class T>
class ConstQueueIterator
{
   friend class Queue<T>;
public:
    ConstQueueIterator() : current_node_(nullptr) {}
    ConstQueueIterator(const QueueIterator<T> & itr) :
        current_node_(itr.current_node_) {}
    const T & operator*() const { return current_node_->element; }
    const T * operator->() const
    {
        return &(current_node_->element);
    }
    bool operator==(const ConstQueueIterator & rhs) const
    {
        return (current_node_ == rhs.current_node_);
    }
    bool operator!=(const ConstQueueIterator & rhs) const
    {
        return (current_node_ != rhs.current_node_);
    }
    ConstQueueIterator & operator++();  
    ConstQueueIterator & operator--();
private:
    explicit ConstQueueIterator(const QueueNode<T> * p) :
        current_node_(p) {}
    const QueueNode<T> * current_node_;
};

template <class T>
inline ConstQueueIterator<T> & ConstQueueIterator<T>::operator++()
{
    current_node_ = current_node_->next;
    return *this;
}

template <class T>
inline ConstQueueIterator<T> & ConstQueueIterator<T>::operator--()
{
    current_node_ = current_node_->previous;
    return *this;
}

template <class T>
class Queue
{
public:
    typedef QueueIterator<T> iterator;
    typedef ConstQueueIterator<T> const_iterator;
    Queue();
    ~Queue();
    int size() const { return size_; }
    T & front() { return head_node_->next->element; }
    const T & front() const
    {
        return head_node_->next->element;
    }
    void push(const T & new_element);
    void pop();
    void clear();
    int search(const T & search_element);
    iterator begin() { return iterator(head_node_->next); }
    iterator end() { return iterator(head_node_); }
    const_iterator begin() const
    {
        return const_iterator(head_node_->next);
    }
    const_iterator end() const
    {
        return const_iterator(head_node_);
    }
private:
    QueueNode<T> * head_node_;
    int size_;
};

template <class T>
inline Queue<T>::Queue() : size_(0)
{
    head_node_ = new QueueNode<T>;
    head_node_->next = head_node_->previous = head_node_;
}

template <class T>
int Queue<T>::search(const T & search_element)
{
	int counter = 0;
	for(int i = 0; i < size_; i++)
	{
		counter++;
		if(head_node_->next->element == search_element)
		{
			return counter;
    		}
		else{
			counter = -1;
			return counter;
		}
	}
}

template <class T>
inline Queue<T>::~Queue()
{
    while (size_ != 0)
        pop();
    delete head_node_;
}

template <class T>
void Queue<T>::push(const T & new_element)
{
    auto last_node = head_node_->previous;
    auto new_node =
        new QueueNode<T>(new_element, head_node_, last_node);
    last_node->next = new_node;
    head_node_->previous = new_node;
    ++size_;
}

template <class T>
void Queue<T>::pop()
{
    auto last_node = head_node_->next;
    auto new_last_node = last_node->next;

    new_last_node->previous = head_node_;
    head_node_->next = new_last_node;

    delete last_node;

    --size_;
}

template<class T>
void Queue<T>::clear()
{
	while(size_ != 0)
		pop();
}	
#endif

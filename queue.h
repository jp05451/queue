template <typename T1>
class node
{
public:
    node(){};
    node(T1 _data) : data(_data) {}
    node *previousNode = nullptr;
    T1 data;
    node *nextNode = nullptr;
    ~node()
    {
        delete previousNode;
        delete nextNode;
    };
};

template <typename T2>
class queue
{
public:
    void push(T2 data);
    void pop();
    T2 &top();
    int Size();
    bool empty();

private:
    node<T2> *beginNode = nullptr;
    node<T2> *endNode = nullptr;
    int size = 0;
};

template <class T3>
void queue<T3>::push(T3 data)
{
    node<T3> *newNode = new node<T3>(data);
    newNode->data = data;

    if (beginNode == nullptr)
    {
        // insert the beginNode
        beginNode = newNode;
        endNode = newNode;
    }
    else
    {
        // insert Node before the begin Node
        endNode->nextNode = newNode;
        newNode->previousNode = endNode;
    }
    endNode = newNode;
    size++;
}

template <class T4>
void queue<T4>::pop()
{
    size--;
    // storge the node after beginNode
    node<T4> *tempNode = beginNode->nextNode;
    T4 temp = beginNode->data;

    // delete beginNode
    beginNode->nextNode = nullptr;
    beginNode->previousNode = nullptr;
    delete beginNode;

    // recover beginNode
    beginNode = tempNode;
    return;
}

template <class T5>
int queue<T5>::Size()
{
    return size;
}

template <class T6>
bool queue<T6>::empty()
{
    return size == 0;
}

template <class T7>
T7 &queue<T7>::top()
{
    return beginNode->data;
}

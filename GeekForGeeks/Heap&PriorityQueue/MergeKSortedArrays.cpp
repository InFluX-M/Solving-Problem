class Heap
{

public:
    class Node
    {
    public:
        int value;
        int key;

        Node(int v, int k)
        {
            this->value = v;
            this->key = k;
        }
    };

    vector<Node *> heap;

    ~Heap()
    {
        for (int i = 0; i < heap.size(); i++)
        {
            delete[] heap[i];
        }
    }

    int parent(int pos) { return (pos - 1) / 2; }
    int leftChild(int pos) { return 2 * pos + 1; }
    int rightChild(int pos) { return 2 * pos + 2; }

    bool hasLeft(int pos)
    {
        return (leftChild(pos) < heap.size());
    }
    bool hasRight(int pos)
    {
        return (rightChild(pos) < heap.size());
    }

    void swap(int i, int j)
    {
        Node *temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void upStream(int i)
    {
        while (i > 0)
        {
            int p = parent(i);
            if (heap[p]->key <= heap[i]->key)
            {
                break;
            }
            swap(i, p);
            i = p;
        }
    }

    void downStream(int i)
    {
        while (hasLeft(i))
        {
            int leftC = leftChild(i);
            int smallChild = leftC;

            if (hasRight(i))
            {
                int rightC = rightChild(i);
                if (heap[leftC]->key > heap[rightC]->key)
                {
                    smallChild = rightC;
                }
            }

            if (heap[smallChild]->key >= heap[i]->key)
                break;
            swap(i, smallChild);
            i = smallChild;
        }
    }

    Node *insert(int key, int value)
    {
        Node *node = new Node(value, key);
        heap.push_back(node);
        upStream(heap.size() - 1);
        return node;
    }

    Node *min()
    {
        return heap[0];
    }

    Node *removeMin()
    {
        Node *minNode = min();
        swap(0, heap.size() - 1);
        heap.pop_back();
        downStream(0);
        return minNode;
    }
};

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    int n = 0;

    Heap heap;
    for(vector<int> t : arr)
    {
        n += t.size();
        for(int num : t)
        {
            heap.insert(num, num);
        }
    }

    vector<int> aim;

    while(n--)
    {
        aim.push_back(heap.removeMin()->value);
    }

    return aim;
}

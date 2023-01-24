#include <bits/stdc++.h>
using namespace std;

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
            if (heap[p]->key >= heap[i]->key)
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
                if (heap[leftC]->key < heap[rightC]->key)
                {
                    smallChild = rightC;
                }
            }

            if (heap[smallChild]->key <= heap[i]->key)
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

vector<int> kLargest(int arr[], int n, int k)
{
    Heap heap;
    for(int i=0; i<n; i++)
    {
        heap.insert(arr[i], arr[i]);
    }

    vector<int> aim;
    while(k--)
    {
        aim.push_back(heap.removeMin()->value);
    }

    return aim;
}

int main()
{

    return 0;
}

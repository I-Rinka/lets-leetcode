#include "./test.hpp"

class union_qunion : public union_component
{
private:
    int *array;
    int size;
    int GetRoot(int node);

public:
    union_qunion(int num);
    void Show();
    void Union(int a, int b);
    bool Find(int a, int b);

    ~union_qunion();
};
void union_qunion::Show()
{
#ifdef DEBUG
    for (int i = 0; i < this->size; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < this->size; i++)
    {
        printf("%d ", this->array[i]);
    }
    printf("\n");
    fflush(stdout);
#endif
}

void union_qunion::Union(int a, int b)
{
    this->array[a] = this->array[b];
}
bool union_qunion::Find(int a, int b)
{
    if (GetRoot(a) == GetRoot(b))
    {
        return true;
    }

    return false;
}
int union_qunion::GetRoot(int node)
{
    int next = this->array[node];
    while (next != this->array[next])
    {
        next = this->array[next];
    }
    return next;
}

union_qunion::union_qunion(int nums) : union_component(nums)
{
    this->size = nums;
    this->array = new int[nums];
    for (int i = 0; i < nums; i++)
    {
        this->array[i] = i;
    }
}

union_qunion::~union_qunion()
{
    delete this->array;
}

int main(int argc, char const *argv[])
{
    printf("input counts:\n");
    int N;
    scanf("%d\n", &N);
    union_component *UC = new union_qunion(N);
    test *T = new test();
    T->run(UC);
    return 0;
}

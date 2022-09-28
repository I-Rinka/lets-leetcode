#include "./test.hpp"

class union_qfind : public union_component
{
private:
    int *array;
    int size;

public:
    union_qfind(int num);
    void Show();
    void Union(int a, int b);
    bool Find(int a, int b);

    ~union_qfind();
};
void union_qfind::Show()
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

void union_qfind::Union(int a, int b)
{
    if (a >= this->size || b >= this->size)
    {
        return;
    }
    int v = this->array[b];
    for (int i = 0; i < this->size; i++)
    {
        if (this->array[i] == v)
        {
            this->array[i] = this->array[a];
        }
    }
}
bool union_qfind::Find(int a, int b)
{
    if (this->array[a] == this->array[b])
    {
        return true;
    }

    return false;
}

union_qfind::union_qfind(int nums) : union_component(nums)
{
    this->size = nums;
    this->array = new int[nums];
    for (int i = 0; i < nums; i++)
    {
        this->array[i] = i;
    }
}

union_qfind::~union_qfind()
{
    delete this->array;
}

int main(int argc, char const *argv[])
{
    printf("input counts:\n");
    int N;
    scanf("%d\n", &N);
    union_component *UC = new union_qfind(N);
    test *T = new test();
    T->run(UC);
    return 0;
}

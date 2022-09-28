#include <iostream>
class union_component
{
private:
    /* data */
public:
    union_component(int nums);
    void virtual Union(int a, int b) = 0;
    void virtual Show() = 0;
    bool virtual Find(int a, int b) = 0;
    ~union_component();
};

union_component::union_component(int nums)
{
}

union_component::~union_component()
{
}

class test
{
private:
    /* data */
public:
    test();
    void run(union_component *UC);
    ~test();
};

void test::run(union_component *UC)
{
    char buffer[10];
#ifdef DEBUG
    printf("%s %d\n", __FILE__, __LINE__);
#endif

    while (true)
    {
        int p, q;
        if (fgets(buffer, 9, stdin) == NULL)
        {

#ifdef DEBUG
            printf("%s %d\n", __FILE__, __LINE__);
#endif

            break;
        }
        if (sscanf(buffer, "%d %d", &p, &q) == 2)
        {
#ifdef DEBUG
            printf("%s", buffer);
            printf("%s %d\n", __FILE__, __LINE__);
#endif
            // break;
            if (!UC->Find(p, q))
            {
                UC->Union(p, q);
                printf("connected %d %d\n", p, q);
                UC->Show();
                fflush(stdout);
            }
            else
            {
                printf("%d %d are connected\n", p, q);
            }
        }
        else
        {
            printf("not OK\n");
        }
    }
}

test::test()
{
}

test::~test()
{
}

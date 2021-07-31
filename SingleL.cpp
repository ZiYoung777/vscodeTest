

class SingleA
{
    SingleA() {}

public:
    SingleA *single = nullptr;
    SingleA *getSingleA()
    {
        if (single == nullptr)
        {
            lock();
            if (single == nullptr)
            {
                single = new SingleA();
            }
        }
        return single;
    }
}
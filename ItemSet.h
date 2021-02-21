#include "Item.h"

// 每一个放入背包/仓库格子的都是一个ItemSet
class ItemSet
{
public:
    inline item::Genre GetGenre() const
    {
        return this->genre;
    }

    inline int GetCount() const
    {
        return this->count;
    }

    void AddCount(int count){
        this->count += count;
    }

    void ReduceCount(int count){
        this->AddCount(-count);
    }


private:
    item::Genre genre;
    int count;
};

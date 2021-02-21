
namespace item
{
    enum class Genre
    {
        MATERIAL = 0, //材料
        EQUIP,        // 装备
        CONSUMABLE,   //消耗品(可使用的: 药水,一次性道具)
    };

    enum class EquipDetailGenre
    {
        WEAPON = 0,
        HELM,       //头盔
        AMULET,     //护身符(项链)
        BODY_ARMOR, //衣物
        GLOVES,     //手套
        RING,       //戒指
        BELT,       //腰带
        PENDANT,    //腰坠
        BOOTS,      //鞋

        MOUNT, //坐骑
    };

    enum class WeaponDetailGenre
    {
        MELEE = 0, //短兵器(刀,剑)
        RANGE,     //长兵器(矛,戟)
        THROW,     //远程武器(弓,弩,飞刀,镖)
    };

    // 叠放在一起的物品共用一个id,主要用于 服务端和客户端的通信
    typedef unsigned long ItemId;

    struct IItem
    {
        virtual ItemId GetId() const = 0;
        virtual Genre GetGenre() const = 0;
        // 出售到商店的价格
        virtual int GetPrice() const = 0;
    };

    class ItemBase : public IItem
    {
    protected:
        ItemBase(ItemId id, Genre genre) : id(id), genre(genre)
        {
        }
        virtual ItemId GetId() const override final
        {
            return this->id;
        }
        virtual Genre GetGenre() const override final
        {
            return this->genre;
        }

        virtual int GetPrice() const override final
        {
            return this->price;
        }

    protected:
        ItemId id;
        Genre genre;
        int price;
        int stack;     //叠放数量
        int max_stack; //最多可以叠放多少个
    };

    class Equip : public ItemBase
    {
    public:
        Equip(ItemId id) : ItemBase(id, Genre::EQUIP)
        {
        }

        int GetDurability() const
        {
            return this->durability;
        }

        int GetMaxDurability() const
        {
            return this->max_durability;
        }

    protected:
        int durability;     //当前耐久度
        int max_durability; //最大耐久度
    };

    class Consumable : public ItemBase
    {
    public:
        Consumable(ItemId id) : ItemBase(id, Genre::CONSUMABLE)
        {
        }
    };

    class Material : public ItemBase
    {
    public:
        Material(ItemId id) : ItemBase(id, Genre::MATERIAL)
        {
        }
    };

} // namespace item


#include "IComponent.h"
#include <string>

namespace
{
    class Player final : public IComponent
    {
    public:
        virtual void Setup() override {}
        virtual void Teardown() override {}
        virtual void Start() override {}
        virtual void Stop() override {}
        virtual void Update() override {}
        virtual void LateUpdate() override {}

    private:

        std::wstring name;

        int hp;
        int max_hp;
        int mp;
        int max_mp;



    };
}

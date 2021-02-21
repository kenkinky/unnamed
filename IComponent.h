

struct IComponent
{
    virtual void Setup() = 0;
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void LateUpdate() = 0;
    virtual void Stop() = 0;
    virtual void Teardown() = 0;
};

#ifndef LITECHFRAMEWORK_ICOMPONENT_H
#define LITECHFRAMEWORK_ICOMPONENT_H

class liActor;

class IComponent {
    friend class liActor;
public:
    virtual ~IComponent() { }

    virtual void Initialize() = 0;
    virtual void Delete() = 0;
    virtual void Render() = 0;
    virtual void Update(double deltaTime) = 0;
protected:
    liActor* parent;
};

#endif
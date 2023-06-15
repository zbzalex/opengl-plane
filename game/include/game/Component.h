#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <vector>

class Component
{
public:
    Component();
    Component(const std::string &name);
    ~Component() = default;
    virtual void Add(Component *child);
    virtual void Remove(Component *child);
    virtual void Clear();
    virtual void Update(float deltaTime);
    inline Component * GetParent() { return m_parent; }
    inline void SetParent(Component *parent) { m_parent = parent; }
protected:
    std::string m_name = nullptr;
    std::vector<Component *> m_children;
    Component *m_parent = nullptr;
};

#endif // COMPONENT_H
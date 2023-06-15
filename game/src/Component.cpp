#include <game/Component.h>

Component::Component() {}
Component::Component(const std::string &name) : m_name(name)
{
}

void Component::Add(Component *child)
{
    child->SetParent(this);

    m_children.push_back(child);
}

void Component::Remove(Component *child)
{
    std::vector<Component *>::iterator it = std::find(m_children.begin(), m_children.end(), child);
    if (*it != nullptr)
    {
        (*it)->SetParent(nullptr);

        m_children.erase(it);
    }
}

void Component::Clear()
{
    for (Component *const it : m_children)
    {
        Remove(it);
    }
}

void Component::Update(float deltaTime)
{
    for (Component *const it : m_children)
    {
        it->Update(deltaTime);
    }
}
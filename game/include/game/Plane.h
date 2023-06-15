#ifndef PLANE_H
#define PLANE_H

#include "Component.h"

class Plane : public Component {
public:
    Plane();
    virtual void Update(float deltaTime) override;
};

#endif // PLANE_H
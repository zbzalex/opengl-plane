#ifndef SCENE_H
#define SCENE_H

#include "Component.h"

class Scene : public Component {
public:
    Scene();
    virtual void Update(float deltaTime) override;
};

#endif // SCENE_H
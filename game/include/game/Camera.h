#ifndef CAMERA_H
#define CAMERA_H

#include "Precompiled.h"
#include "Component.h"

class Camera : public Component {
public:
    Camera(void);

    virtual void Update(float deltaTime) override;
protected:
    glm::vec3 m_pos;
    glm::quat m_orient;
};

#endif // CAMERA_H
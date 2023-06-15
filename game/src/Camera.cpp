#include <game/Camera.h>
#include <game/Component.h>
#include <iostream>
#include <game/Input.h>

Camera::Camera() : Component("camera")
{
    
}

void Camera::Update(float deltaTime) {
    Component::Update(deltaTime);

    std::cout << "Update camera\n";

    
    glMatrixMode(GL_PROJECTION);
    glm::mat4 projection = glm::perspective(
        glm::radians(59.f),
        (float) SCREEN_WIDTH/SCREEN_HEIGHT,
        0.1f,
        2000.f
    );
    
    glLoadMatrixf(glm::value_ptr(projection));


    glMatrixMode(GL_MODELVIEW);

    glm::mat4 view = glm::lookAt(
        glm::vec3(0.0f,  0.9f,  -5.0f),
        glm::vec3(0.0f,  0.0f,   0.0f),
        glm::vec3(0.0f,  1.0f,   0.0f)
    );

    view = glm::translate(view, glm::vec3(m_pos[0], m_pos[1], m_pos[2]));

    glLoadMatrixf(glm::value_ptr(view));

    Input &rInput = Input::Instance();
    if (rInput.GetKeyState(SDLK_w)) {
        m_pos[2] -= 0.01f;
    } else if (rInput.GetKeyState(SDLK_s)) {
        m_pos[2] += 0.01f;
    } else if (rInput.GetKeyState(SDLK_a)) {
        m_pos[0] -= 0.01f;
    } else if (rInput.GetKeyState(SDLK_d)) {
        m_pos[0] += 0.01f;
    } else if (rInput.GetKeyState(SDLK_q)) {
        m_pos[1] -= 0.01f;
    } else if (rInput.GetKeyState(SDLK_e)) {
        m_pos[1] += 0.01f;
    }
}
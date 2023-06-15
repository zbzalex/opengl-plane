#include <game/Precompiled.h>
#include <game/Plane.h>
#include <game/Component.h>
#include <iostream>

Plane::Plane() : Component("plane") {}

void Plane::Update(float deltaTime)
{
    Component::Update(deltaTime);

    std::cout << "Update plane\n";

    glMatrixMode(GL_MODELVIEW);

    // glBegin(GL_QUADS);

    // glColor3f(0.0f, 0.9f, 0.0f);

    // glVertex3f(-5.0f, -5.0f, 0.0f); // lb
    // glVertex3f( 5.0f, -5.0f, 0.0f);  // rb
    // glVertex3f( 5.0f, 5.0f, 0.0f);   // rt
    // glVertex3f(-5.0f, 5.0f, 0.0f);  // lt

    // glEnd();

    int gridSize = 5;

    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f); // Цвет линий - серый
    
    // Отрисовка горизонтальных линий
    for (int i = -gridSize; i <= gridSize; ++i) {
        glVertex3f(-gridSize, 0.0f, i);
        glVertex3f(gridSize, 0.0f, i);
    }
    
    // Отрисовка вертикальных линий
    for (int i = -gridSize; i <= gridSize; ++i) {
        glVertex3f(i, 0.0f, -gridSize);
        glVertex3f(i, 0.0f, gridSize);
    }
    
    glEnd();
}
#include <game/Scene.h>
#include <game/Component.h>
#include <game/Precompiled.h>
#include <game/Text.h>
#include <game/Camera.h>
#include <game/Plane.h>

Scene::Scene() : Component("scene")
{
	Add(new Camera());
	Add(new Plane());
}

void Scene::Update(float deltaTime)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.9f, 0.9f, 0.9f, 1.f);

	Component::Update(deltaTime);

	Text &rText = Text::Instance();
	float pos[2] = {
		10,
		10
	};
	rText.SetPosition(pos);
	rText.SetAlign(Text::ALIGN_CENTER);
	rText.SetFontSize(14);
	rText.SetText("hello");
	rText.SetColor(1.f, 0.f, 0.f, 1.f);

	rText.Render();

	glFlush();
}
#include <game/Precompiled.h>
#include <game/Game.h>
#include <game/Input.h>
#include <game/Text.h>
#include <iostream>
#include <game/Scene.h>

Game::Game()
{
	SetScene(new Scene());
}

void Game::Init() noexcept
{
	std::cout << "Initialize game..\n";

	Text &rText = Text::Instance();
	rText.Create((float) SCREEN_WIDTH,(float) SCREEN_HEIGHT);
	rText.SetFace("../assets/fonts/RobotoMono-Regular.ttf");
	float scale[2] = {
		1.f,
		1.f
	};
	rText.SetScale(scale);
	rText.SetFontSize(14);
	rText.SetColor(1.0f, 1.0f, 1.0f, 1.f);

	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT);
}

void Game::Update(float deltaTime) noexcept
{
	if (Input::Instance().GetKeyState(SDLK_ESCAPE) == 1)
	{
		Stop();

		return;
	}

	m_scene->Update(deltaTime);
}

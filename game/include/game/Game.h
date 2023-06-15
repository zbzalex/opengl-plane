#ifndef GAME_H
#define GAME_H

#include "Component.h"

class Game
{
public:
  Game();

  void Init() noexcept;
  
  void Update(float dt) noexcept;

  inline bool IsRunning() const { return m_Running; }

  inline void Stop() { m_Running = false; }
  
  inline void SetScene(Component *scene) { m_scene = scene; }

protected:
  bool m_Running = true;
  Component * m_scene;
};

#endif // GAME_H
#ifndef GAME_HPP
# define GAME_HPP

# include "Interfaces/Sound.hpp"
# include "Graphical/Model.hpp"
# include "Game/ResourceHandler.hpp"
# include "Game/Load.hpp"
# include "Game/Scene.hpp"
# include "Game/Map.hpp"
# include "Game/Settings.hpp"
# include "Interfaces/IGame.hpp"
# include "Common/GUI.hpp"
# include <map>
#include "Common/Timer.hpp"

namespace indie {

  # define PLAYER_SPEED 0.1

  typedef std::function<void()>                                               TurnHandler;
  typedef std::function<void(const std::size_t &, const std::size_t &)>       TileHandler;

  class Game : public indie::IGame {
    public:
      Game();
      virtual ~Game();

    public:
      // Getters for ressources to load
      virtual std::unique_ptr<std::vector<std::unique_ptr<indie::ISprite> > >     getSpritesToLoad() const;
      virtual std::unique_ptr<std::vector<std::unique_ptr<IModel> > >             getModelsToLoad() const;
      virtual std::unique_ptr<std::vector<std::pair<std::string, SoundType> > >   getSoundsToLoad() const;
      virtual std::unique_ptr<std::vector<std::unique_ptr<indie::IScene> > >      getScenesToLoad() const;

    public:
      virtual void notifyEvent(std::vector<Event> &&events);
      virtual void setObjectsAnimationState(const std::vector<AnimationState> &);

      // --- Process Part - Start
    public:
      virtual void process();

    private:
      void initSettings();

    private:
      void  splashScreen();
      void  gameProcess();
      void  menuProcess();

    private:
      std::vector<indie::Player>::const_iterator getPlayerSettings(size_t) const;
      indie::OBJECTS_ID getBombType(size_t) const;
      void bonusTimer();

    private:
      void updateAnimations();
      std::vector<indie::AnimationState>::const_iterator getAnimationStateIt(size_t) const;
      void updatePlayerAnimation(Tile &, size_t);
      void updateBombAnimation(Tile &, size_t &, OBJECTS_ID, size_t x, size_t y);
      void removeObject(Tile &, size_t);
      bool isEnded() const;
      void reset();

    private:
      void  handleEvents();
      Tile &move_left(indie::Tile &, size_t, size_t);
      Tile &move_right(indie::Tile &, size_t, size_t);
      Tile &move_down(indie::Tile &, size_t, size_t);
      Tile &move_up(indie::Tile &, size_t, size_t);
      void  move(size_t, indie::ELookAt);
      void  bomb(size_t);
      void  SquareBomb(indie::Tile &);
      void  PikesBomb(indie::Tile &, size_t, size_t);
      void  TentacleBomb(indie::Tile &, size_t x, size_t y);

    private:
      void explode(indie::Tile &, size_t i, size_t x, size_t y);
      void squareExplosion(size_t x, size_t y);
      void tentacleExplosion(size_t x, size_t y, size_t size, size_t at);
      void pikesTrap(size_t x, size_t y);
      void kill(indie::Tile &);
      void explodeBox(indie::Tile &);

    private:
      void AIhandler();

    public:
      virtual GameState                 getGameState() const;
      virtual const IMap                &getCurrentMap() const;
      virtual const std::vector<size_t> &getObjectsId() const;
      virtual const IGUI                &getCurrentGUI() const;
      virtual const std::vector<Sound>  &getSoundsToPlay() const;

    private:
      indie::Timer                      _timer;
      std::vector<indie::Sound>         _soundsToPlay;
      indie::Sound                      _music;
      GameState                         _gameState;
      std::vector<Event>                _events;
      Map                               _map;
      Settings                          _settings;
      GUI                               _gui;
      std::vector<AnimationState>       _objectsStates;
  };
};

#endif /* GAME_HPP */

#ifndef GAME_HPP
# define GAME_HPP

# include "Interfaces/IGame.hpp"
# include "Interfaces/Sound.hpp"
# include "Graphical/Model.hpp"
# include "Game/ResourceHandler.hpp"
# include "Game/Load.hpp"
# include "Game/Scene.hpp"
# include "Game/Map.hpp"
# include "Game/Settings.hpp"
# include "Game/Player.hpp"
# include "Common/GUI.hpp"
# include "Common/Timer.hpp"
# include <map>
# include <numeric>

namespace indie {

  # define PLAYER_SPEED 0.1

  typedef std::function<void()> TurnHandler;
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
      void start();
      void reset();
      virtual void process();

    private:
      void  splashScreen();
      void  gameProcess();
      void  menuProcess();

    private:
        void fallingStones();
        void itsRainingStones();
        std::pair<size_t, size_t> getNextFallingPillarPos(bool = false);

    private:
      Player &getBombOwner(size_t);
      Player &getPlayerById(size_t);
      void updateScore(size_t, int = 100);
      void deleteBombSaves(size_t);
      void popBonus(Tile &, size_t);

    private:
      std::vector<indie::AnimationState>::const_iterator getAnimationStateIt(size_t) const;
      void updateAnimations();
      void updatePlayerAnimation(Tile &, size_t);
      void updateBombAnimation(Tile &, size_t &, OBJECTS_ID, size_t x, size_t y);
      void removeObject(Tile &, size_t &);
      bool isEnded() const;
      void reward();

    private:
      void  handleEvents();
      void  move(size_t, indie::ELookAt);
      Tile &move_left(indie::Tile &, size_t, size_t);
      Tile &move_right(indie::Tile &, size_t, size_t);
      Tile &move_down(indie::Tile &, size_t, size_t);
      Tile &move_up(indie::Tile &, size_t, size_t);
      void checkBonus(indie::Tile &, indie::Tile &);
      void checkDeath(indie::Tile &, size_t, size_t);
      void  bomb(size_t);
      void  SquareBomb(indie::Tile &, indie::Player &);
      void  PikesBomb(indie::Tile &, size_t, size_t, indie::Player &);
      void  TentacleBomb(indie::Tile &, size_t x, size_t y, indie::Player &);

    private:
      void explode(indie::Tile &, size_t i, size_t x, size_t y);
      void squareExplosion(size_t x, size_t y, size_t);
      void tentacleExplosion(size_t x, size_t y, size_t size, size_t at, size_t);
      void simpleExplosion(size_t x, size_t y, size_t, bool = true, bool = true);
      int chainExplosion(size_t, size_t, size_t);
      void kill(indie::Tile &, size_t);
      void explodeBox(indie::Tile &, size_t);

    private:
      void AIhandler();

    public:
      virtual GameState                 getGameState() const;
      virtual const IMap                &getCurrentMap() const;
      virtual const std::vector<size_t> &getObjectsId() const;
      virtual const IGUI                &getCurrentGUI() const;
      virtual const std::vector<Sound>  &getSoundsToPlay() const;

    private:
      std::vector<std::unique_ptr<Player> >       _players;
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

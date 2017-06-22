#ifndef AISIMPLE_HPP
# define AISIMPLE_HPP

#include "Game/AAI.hpp"

namespace indie {

  class AiSimple : public AAI
  {
    public:
      AiSimple(const int &);
      virtual ~AiSimple();
      virtual void loop(const Map &, const int &);
  };

};

#endif /* AISIMPLE_HPP */

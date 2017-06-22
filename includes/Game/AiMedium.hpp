#ifndef AIMEDIUM_HPP
# define AIMEDIUM_HPP

#include "Game/AAI.hpp"

namespace indie {

  class AiMedium : public AAI
  {
    public:
      AiMedium(const int &);
      virtual ~AiMedium();
      virtual void loop(const Map &, const int &);
  };

};

#endif /* AIMEDIUM_HPP */

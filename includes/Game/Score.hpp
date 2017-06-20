//
// Author: Maud Marel 
// Date: 2017-06-17 18:34:07 
//

#ifndef SCORE_HPP_
# define SCORE_HPP_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

namespace indie
{
    class   Score
    {
        std::vector<int>            _scores;
        std::vector<std::string>    _dates;

    public:
        Score();
        ~Score();
        int get_bigger_score();
        void add_score(int);
        std::string get_date();
        std::vector<int>    GetScores() const;
        std::vector<std::string>    GetDates() const;
    };
}

#endif /* !SCORE_HPP_ */
//
// Author: Maud Marel 
// Date: 2017-06-17 18:44:40 
//

#include <ctime>
#include "Game/Score.hpp"

indie::Score::Score() : _scores(), _dates()
{
  std::string line;
  std::size_t found;
  std::string str;
  int           score;
  std::string::size_type sz;
  std::ifstream   file(".score.txt");

  if (file.is_open())
  {
    while (getline(file,line))
    {
      found = line.find(" ");
      str = line.substr(0, found);
      score = std::stoi(str, &sz);
      _scores.push_back(score);
      str = line.substr(found + 1, line.size());
      _dates.push_back(str);
    }
    file.close();
  }
}

indie::Score::~Score()
{
}

int  indie::Score::get_bigger_score()
{
  int max;
  int pos;
  unsigned int i;

  i = 0;
  pos = 0;
  max = _scores[pos];
  while (i < _scores.size())
  {
    if (_scores[i] > max)
    {
      pos = i;
      max = _scores[pos];
    }
    i++;
  }
  return (pos);
}

std::string indie::Score::get_date()
{
  time_t    t;
  struct tm datetime;
  char      date[32];
 
  time(&t);
  datetime = *localtime(&t);
  strftime(date, 32, "%d.%m.%Y", &datetime);
  return (date);
}

void  indie::Score::add_score(int score)
{
  unsigned int nb = 0;
  int max;
  std::ofstream file(".score.txt");
  long unsigned int size;

  _scores.push_back(score);
  _dates.push_back(get_date());
  if (file.is_open())
  {
    size = _scores.size();
    while (nb < 5 && nb < size)
    {
      max = get_bigger_score();
      file << _scores[max];
      file << " ";
      file << _dates[max];
      file << "\n";
      _scores.erase(_scores.begin() + max);
      _dates.erase(_dates.begin() + max);
      nb++;
    }
    file.close();
  }
}

std::vector<int>  indie::Score::GetScores() const
{
  return (_scores);
}

std::vector<std::string>  indie::Score::GetDates() const
{
  return (_dates);
}
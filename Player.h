#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <sstream>


class Player {
protected:
	int health;
	float *position;
	int team;
	std::ostringstream oss;
	std::string getPositionAsJson();


public:
	int getHealth();
	int getTeam();
	float* getPosition();
	virtual std::string toString() = 0;

};


#endif

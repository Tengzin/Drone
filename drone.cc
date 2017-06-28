/*
Drone.cc
*/
#include "drone.h"		

Position::Position( int ew, int ns)	: ew{ew}, ns{ns} {}
int test = 1;
int track[51] = {0};
Drone::Drone() : currpos{}, direction{}, 
prevns{}, prevew{}, 
step{test} {}
Drone::~Drone() {}

void Drone:: forward() {
	if (this->direction == 0) this->currpos.ns++;
	else if (this->direction == 1) this->currpos.ew++;
	else if (this->direction == 2) this->currpos.ns--;
	else this->currpos.ew--;
	this->prevns[this->step] = this->currpos.ns;
	this->prevew[this->step] = this->currpos.ew;
	this->step++;
}
void Drone:: backward() {
	if (this->direction == 0) this->currpos.ns--;
	else if (this->direction == 1) this->currpos.ew--;
	else if (this->direction == 2) this->currpos.ns++;
	else this->currpos.ew++;
	this->prevns[this->step] = this->currpos.ns;
	this->prevew[this->step] = this->currpos.ew;
	this->step++;
}
void Drone:: left() {
	if (this->direction == 0) {
		this->direction = 3;
	}
	else this->direction--;		
};
void Drone:: right() {
	if (this->direction == 3) this->direction = 0;
	else this->direction++;
}
Position Drone:: current() const {
	return this->currpos;
}
int Drone:: totalDistance() const {
	return (this->step - 1);
}
int Drone:: manhattanDistance() const {
	int total = 0;
	if (this->currpos.ns < 0) {
		total += (0 - this->currpos.ns);
	}
	else total += this->currpos.ns;
	if (this->currpos.ew < 0) {
		total += (0 - this->currpos.ew);
	}
	else total += this->currpos.ew;
	return total;
}
bool Drone:: repeated() const {
	int ns = this->currpos.ns;
	int ew = this->currpos.ew;
	const int count = this->step - 1;

	for (int i = 0; i < count; i++) {
		if (ns == this->prevns[i] && ew == this->prevew[i]) return true;
	}
	return false;		
}

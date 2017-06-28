#ifndef DRONE_H
#define DRONE_H

struct Position {
  int ew, ns;
  Position( int ew = 0, int ns = 0 );
};

struct Drone {
  Drone();
  ~Drone();
  void forward(); 
  void backward(); 
  void left();
  void right();
  Position current() const;
  int totalDistance() const;
  int manhattanDistance() const;
  bool repeated() const;

  private:
	Position currpos;
	int direction = 0;	
	int prevns[51];
	int prevew[51];	
	int step = 1;		
};

#endif
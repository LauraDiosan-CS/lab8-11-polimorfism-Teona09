#pragma once
class Square{
private:
	int x;
	int y; 
	char state; // 'O' - not attacked
				// 'M' - attacked and miss
				// 'H' - attacked and hit
				// 'D' - attacked and the ship is down
	char occupied;	// 'C' - clear, no airplane
					// 'A' - airplane
public:
	Square();
	Square(int x, int y);
	static Square makeSquare(int x, int y);
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
	char getState()const;
	void setState(char state);
	char getOccupied() const;
	void setOccupied();
	bool operator==(const Square& other)const;
	bool operator!=(const Square& other)const;
	Square& operator=(const Square& other);
	~Square(){}
};


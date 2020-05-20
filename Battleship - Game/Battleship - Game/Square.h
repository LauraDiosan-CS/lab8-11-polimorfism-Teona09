#pragma once
class Square{
private:
	int x;
	int y; 
public:
	enum State {
		NOT_ATTACKED=1,
		ATTACKED_MISS=0,
		ATTACKED_HIT=2
	};

	Square();
	Square(int x, int y);
	static Square makeSquare(int x, int y);
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
	bool operator==(const Square& other)const;
	bool operator!=(const Square& other)const;
	Square& operator=(const Square& other);
	~Square(){}
};


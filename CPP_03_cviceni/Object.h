#pragma once
#ifndef OBJECT_H
#define OBJECT_H

class Object {
private:
	int id;
	double x;
	double y;
public:
	Object(int id);
	virtual ~Object() {};
	double GetX() const;
	void SetX(double x);
	double GetY() const;
	void SetY(double y);
	int GetId() const;

};

#endif // !OBJECT_H

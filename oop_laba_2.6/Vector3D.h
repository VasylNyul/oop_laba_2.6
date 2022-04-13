#pragma once
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Vector3D
{
public:
	class Triad
	{
	private:

		int x, y, z;

	public:
		int get_x() const { return x; }
		int get_y() const { return y; }
		int get_z() const { return z; }

		void set_x(int x) { this->x = x; };
		void set_y(int y) { this->y = y; };
		void set_z(int z) { this->z = z; };

		Triad();
		Triad(int, int, int);
		Triad(const Triad&);

		Triad& operator = (const Triad&);

		friend ostream& operator << (ostream& out, const Triad& m);
		friend istream& operator >> (istream& in, Triad& m);

		friend Triad operator + (const Triad&, const Triad&);
		friend Triad operator * (const Triad&, const Triad&);

		bool init(int x, int y, int z);
		void display() const;
		void read();

		friend bool operator == (Triad&, Triad&);
		friend bool operator != (Triad&, Triad&);

		operator string () const;

		Triad& operator ++();
		Triad& operator --();
		Triad operator ++(int);
		Triad operator --(int);

		~Triad(void) {};
	};
private:
	Triad triad;
public:
	Triad get_Triad() const { return triad; }
	void set_Triad(Triad triad) { this->triad = triad; }

	Vector3D() :triad() {}
	Vector3D(const Triad t) :triad(t) {}
	Vector3D(const Vector3D& t) { triad = t.triad; }

	void init(Triad triad) { set_Triad(triad); }
	void display() const;
	void read();

	friend ostream& operator <<(ostream& out, const Vector3D& c);
	friend istream& operator >>(istream& in, Vector3D& c);

	operator string () const;

	friend Vector3D operator + (const Vector3D&, const Vector3D&);
	friend int operator * (const Vector3D, const Vector3D);

	Vector3D& operator++();
	Vector3D& operator--();
	Vector3D operator++(int);
	Vector3D operator--(int);

	~Vector3D(void) {};
};
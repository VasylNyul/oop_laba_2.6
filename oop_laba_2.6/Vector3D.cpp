#include "Vector3D.h"

///Triad.cpp
Vector3D::Triad::Triad()
	: x(0), y(0), z(0)
{}

Vector3D::Triad::Triad(int a, int b, int c)
	: x(a), y(b), z(c)
{}

Vector3D::Triad::Triad(const Vector3D::Triad& f)
	: x(f.x), y(f.y), z(f.z)
{}

bool Vector3D::Triad::init(int x, int y, int z)
{
	set_x(x);
	set_y(y);
	set_z(z);

	return true;
}
void Vector3D::Triad::display() const
{
	cout << endl;
	cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}
void Vector3D::Triad::read()
{
	int x, y, z;

	cout << endl;
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	cout << "z = "; cin >> z;
	init(x, y, z);
}

Vector3D::Triad& Vector3D::Triad::operator = (const Vector3D::Triad& f)
{
	this->x = f.x;
	this->y = f.y;
	this->z = f.z;

	return *this;
}

Vector3D::Triad::operator string () const
{
	stringstream ss;

	ss << "(" << x << ", " << y << ", " << z << ")" << endl;

	return ss.str();
}

Vector3D::Triad& Vector3D::Triad:: operator ++()
{
	++x;
	return *this;
}

Vector3D::Triad& Vector3D::Triad:: operator --()
{
	--x;
	return *this;
}
Vector3D::Triad Vector3D::Triad:: operator ++(int)
{
	Triad t(*this);
	++y;
	return t;
}
Vector3D::Triad Vector3D::Triad:: operator --(int)
{
	Triad t(*this);
	--y;
	return t;
}

ostream& operator <<(ostream& out, const Vector3D::Triad& f)
{
	out << string(f);
	return out;
}
istream& operator >>(istream& in, Vector3D::Triad& f)
{
	int x, y, z;
	cout << endl;
	cout << "x = "; in >> x;
	cout << "y = "; in >> y;
	cout << "z = "; in >> z;
	f.init(x, y, z);
	return in;
}


Vector3D::Triad operator +(const Vector3D::Triad& a, const Vector3D::Triad& b)
{
	Vector3D::Triad t;
	t.x = a.x + b.x;
	t.y = a.y + b.y;
	t.z = a.z + b.z;
	return t;
}

Vector3D::Triad operator *(const Vector3D::Triad& a, const Vector3D::Triad& b)
{
	Vector3D::Triad t;
	t.x = a.x * b.x;
	t.y = a.y * b.y;
	t.z = a.z * b.z;
	return t;
}

bool operator == (Vector3D::Triad& f, Vector3D::Triad& s)
{
	return f.x == s.x && f.y == s.y && f.z == s.z;
}

bool operator != (Vector3D::Triad& f, Vector3D::Triad& s)
{
	return !(f.x == s.x && f.y == s.y && f.z == s.z);
}

///Vector3d.cpp

void Vector3D::display() const
{
	cout << endl;
	cout << "vector = " << endl;
	triad.display();
}
void Vector3D::read()
{
	Triad t;
	cout << endl;
	cout << "Vector = " << endl;
	t.read();
	init(t);
}


ostream& operator << (ostream& out, const Vector3D& f)
{
	out << string(f);
	return out;
}

istream& operator >> (istream& in, Vector3D& f)
{

	in >> f.triad;

	return in;
}

Vector3D::operator string() const
{
	return string(triad);
}

Vector3D operator +(const Vector3D& o, const Vector3D& u)
{
	Vector3D s;
	int a = o.triad.get_x() + u.triad.get_x();
	int b = o.triad.get_y() + u.triad.get_y();
	int c = o.triad.get_z() + u.triad.get_z();

	s.triad.set_x(a);
	s.triad.set_y(b);
	s.triad.set_z(c);

	return s;
}

int operator * (const Vector3D o, const Vector3D u)
{

	int a = o.triad.get_x() * u.triad.get_x();
	int b = o.triad.get_y() * u.triad.get_y();
	int c = o.triad.get_z() * u.triad.get_z();

	int s = a + b + c;

	return s;
}

Vector3D& Vector3D::operator++()
{
	triad++;
	return*this;
}

Vector3D& Vector3D::operator--()
{
	triad++;
	return*this;
}

Vector3D Vector3D::operator++(int)
{
	Vector3D s(*this);
	triad++;
	return s;
}

Vector3D Vector3D::operator--(int)
{
	Vector3D s(*this);
	triad--;
	return s;
}
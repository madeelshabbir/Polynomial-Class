#include<iostream>
#include<string>
using namespace std;
class Term {
private:
	int coefficient;
	char variable;
	int exponent;
public:
	Term() {
		coefficient = 0;
		variable = 'x';
		exponent = 0;
	}
	Term(int c, int e) {
		coefficient = c;
		variable = 'x';
		exponent = e;
	}
	void setCoefficient(int n) {
		coefficient = n;
	}
	void setExponent(int n) {
		exponent = n;
	}
	char getVariable() {
		return variable;
	}
	int getCoefficient() {
		return coefficient;
	}
	int getExponent() {
		return exponent;
	}
};
class Polynomial {
private:
	Term* poly;
	int degree;
public:
	Polynomial() {
		poly = new Term[5];
		degree = 0;
	}
	Polynomial(const Polynomial& p) {
		poly = new Term[5];
		for (int i = 0; i < p.degree; i++) {
			poly[i].setCoefficient(p.poly[i].getCoefficient());
			poly[i].setExponent(i);
		}
		degree = p.degree;
	}
	~Polynomial() {
		delete[] poly;
	}
	void append(int n) {
		if (degree >= 5) {
			cout << "Max limit Reached" << endl;
			return;
		}
		poly[degree].setCoefficient(n);
		poly[degree].setExponent(degree);
		degree++;
	}
	Polynomial operator+(const Polynomial& p) const {
		Polynomial tmp;
		if (degree >= p.degree)
			tmp.degree = degree;
		else
			tmp.degree = p.degree;
		for (int i = 0; i < tmp.degree; i++) {
			tmp.poly[i].setCoefficient(poly[i].getCoefficient() + p.poly[i].getCoefficient());
			tmp.poly[i].setExponent(i);
		}
		return tmp;
	}
	Polynomial operator-(const Polynomial& p) const {
		Polynomial tmp;
		if (degree >= p.degree)
			tmp.degree = degree;
		else
			tmp.degree = p.degree;
		for (int i = 0; i < tmp.degree; i++) {
			tmp.poly[i].setCoefficient(poly[i].getCoefficient() - p.poly[i].getCoefficient());
			tmp.poly[i].setExponent(i);
		}
		return tmp;
	}
	Polynomial operator*(const Polynomial& p) const {
		if (degree + p.degree > 5) {
			cout << "Not Possible" << endl;
			throw 0;
		}
		Polynomial tmp;
		for (int i = 0; i < degree; i++) {
			for (int j = 0; j < p.degree; j++) {
				tmp.poly[i + j].setCoefficient(tmp.poly[i + j].getCoefficient() + poly[i].getCoefficient() * p.poly[j].getCoefficient());
				tmp.poly[i + j].setExponent(i);
			}
		}
		tmp.degree = degree + p.degree;
		return tmp;
	}
	Polynomial& operator=(const Polynomial& p) {
		if (this != &p)
		{
			for (int i = 0; i < p.degree; i++) {
				poly[i].setCoefficient(p.poly[i].getCoefficient());
				poly[i].setExponent(i);
			}
			degree = p.degree;
		}
		return *this;
	}
	Polynomial& operator+=(const Polynomial& p) {
		if (degree < p.degree)
			degree = p.degree;
		for (int i = 0; i < degree; i++) {
			poly[i].setCoefficient(poly[i].getCoefficient() - p.poly[i].getCoefficient());
			poly[i].setExponent(i);
		}
		return *this;
	}
	Polynomial& operator*=(const Polynomial& p) {
		if (degree + p.degree > 5) {
			cout << "Not Possible" << endl;
			throw 0;
		}
		Polynomial tmp;
		for (int i = 0; i < degree; i++) {
			for (int j = 0; j < p.degree; j++) {
				poly[i + j].setCoefficient(poly[i + j].getCoefficient() + poly[i].getCoefficient() * p.poly[j].getCoefficient());
				poly[i + j].setExponent(i);
			}
		}
		return *this;
	}
	void show() {
		for (int i = 0; i < degree; i++)
			cout << poly[i].getCoefficient() << poly[i].getVariable() << poly[i].getExponent() << " ";
		cout << endl;
	}
};
int main() {
	Polynomial p, q;
	p.append(2);
	p.append(4);
	p.append(5);
	q.append(2);
	q.append(5);
	(p + q).show();
	(p - q).show();
	(p * q).show();
	system("pause");
}
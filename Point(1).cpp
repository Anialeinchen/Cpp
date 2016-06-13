/* Point.cpp (Vorgabe)
 *
 * Die Klasse der Punkte einer Ebene mit x- und y-Koordinate 
 * und der Methode absolutes Verschieben
 */

#include <iostream>
#include <cmath>
using namespace std;


class Point
	{
	public:
		int x;
		int y;

		Point(){
				x = 0;
				y = 0;
			
		}
		Point(int movX, int movY){
				this->x = movX;
				this->y = movY;
		}
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}

		void moveTo(int xneu, int yneu){
			x = xneu;
			y = yneu;
		}

		void moveRel(int xneu, int yneu){
			x = x + xneu;
			y = y + yneu;
		}

		int distance(){
			return sqrt(x*x + y*y);
		}

	friend class PointFriend;
};



class PointFriend{
public:
	//PointFriend();

	void resetPt(PointFriend * p);
};

void Point::resetPt(Point * p){
	p->moveTo(0,0);
}


//extern Point p;

int main() {

	Point p;

	cout << "p = (" << p.getX() << ",";
	cout << p.getY() << ")" << endl;

	cout << "Jetzt wird p auf (4,5) verschoben." << endl;
	p.moveTo(4,5);
	cout << "p = (" << p.getX() << ",";
	cout << p.getY() << ")" << endl;

	Point q(3,9);

	Point * ptr;
	ptr = &q;
	
	cout << "q = (" << q.getX() << ",";
		cout << q.getY() << ")" << endl;

	cout << "Jetzt wird q auf (4,5) verschoben." << endl;
	q.moveTo(4,5);
	cout << "q = (" << q.getX() << ",";
	cout << q.getY() << ")" << endl;


	cout << "Jetzt wird q auf ( ursprungspos + 40, ursprungspos + 5) verschoben." << endl;
	q.moveRel(40,5);
	cout << "q = (" << q.getX() << ",";
	cout << q.getY() << ")" << endl;

	cout << "distance vom q zu dem Koordinaten Anfang." << endl;

	cout << "distance = " << q.distance() << endl;

	PointFriend::resetPt(ptr);
	cout << "q = (" << q.getX() << ",";
	cout << q.getY() << ")" << endl;

return 0;
}

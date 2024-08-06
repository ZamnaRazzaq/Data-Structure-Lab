#include<iostream>
using namespace std;
class rectangle;
class Shape{
	int legnth;
	int width;
public:
	friend class rectangle;
	Shape(int x=0 , int y=0){
		legnth = x;
		width = y;
	}
	void setlegnth(int a){
		legnth = a;
	}
	int getlegnth(){
		return legnth;
	}
	void setwidth(int b){
		width = b;
	}
	int getwidth(){
		return width;
	}
	~Shape(){
	}
};
class rectangle{
	int  area;
	int  perimeter;
public:

	void calculateArea(Shape &obj){
		area= obj.getlegnth()*obj.getwidth();
		cout << "Area of the rectangle: " << area<<endl;
	
	}
	void calculatePeri(Shape &obj){
		perimeter = 2 * obj.getlegnth() + 2 * obj.getwidth();
		cout << "Perimeter of the rectangle: " << perimeter;

	}

};

int main(){
	int l, w;
	cout << "Enter legnth";
	cin >> l;
	cout << "Enter width";
	cin >> w;
	Shape  S(l, w);
	rectangle R;
	R.calculateArea(S);
	R.calculatePeri(S);
	system("pause");

}
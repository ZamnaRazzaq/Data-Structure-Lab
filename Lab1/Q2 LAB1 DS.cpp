#include <iostream>
using namespace std;
 template <class T, class U>
 class Dataobject {
 private:
	 T data;
	 U key;
	 Dataobject* link;
 public:
	 Dataobject() {
		 data = NULL;
		 key = NULL;
		 link = NULL;
	 }
	 Dataobject(T x, U y) {
		 data = x;
		 key = y;
		 link=NULL;
	 }
	 void setdata(T d) {
		 data = d;
	 }
	 void setkey(U k) {
		 key = k;
	 }
	 void setlink(Dataobject* l) {
		 link = l;
	 }
	 T getdata() {
		 return data;
	 }
	 U getkey() {
		 return key;
	 }
	 Dataobject* getlink() {
		 return link;
	 }
	 ~Dataobject() {
			 if (link != nullptr)
			 {
				 link = nullptr;
			 }
		 
	 }
	 void operator =(const Dataobject& obj) {
		 data = obj.data;
		 key = obj.key;
		 link = obj.link;
	 }
	 bool operator ==(const Dataobject& OBJ) {
		 if (data == OBJ.data & key == OBJ.key) {
			 return true;
		 }
		 else {
			 return false;
		 }
	 }

 };
 int main()
 {
	 Dataobject<int, char>obj1 = Dataobject<int, char>(97, 'a');
	 Dataobject<int, char>obj2 = Dataobject<int, char>(obj1);
	 Dataobject<int, char>obj3 = Dataobject<int, char>(1,'x');
	 ((obj1 == obj2)) ? cout << "objects are equal" : cout << "objects are not equal ";
	 obj2.setlink(&obj1);
	 obj2.setdata('b');
	 obj2.setkey(98);
	 cout << endl;
	 cout << "[" << obj1.getdata() << " : " << obj1.getkey() << ": " << obj1.getlink() << " ] ";
	 obj1.~Dataobject();
	 cout << endl;
	 cout << "[" << obj2.getdata() << " : " << obj2.getkey() << ": " << obj2.getlink() << " ] ";
	 cout << endl;
	 cout << "[" << obj3.getdata() << " : " << obj3.getkey() << ": " << obj3.getlink() << " ] ";
	 obj3 = obj2;
	 obj2.~Dataobject();
	 cout << endl;
	 cout << "[" << obj3.getdata() << " : " << obj3.getkey() << ": " << obj3.getlink() << " ] ";
	 cout << endl;
	 obj3.~Dataobject();
	 system("pause");

	 
 }
#include<iostream>
using namespace std;
class students {
	int rollnumber;
	string name;
	float cgpa;
public:
	students() {

	}
	~students() {

	}
	void setroll(int A) {
		rollnumber = A;
	}
	int getroll() {
		return rollnumber;
	}
	void setname(string B) {
		name = B;
	}
	string getname() {
		return name;
	}
	void cgpa(int C) {
		cgpa=C;
	}
	float getcgpa() {
		return cgpa;
	}
	friend ostream& operator<<(ostream& out, const students& s) {
		out << s.rollnumber << " " << s.name << " " << s.cgpa << " ";
		return out;
	}
};
int main() {


}
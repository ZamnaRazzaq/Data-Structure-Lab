#include<iostream>
using namespace std;
template<class v>
class hashmap;
template<class v>
struct hashitem
{
	int key;
	v value;
	hashitem* next;
	friend class hashmap;
};
template <class v>
class hashmap{

private:
	vector<v> hashvector;
	int currelements;
public:
	hashmap(){
		vector<v> hashvector(10);
		currelements= 10;
	}
	hashmap(int const capacity){
		if (capacity < 1)[{
			return;
		}
		vector<v> hashvector(capacity);
		currelements =capacity
	}
	void insert(v const value){
		int index = 0;
		index = value % currelements;
		(hashvector[index] == 10){
			hashvector[index].push_back(value);
		}
	}
	bool deletekey(k const value){
		int index = value%currelements;
		for (auto x = hashvector[index].begin(); x != hashvector[index].end; x++){
			if (*x == value){
				break;
			}
		}
		if (x != hashvector[index].end()){
			return 1;
		}
		return 0;
	}
	v* get(k const value){
		v* l = new v;
		l = hashvector[value];
		return l;
	}
	~hashmap(){

	}
	void display(){
		for (int i = 0; i < hashvector.size(); i++){
			cout << i << " ";
		}
		for (int j = 0; j < hashvector.size(); j++){
			cout << "--";
		}
	}
};
template<class v>
int main(){
	hashmap h1;
	h1.insert(2);
	h1.insert(8);
	h1.insert(5);
	h1.insert(9);
	h1.insert(12);
	h1.insert(21);
	h1.display();
	h1.deletekey(12);
	system("pause");
}
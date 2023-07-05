//#include <iostream>
//using namespace std;
//class Creature {
//	string name;
//	int age;
//	int numberofchild;
//public:
//	Creature(string a_name, int a_age, int a_namberofchild) {
//		age = a_age;
//		name = a_name;
//		numberofchild = a_namberofchild;
//	}
//	int getage() {
//		return age;
//	}
//	int getnumberofchild() {
//		return numberofchild;
//	}
//	string getname() {
//		return name;
//	}
//	virtual void print() {
//		cout << "the age is" << age << "the name is" << name << endl;
//	}
//};
//class Vampire :virtual public Creature {
//	int lightsensitivity;
//	Vampire** a;
//public:
//	Vampire(int num, string s_name, int s_age, int s_namberofchild) : Creature(s_name, s_age, s_namberofchild) {
//		lightsensitivity = num;
//	}
//	virtual void print() {
//		Creature::print();
//		cout << "the lightsensitivity is" << lightsensitivity << endl;
//	}
//	virtual int getlight() {
//		return lightsensitivity;
//	}
//};
//class Werewolf : virtual public Creature {
//	int manlike, wolflike;
//	Werewolf** b;
//public:
//	Werewolf(int num1,int num2, string w_name, int w_age, int w_namberofchild) : Creature(w_name, w_age, w_namberofchild) {
//		manlike = num1;
//		wolflike = num2;
//	}
//	virtual void print() {
//		Creature::print();
//		cout << "the manlike is" << manlike << "the wolflike is" << wolflike << endl;
//	}
//	virtual void printmanlikeandwolflike() {
//		cout << "the manlike is" << manlike << "the wolflike is" << wolflike << endl;
//	}
//};
//class vampirewerwolf :public Vampire, public Werewolf {
//	Creature** c;
//public:
//	vampirewerwolf(int x_num1, int x_num2, int x_num3, string x_name, int x_age, int x_numberofchild) :Vampire(x_num1, x_name, x_age, x_numberofchild), Werewolf(x_num2, x_num3, x_name, x_age, x_numberofchild), Creature(x_name, x_age,x_numberofchild) {
//	}
//	virtual void print() {
//		Vampire::print();
//		Werewolf::printmanlikeandwolflike();
//	}
//};
//void main() {
//	Vampire a(2, "moran", 3, 4);
//	a.print();
//	Creature** x= new Creature*[5];
//	x[0] = new Vampire(3, "moran", 4, 5);
//	x[1]= new Vampire(6, "noa", 7, 8);
//	x[2]= new Werewolf(1, 2, "iren", 12, 2);
//	x[3]= new Werewolf(2, 3, "miki", 5, 4);
//	x[4]= new vampirewerwolf (3, 4, 5, "OMER", 15, 4);
//	int num = 0;
//	for (int i = 0; i < 5; i++) {
//		if (typeid(*x[i]) == typeid(Vampire))
//			num++;
//	}
//	int num1 = 0;
//	int avg = 0;
//	cout << "the number of only vampire is" << num << endl;
//	for (int i = 0; i < 5; i++) {
//		Vampire* v = dynamic_cast <Vampire*>(x[i]);
//		if (v != NULL) {
//			num1++;
//			avg = avg + v-> getlight();
//		}
//	}
//	cout << "the number of all kind of vampire is" << num1 << endl;
//	cout << "the avg of light sensativity is" << avg / num1 << endl;
//}
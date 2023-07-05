//#include <iostream>
//#include <fstream>
//using namespace std;
////int main() {
////	ofstream Outfile("player1.txt");
////	Outfile << "score 25"<< 25 << endl;
////	Outfile.close();
////
////	int score;
////	char str[50];
////
////	ifstream Infile("player1.txt");
////	Infile >> str >> score;
////	cout << str << endl << score << endl;
////	Infile.seekg(0);
////	Infile.getline(str, sizeof(str));
////	cout << str << endl;
////	Infile.close();
////}
//class Employee {
//	char* name;
//	int age;
//	int salary;
//public:
//	Employee(){}
//	Employee(char* a_name, int a_age, int a_salary) {
//		name = a_name; 
//		age = a_age;
//		salary = a_salary;
//	}
//	virtual void save(ofstream& out) {
//		int n = strlen(name);
//		cout << n << endl;
//		out.write((char*)&n, sizeof(n));
//		out.write(name, n);
//		out.write((char*)&age, sizeof(age));
//		out.write((char*)&salary, sizeof(salary));
//	}
//	virtual void load(ifstream& in) {
//		int n;
//		in.read((char*)&n, sizeof(n));
//		name = new char[n + 1];
//		in.read(name, n);
//		name[n] = '\0';
//		in.read((char*)&age, sizeof(age));
//		in.read((char*)&salary, sizeof(salary));
//	};
//	void savetipe(ofstream& out) const {
//		char type[2];
//		strncpy_s(type, typeid(*this).name()+6, 2);
//		out.write((char*)type, 2);
//	}
//};
//class Engineer :public Employee {
//	int tipeofdegree;
//public:
//	Engineer(char* a_name, int a_age, int a_salary, int a_tipeofdegree) : Employee(a_name, a_age, a_salary) {
//		tipeofdegree = a_tipeofdegree;
//	}
//	virtual void save(ofstream& out) {
//		Employee::save(out);
//		out.write((char*)&tipeofdegree, sizeof(tipeofdegree));
//	};
//	virtual void load(ifstream& in) {
//		Employee::load(in);
//		in.read((char*)&tipeofdegree, sizeof(tipeofdegree));
//	};
//};
//class Managerr :public Employee {
//	double level;
//public:
//	Managerr (char* a_name, int a_age, int a_salary, double a_level) : Employee(a_name, a_age, a_salary) {
//		level = a_level;
//	}
//	virtual void save(ofstream& out) {
//		Employee::save(out);
//		out.write((char*)&level, sizeof(level));
//	};
//	virtual void load(ifstream& in) {
//		Employee::load(in);
//		in.read((char*)&level, sizeof(level));
//	};
//};
//int main() {
//	ofstream out;
//	out.open("out.bin", ios::binary);
//	int size;
//	cout << "how many employee you whant?" << endl;
//	cin >> size;
//	Employee** empolyees1 = new Employee*[size];
//	char* name1 = new char();
//	int age, salary;
//	int type;
//	for (int i = 0; i < size; i++) {
//		cout << "writh the thing for your employee " << endl;
//		cin >> name1 >> age >> salary;
//		int len = std::strlen(name1);
//		char* name2 = new char[len + 1];
//		strcpy_s(name2, len + 1, name1);
//		cout << "what tipe of wmployee? for Engineer press 1 and for manager press 2? " << endl;
//		cin >> type;
//		if (type == 1) {
//			int tipeofdegree = 5;
//			empolyees1[i] = new Engineer(name2, age, salary, tipeofdegree);
//			empolyees1[i]->savetipe(out);
//			empolyees1[i]->save(out);
//		}
//		if (type == 2) {
//			double level = 25;
//			empolyees1[i] = new Managerr(name2, age, salary, level);
//			empolyees1[i]->savetipe(out);
//			empolyees1[i]->save(out);
//		}
//	}
//};
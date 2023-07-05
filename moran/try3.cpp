//#include <iostream>
//using namespace std;
//class DivisionByException {
//	const char* description = "error: division by ziro";
//	public:
//		const char* getDescription(){
//			return description;
//		}
//		void Print() {
//			cout << description << endl;
//		}
//};
//
//double div1(double a, double b) throw (int, DivisionByException) {
//	if (a < b)
//		throw - 1;
//	if (b == 0)
//		throw DivisionByException();
//	return a / b;
//}
//int main() {
//	try {
//		int x, y;
//		cout << "input x,y" << endl;
//		cin >> x >> y;
//		cout << div1(x, y)<< endl;
//	}
//	catch (int a) {
//		if (a == -1)
//			cout << "x is smaller than y" << endl;
//	}
//	catch (DivisionByException& e) {
//		e.Print();
//	}
//	catch (...) {
//		cout << "unknown error has occurred" << endl;
//	}
//	return 0;
//}
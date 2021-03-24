#include <iostream>
#include "Var.h"
using namespace std;
int main() {
	Var tmp = 333.2;
	Var tmp2 = 333.1;
	//tmp.show();
	Var res = tmp+tmp2;
	cout << tmp.getPos() << tmp2.getPos()<<endl;
	res.show();
	cout << "\nResult: "<<res<<endl;
	res = tmp * tmp2;
	cout << "\nResult: "<<res<<endl;
	tmp = "Test";
	tmp2 = "Tesla";
	
	res = tmp * tmp2;
	
	res += tmp2;
	cout << res.getPos() << endl;
	cout<< "+= string result: "<<res<<endl;
	Var res2 = res;
	cout << boolalpha << (res == res) << endl;
	return 0;
}
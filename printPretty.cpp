#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        cout << 
        std::left <<
        std::hex <<
        std::showbase << 
        std::nouppercase <<
        long(A) <<
        endl;
        char sign = B > 0 ? '+':'-';
        cout.precision(2);
        cout <<
        fixed <<
        std::setw(12-std::to_string(long(B)).size()) <<
        std::right <<
        std::setfill('_') <<
        sign <<
        B <<
        endl;
        cout.precision(9);
        cout << std::uppercase << scientific << C << endl;
	}
	return 0;

}

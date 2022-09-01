#include <iostream>
#include<fstream>

using namespace std;

int main() //主函数
{

    ifstream fin;
    ofstream fout;
    string s  ;

    fout.open("try.txt", ios::out);

    while(1){
        cout << "ctrl + z quit" << endl;
        cout << "please input" << endl;
        cin >> s;
        fout << s <<endl;

    }
    fout.close();

	return 0;
}

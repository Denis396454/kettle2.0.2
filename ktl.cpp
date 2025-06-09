#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    
    string user;
    cin >> user;
    fstream output;
    fstream code;
    string line;
    

    output.open("a.cpp");
    code.open(user);
    output << "#include <iostream>\nusing namespace std;\nint main(){\n";
    while (getline(code, line)) {
        cout << "hi";
        if (line.size() >= 5 && line.substr(0, 5) == "print"){
            output << "    cout << " << line.substr(6) << " << endl;\n";
        }
        else if (line.size() >= 3 && line.substr(0, 3) == "var"){
            output << "    auto " << line.substr(4, line.size()) << ";\n";
        }
	else if (line.size() >= 3 && line.substr(0, 3) == "for"){
	    output << "for ( " << line.substr(4, line.size()) << "){\n";
	}
	else if (line.size() >= 1 && line == "}"){
	    output << "}\n";
	}
    }
    output << "    return 0;\n}";
    output.close();
    code.close();

    return 0;
}
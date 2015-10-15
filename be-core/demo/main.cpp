#include <iostream>
#include <string>
#include <boost/any.hpp>

#include "be-designer.h"
#include "project.h"

using namespace std;
using namespace bd;
using namespace boost;


int main(int argc, char* argv[]){
    bd::Session session;
    session.chain(std::string("cpptst"), true);
    cout << "Done!" << endl;
    /*
    Datafield b1, b2;
    any v1 = std::string("Àîº£·å12321hjkah");
    any v2 = 123;
    
    b1.setValue(v1);
    cout << b1.toString() << endl;
    b1.setValue(v2);
    cout << b1.toString() << endl;
    */
}
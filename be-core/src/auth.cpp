#include "Auth.h"
#include<ctime> 
using namespace bd;

Auth::Auth():_authed(false),_user(""),_loginTime(-1){

}

Auth::~Auth(){

}

bool Auth::login(const std::string& user, const std::string& passwd){
	if (user == passwd) {
		this->_user = user;
		this->_authed = true;
		time_t now = time(NULL);
		this->_loginTime = now;
		return true;
	}
    return false;
}

bool Auth::logout(){
	_user = "";
	_authed = false;
	_loginTime = -1;
    return true;
}
bool Auth::isAuthed(){
	return this->_authed;
}

std::string Auth::getLoginUserName() const{
    return this->_user;
}
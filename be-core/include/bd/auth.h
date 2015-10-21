#ifndef _BE_DESIGNER_AUTH_H_
#define _BE_DESIGNER_AUTH_H_

#include <string>

namespace bd{
    class Auth{
    public:
        Auth();
        ~Auth();
    public:
        virtual bool login(const std::string& user, const std::string& passwd);
        virtual bool logout();
        virtual bool isAuthed();
        virtual std::string getLoginUserName() const;
	protected:
		std::string _user;
		bool _authed;
		int _loginTime;
    };
}

#endif
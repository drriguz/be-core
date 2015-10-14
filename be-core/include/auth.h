#ifndef _BE_DESIGNER_AUTH_H_
#define _BE_DESIGNER_AUTH_H_

#include <string>

namespace bd{
    class Auth{
    public:
        Auth();
        ~Auth();
    public:
        virtual bool login();
        virtual bool logout();
        virtual bool isAuthed();
        virtual std::string getLoginUserName() const;
    };
}

#endif
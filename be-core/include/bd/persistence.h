#ifndef _BE_DESIGNER_MODULE_SUPPORT_H_
#define _BE_DESIGNER_MODULE_SUPPORT_H_

#include <string>
#include <soci.h>
#include "module.h"

namespace bd{
	class Entity {
	public:
		virtual bool save(soci::session &sql) = 0;
	};

	class PersistenceAble {
	public:
		PersistenceAble() {

		}
		~PersistenceAble() {

		}
	public:
		virtual Entity* createObject() = 0;
	};

    class Persistence{
    public:
        Persistence();
        ~Persistence();
    public:
        virtual bool init();
        virtual bool invoke(void* callback);
        virtual bool begin();
        virtual bool commit();
        virtual bool rollback();
        virtual int count(const char* key);
        virtual bool lock(const char* key);
        virtual bool unlock(const char* key);
        virtual bool save(PersistenceAble *module);
        virtual bool update(const Module *Module);
        virtual bool reupdate(const Module *module);
        virtual bool remove(const Module *module);        
        virtual bool get(Module *module);
        virtual bool execute(const char *sql, void* params, ...);
        virtual bool fetch();
        virtual bool close();
    };
}

#endif
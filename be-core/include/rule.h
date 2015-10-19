#ifndef _BE_DESIGNER_RULE_H_
#define _BE_DESIGNER_RULE_H_

namespace bd{
    class Context;
	class Module;
}

namespace bd{
    class Rule{
    public:
		Rule(Module *parent);		
        ~Rule();
    public:
        virtual int getOrder();
        void setOrder(int order);
        virtual bool invoke(Context &context);
        bool operator < (const Rule &m) const;
    protected:
        int _order;
		Module* _parent;
    };
}

#endif
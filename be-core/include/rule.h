#ifndef _BE_DESIGNER_RULE_H_
#define _BE_DESIGNER_RULE_H_

namespace bd{
    class Context;
}

namespace bd{
    class Rule{
    public:
        Rule();
        ~Rule();
    public:
        virtual int getOrder();
        void setOrder(int order);
        virtual bool invoke(Context &context);
        bool operator < (const Rule &m) const;
    protected:
        int _order;
    };
}

#endif
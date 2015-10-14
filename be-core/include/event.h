#ifndef _BE_DESIGNER_EVENT_H_
#define _BE_DESIGNER_EVENT_H_

#include <boost\any.hpp>

namespace bd{
    class Attribute;
}

namespace bd{
    enum EventType{
        DEFAULT,
        ON_CHANGE,
        ON_CLICK,
        ON_DBLCLICK,
        ON_ROW_INSERT,
        ON_ROW_REMOVE,
        ON_STREAM_UPLOAD,
        ON_STREAM_DOWNLOAD,
        ON_PANEL_SHOW,
        ON_PANEL_CLOSE
    };
    
    class Event{
    public:
        Event();
        ~Event();
    public:
        Attribute* getTarget() const;
        EventType getEventType() const;
        boost::any* getData() const;
        void setData(boost::any* value);
    protected:
        Attribute *_target;
        EventType _eventType;
        boost::any *_data;
    };
}

#endif
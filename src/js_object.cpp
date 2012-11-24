// Copyright (c) 2012 Plenluno All rights reserved.

#include "libj/js_object.h"
#include "libj/symbol.h"

namespace libj {

class JsObjectImpl : public JsObject {
 public:
    static Ptr create() {
        return Ptr(new JsObjectImpl());
    }

    virtual void clear() {
        map_->clear();
    }

    virtual Boolean containsKey(const Value& key) const {
        return map_->containsKey(String::valueOf(key));
    }

    virtual Boolean containsValue(const Value& val) const {
        return map_->containsValue(val);
    }

    virtual Value get(const Value& key) const {
        return map_->get(String::valueOf(key));
    }

    virtual Boolean isEmpty() const {
        return map_->isEmpty();
    }

    virtual Set::CPtr keySet() const {
        return map_->keySet();
    }

    virtual Value put(const Value& key, const Value& val) {
        return map_->put(String::valueOf(key), val);
    }

    virtual Value remove(const Value& key) {
        return map_->remove(String::valueOf(key));
    }

    virtual Size size() const {
        return map_->size();
    }

    virtual String::CPtr toString() const {
        LIBJ_STATIC_SYMBOL_DEF(symObject, "[object Object]");
        return symObject;
    }

 private:
    Map::Ptr map_;

    JsObjectImpl() : map_(Map::create()) {}
};

JsObject::Ptr JsObject::create() {
    return JsObjectImpl::create();
}

}  // namespace libj

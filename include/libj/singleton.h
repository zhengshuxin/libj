// Copyright (c) 2012 Plenluno All rights reserved.

#ifndef LIBJ_SINGLETON_H_
#define LIBJ_SINGLETON_H_

#include "libj/value.h"
#include "libj/object.h"
#include "libj/string.h"

namespace libj {

template<typename T>
class SingletonBase
    : public Singleton
    , public ObjectBase {
 private:
    struct NullDeleter {
        void operator()(void const *) const {}
    };

 public:
    static LIBJ_PTR_TYPE(T) instance() {
        static T t;
#ifdef LIBJ_USE_SP
        LIBJ_PTR_TYPE(T) p(&t, NullDeleter());
#else
        LIBJ_PTR_TYPE(T) p(&t);
#endif
        return p;
    }

    Type<String>::Cptr toString() const {
        return String::create();
    }

    bool instanceOf(TypeId id) const {
        return id == Type<Singleton>::id()
            || ObjectBase::instanceOf(id);
    }

 protected:
    SingletonBase() {}
    virtual ~SingletonBase() {}
};

#define LIBJ_SINGLETON(T) public libj::SingletonBase<T> { \
private: \
    friend class libj::SingletonBase<T>; \
    T() : libj::SingletonBase<T>() {} \
    ~T() {} \
public: \
    typedef T* Ptr; \
    typedef const T* Cptr; \
    libj::TypeId type() const { \
        return libj::Type<T>::id(); \
    } \
    bool instanceOf(libj::TypeId id) const { \
        return id == type() \
            || libj::SingletonBase<T>::instanceOf(id); \
    }

}  // namespace libj

#endif  // LIBJ_SINGLETON_H_
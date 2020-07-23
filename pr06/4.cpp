#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>

class ProxyIndex;

class String {
public:
    String(const char *);
    String(const String &);
    ~String();
    const String &operator=(String);
    const String &operator+=(const char *);
    ProxyIndex operator[](size_t);
    const char &operator[](size_t) const;
    explicit operator std::string() const;
    friend class ProxyIndex;
    friend std::ostream &operator<<(std::ostream &, const ProxyIndex &);

protected:
    struct Data;
    Data *ptr_{};
};

struct String::Data {
    size_t cnt_{}, size_;
    char *str_{};
    Data(const char *str) {
        if (str != nullptr) {
            size_ = strlen(str) + 1;
            str_ = new char[size_];
            memcpy(str_, str, size_);
            cnt_ = 1;
        }
    }
    Data(const char *str1, const char *str2) {
        size_ = strlen(str1) + strlen(str2) + 1;
        str_ = new char[size_];
        memcpy(str_, str1, strlen(str1));
        memcpy(str_ + strlen(str1), str2, strlen(str2) + 1);
        cnt_ = 1;
    }
    ~Data() {
        if (!cnt_) {
            delete[] str_;
        }
    }
    Data(const Data &other) = delete;
    Data &operator=(const Data &other) = delete;
};

class ProxyIndex {
public:
    ProxyIndex(String *p, size_t idx) : pstring_{p}, idx_{idx} {}
    const char &operator=(char c) {
        if (pstring_->ptr_->cnt_ > 1) {
            *pstring_ = String(pstring_->ptr_->str_);
        }
        return pstring_->ptr_->str_[idx_] = c;
    }
    friend std::ostream &operator<<(std::ostream &out, const ProxyIndex &obj) {
        out << obj.pstring_->ptr_->str_[obj.idx_];
        return out;
    }

private:
    String *pstring_;
    size_t idx_;
};

String::String(const char *str = nullptr) {
    if (str) {
        ptr_ = new Data{str};
    }
}

String::~String() {
    if (ptr_ && --ptr_->cnt_ < 1) {
        delete ptr_;
    }
}

String::String(const String &other) : ptr_{other.ptr_} {
    if (ptr_) {
        ++ptr_->cnt_;
    }
}

const String &String::operator=(String other) {
    std::swap(ptr_, other.ptr_);
    return *this;
}

const String &String::operator+=(const char *other) {
    if (!ptr_) {
        this->ptr_ = new Data{other};
        return *this;
    }
    String tmp = *this;
    this->~String();
    this->ptr_ = new Data{tmp.ptr_->str_, other};
    return *this;
}

ProxyIndex String::operator[](size_t idx) {
    return ProxyIndex(this, idx);
}

const char &String::operator[](size_t idx) const {
    return ptr_->str_[idx];
}

String::operator std::string() const {
    return ptr_->str_;
}
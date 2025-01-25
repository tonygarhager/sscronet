#include "pch.h"
#include "GURL.h"


Parsed& Parsed::operator=(const Parsed& other) {
    if (this != &other) {
        scheme = other.scheme;
        username = other.username;
        password = other.password;
        host = other.host;
        port = other.port;
        path = other.path;
        query = other.query;
        ref = other.ref;
        potentially_dangling_markup = other.potentially_dangling_markup;
        has_opaque_path = other.has_opaque_path;
        //if (other.inner_parsed_)
        //    set_inner_parsed(*other.inner_parsed_);
        //else
        //    clear_inner_parsed();
    }
    return *this;
}

GURL::GURL() : is_valid_(false) {
}


GURL::GURL(const GURL& other)
    : spec_(other.spec_),
    is_valid_(other.is_valid_),
    parsed_(other.parsed_) {
    if (other.inner_url_)
        inner_url_ = std::make_unique<GURL>(*other.inner_url_);
    // Valid filesystem urls should always have an inner_url_.
    //DCHECK(!is_valid_ || !SchemeIsFileSystem() || inner_url_);
}

GURL& GURL::operator=(const GURL& other) {
    spec_ = other.spec_;
    is_valid_ = other.is_valid_;
    parsed_ = other.parsed_;

    if (!other.inner_url_)
        inner_url_.reset();
    else if (inner_url_)
        *inner_url_ = *other.inner_url_;
    else
        inner_url_ = std::make_unique<GURL>(*other.inner_url_);

    return *this;
}
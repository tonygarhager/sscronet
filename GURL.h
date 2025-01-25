#pragma once
#include <string>
#include <memory>

struct Component//size 0x8
{
	int begin;
	int len;
};
struct Parsed//size 0x48
{
	Parsed& operator=(const Parsed&);
	Component scheme;
	Component username;
	Component password;
	Component host;
	Component port;
	Component path;
	Component query;
	Component ref;
	bool potentially_dangling_markup;
	bool has_opaque_path;
	Parsed* inner_parsed_;
};

class GURL//size 0x5c
{
public:
	GURL();
	GURL(const GURL& other);

	GURL& operator=(const GURL& other);//sub_3185c6

	std::string spec_;
	bool is_valid_;
	Parsed parsed_;
	std::unique_ptr<GURL> inner_url_;
};


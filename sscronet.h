#pragma once
#include <string>
#include <vector>
#include <array>
#include <optional>
#include "GURL.h"

struct SchemeHostPort
{
	std::string scheme_;
	std::string host_;
	uint16_t port_;
};

struct Token
{
	std::array<uint64_t, 2> words_;
};

struct UnguessableToken
{
	Token token_;
};

namespace url
{
	struct Nonce
	{
		UnguessableToken token_;
	};

	struct Origin
	{
		SchemeHostPort tuple_;
		std::optional<Nonce> nonce_;
	};
}

struct NetLogSource
{
	uint32_t kInvalidId;
	int type;
	uint32_t id;
	int start_time;
};


class NetLogWithSource
{
	NetLogSource source_;
	void* non_null_net_log_;
};

class URLRequest
{
public:
	int m_n_00[10];
	NetLogWithSource net_log_;
	void* job_;
	void* upload_data_stream_;
	std::vector<GURL> url_chain_;
	int m_n_50[313];
	int delegate_event_type_534;
	bool calling_delegate_538;
};

struct SchemefulSite
{
	url::Origin site_as_origin_;
};

struct SiteIndex
{
	uint32_t value_;
};

struct FirstPartySetEntry
{
	SchemefulSite primary_;
	int site_type_;
	std::optional<SiteIndex> site_index_;
};

struct FirstPartySetMetadata
{
	std::optional<FirstPartySetEntry> frame_entry_;
	std::optional<FirstPartySetEntry> top_frame_entry_;
};

struct stStr0x8
{
	stStr0x8()
	{
		m_str = NULL;
		m_len = 0;
	}
	stStr0x8(const char* str)
	{
		m_str = str;
		m_len = strlen(str);
	}
	const char* m_str;
	int m_len;
};

struct st0x18
{
	std::string m_str_00;
	std::string m_str_0c;
};

class URLRequestHttpJob
{
public:
	void StartTransactionInternal();

	int m_n_00;
	URLRequest* request_;
	bool done_;
	int64_t prefilter_bytes_read_;
	int64_t postfilter_bytes_read_;
	void* source_stream_;
	void* pending_read_buffer_;
	void* raw_read_buffer_;
	bool has_handled_response_;
	int64_t expected_content_size_;
	int m_n_38[69];
	std::optional<GURL> preserve_fragment_on_redirect_url_;
	bool awaiting_callback_;
	void* http_user_agent_settings_;
	int64_t total_received_bytes_from_previous_transactions_;
	int64_t total_sent_bytes_from_previous_transactions_;
	int m_n_1c0[39];
	std::vector<st0x18> m_vec_25c;
};


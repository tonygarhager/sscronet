#include "sscronet.h"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "sscronet", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "sscronet", __VA_ARGS__))

stStr0x8 g_st_332774[] =
{
	stStr0x8("force_tt_hpack_optimization"),
	stStr0x8("x-ttnet-scene-type"),
	stStr0x8("x-ttnet-bypass-sandbox"),
	stStr0x8("x-bd-client-key"),
	stStr0x8("force_tt_hpack_optimization"),
	stStr0x8("x-ttnet-scene-type"),
	stStr0x8("x-ttnet-origin-url"),
	stStr0x8("smbyttnet"),
	stStr0x8("1"),
	stStr0x8("Sec-CH-Partitioned-Cookies"),
	stStr0x8("Sec-CH-Partitioned-Cookies"),
	stStr0x8("?0"),
	stStr0x8("x-common-params-v2"),
	stStr0x8("x-metasec-bypass-ttnet-features"),
	stStr0x8("x-metasec-bypass-ttnet-features"),
};

void sub_146E4A(stStr0x8& rr0, const std::string& rr1)
{
	rr0.m_str = rr1.c_str();
	rr0.m_len = rr1.length();
}

bool sub_EE524(const char* rr0, int rr1, const char* rr2, int rr3)
{
	if (rr1 != rr3)
		return false;
	
	for (int i = 0; i < rr1; i++)
	{
		if (tolower(rr0[i]) != tolower(rr2[i]))
			false;
	}
	return true;
}

std::vector<st0x18>::iterator sub_1BE402(std::vector<st0x18>& rr0, const stStr0x8& rr1)
{
	stStr0x8 var_28;
	std::vector<st0x18>::iterator it = rr0.begin();
	for (; it != rr0.end(); it++)
	{
		sub_146E4A(var_28, it->m_str_00);
		if (sub_EE524(rr1.m_str, rr1.m_len, var_28.m_str, var_28.m_len) != 0)
			break;
	}
	return it;
}

inline uint32_t count_leading_zeros(uint32_t value) {
	return value ? __builtin_clz(value) : 32;
}

uint32_t sub_C2B4C(uint32_t rr0, uint32_t rr1)
{
	if (rr1 < 1)
		return 0;
	if (rr1 == 1)
		return rr0;
	if (rr0 < rr1)
		return 0;
	uint32_t count = count_leading_zeros(rr1) - count_leading_zeros(rr0);
	uint32_t nr3 = 0;
	for (uint32_t i = 0; i <= count; i++)
	{
		uint32_t shift = 31 - i;
		if (rr0 >= (rr1 << shift))
		{
			nr3 += (1 << shift);
			rr0 -= (rr1 << shift);
		}
	}
	return nr3;
}

size_t sub_C2B20(int rr0, int rr1)
{
	return (sub_C2B4C(abs(rr0), abs(rr1)) ^ ((rr0 ^ rr1) >> 31)) - ((rr0 ^ rr1) >> 31);
}

std::vector<st0x18>::iterator sub_1BE56C(std::vector<st0x18>& rr0, std::vector<st0x18>::iterator rr1)
{
	size_t nr0 = sub_C2B20((rr1 - rr0.begin()) * sizeof(st0x18), sizeof(st0x18));
	std::vector<st0x18>::iterator itr8 = rr0.begin() + nr0;
	rr0.erase(itr8, rr0.end() - 1);
	
	return itr8;
}

std::vector<st0x18>::iterator sub_1BE550(std::vector<st0x18>& rr0, const stStr0x8& rr1)
{
	std::vector<st0x18>::iterator it = sub_1BE402(rr0, rr1);

	if (it != rr0.end())
		return sub_1BE56C(rr0, it);
	return it;
}

bool sub_1B4608(std::vector<st0x18>& rr0, const stStr0x8& rr1)
{
	return rr0.end() != sub_1BE402(rr0, rr1);
}

void URLRequestHttpJob::StartTransactionInternal()
{
	preserve_fragment_on_redirect_url_ = request_->url_chain_.back();
	sub_1BE550(m_vec_25c, g_st_332774[2]);
	
	if (sub_1B4608(m_vec_25c, g_st_332774[13]))
	{
		std::string var_268;
		if (sub_1BE3DE(m_vec_25c, g_st_332774[14], var_268) &&
			var_268 == "1")
		{
			std::vector<std::string> var_2cc = {
				"x-bd-client-key",
				"x-bd-lanusk",
				"x-bd-kmsv",
				"x-bd-lanusv",
				"x-common-params-v2",
				"tt-cold-start",
				"tt-config-updated",
				"tt-config-version",
				"tt-tnc-etag",
				"tt-tnc-canary",
				"x-ss-stub",
				"x-ab-id",
				"x-tt-store-idc",
				"x-tt-store-region",
				"x-tt-store-region-src",
				"x-tt-store-region-did",
				"x-tt-store-region-uid",
				"x-tt-local-region",
				"x-tt-trace-id",
				"x-tt-trace-log",
				"x-client-ip-v4",
				"x-tt-bp-v4",
				"transaction-id",
				"bypass-boe",
				"x-tt-request-tag",
				"x-ss-tc",
				"x-ss-dp",
				"x-tt-bypass-dp",
				"x-ss-req-ticket",
				"x-vc-bdturing-sdk-version",
				"x-khronos",
				"x-gorgon",
				"x-ladon",
				"x-tython",
				"x-argus"
			};

			for (size_t i = 0; i < var_2cc.size(); i++)
			{
				stStr0x8 var_1d0;
				sub_146E4A(var_1d0, var_2cc[i]);
				sub_1BE550(m_vec_25c, var_1d0);
			}
		}
	}
	//loc_21FFB2
	sub_1BE550(m_vec_25c, g_st_332774[3]);
}
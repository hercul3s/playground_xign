#include "Xign.h"


v_u8 hash_MD5(const v_u8& input) {


	v_u8 out(16);

	int ret = mbedtls_md5(input.data(), input.size(), out.data());		

	if (ret != 0) {
		//printf("Hashing {} bytes with MD5 failed! (ret: 0x{:x})", hex_dump(input, ":"));
		return {};
	}
	return out;
}
std::string hex_dump(const v_u8& data, const std::string& sep) {
	std::string hexstring = std::accumulate(std::begin(data), std::end(data), std::string{},
		[sep](const std::string& a, uint8_t b) {
			return a.empty() ? fmt::format("{:02x}", b) : a + sep + fmt::format("{:02x}", b);
		});
	return hexstring;
}
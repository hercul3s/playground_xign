#pragma once
#include "helper.h"

typedef std::vector<uint8_t> v_u8;
std::string hex_dump(const v_u8& data, const std::string& sep = ":");
v_u8 hash_MD5(const v_u8& input);
void decrypt_buffer(const uint8_t* input, size_t input_len, uint8_t* output, mbedtls_aes_context* ctx);
v_u8 rijndael(const v_u8& tmpArr, uint8_t* xArr);


//lenght 0x140 320

struct XignLog {
	uint32_t sign_header;
	uint32_t sign_type; //HIWORD
	uint8_t  unk_buffer[16]; //12
	uint8_t  key[12]; //12
	uint8_t  after_key[4]; //4
	//std::vector<uint8_t> hash[4];
	uint8_t hash[4];
	//uint32_t after_hash;
	uint8_t after_hash0;
	uint8_t after_hash1;
	uint16_t after_hash2;
	uint32_t v_const; //32
	uint8_t  fff[16];
	uint8_t  second_buffer[0xF0]; //240 round 15
	uint32_t sign_tail;
	uint32_t junk;
	uint32_t log_count;
};typedef XignLog xLog;





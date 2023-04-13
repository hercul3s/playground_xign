

#include "Xign.h"


v_u8 rijndael(const v_u8& tmpArr, uint8_t* xArr)
{

    v_u8 decrypted_buffer(0xF0);
    mbedtls_aes_context ctx;
    mbedtls_aes_init(&ctx);
    mbedtls_aes_setkey_dec(&ctx, tmpArr.data(), 0x80);
    decrypt_buffer(xArr, 0xF0, decrypted_buffer.data(), &ctx);
    return decrypted_buffer;
}

// Function to decrypt a buffer using mbedtls_aes_decrypt
void decrypt_buffer(const uint8_t* input, size_t input_len, uint8_t* output, mbedtls_aes_context* ctx)
{
    size_t num_blocks = input_len / 16;

    for (size_t i = 0; i < num_blocks; i++)
    {
        mbedtls_internal_aes_decrypt(ctx, input + i * 16, output + i * 16);
    }
}
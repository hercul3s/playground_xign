
#include "Xign.h"


int main(int argc, char* argv[])
{
    auto console = spdlog::stdout_color_mt("console");
    spdlog::set_level(spdlog::level::debug);
    const char* str;
    std::vector<xLog> arrXign;
#ifndef _DEBUG 
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " input_file output_file\n";
        return 1;
    }
    str = argv[1]; //input file 


    std::ofstream output_file(argv[2], std::ios::binary);
    if (!output_file)
    {
        std::cerr << "Failed to open output file: " << argv[2] << '\n';
        return 1;
    }

#else 
    str = "C:\\src\\git-folder\\playground_xign\\xigncode.log";
#endif

    std::ifstream file(str, std::ios::binary);

    if (file.is_open()) {
        xLog tmp = { 0 };
        // Read 320 bytes at a time and store it in the vector
        while (file.read((char*)&tmp, sizeof(tmp))) {
            arrXign.push_back(tmp);
        }
    }
    else {
        std::cout << "Failed to open log file" << std::endl;
    }

    file.close();


    for (auto& tmp_log : arrXign) {
   
       
        v_u8 hash_vector(tmp_log.hash, tmp_log.hash + 4);
        v_u8 tmpArr(16);
        tmpArr = hash_MD5(hash_vector);
        v_u8 decrypted_buffer = rijndael(tmpArr, tmp_log.second_buffer);

        console->info("Output  buffer {:a}", spdlog::to_hex(decrypted_buffer, 36));
#ifndef _DEBUG 
        output_file.write((const char*)decrypted_buffer.data(), 0xf0);
#endif 

    }

#ifndef _DEBUG 
    output_file.close();
#endif
    return 0;

   }

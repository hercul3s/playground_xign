#pragma once
#include <stdint.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>

#include <numeric>
#include <windows.h>
#include "mbedtls/md5.h"
#include "mbedtls/platform.h"
#include "mbedtls/aes.h"


#include "mbedtls/ctr_drbg.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/bin_to_hex.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#pragma warning(disable : 4996)
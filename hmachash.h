#include "cryptlib.h"
#include "sha.h"
#include <iostream>
#include "AESCBC.h"
#include "cryptlib.h"
#include "sha.h"
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include "cryptlib.h"
using CryptoPP::Exception;

#include "secblock.h"
using CryptoPP::SecByteBlock;

#include "hmac.h"
using CryptoPP::HMAC;

#include "sha.h"
using CryptoPP::SHA256;

#include "base64.h"
using CryptoPP::Base64Encoder;

#include "filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::HashFilter;

AutoSeededRandomPool prng;

SecByteBlock key(16);  //encryption key
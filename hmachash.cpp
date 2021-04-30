#include "hmachash.h"

string plain = "HMAC Test"; //plain text: replaced by input
string mac, encoded;
//void HMACt(string plain secByteBlock key(16))

int main(int argc, char* argv[])
{
    prng.GenerateBlock(key, key.size());   

    /*********************************\
    \*********************************/

    // Pretty print key
    encoded.clear();
    StringSource ss1(key, key.size(), true,
        new HexEncoder(
            new StringSink(encoded)
        ) // HexEncoder
    ); // StringSource

    cout << "key: " << encoded << endl;
    cout << "plain text: " << plain << endl;

    /*********************************\
    \*********************************/

    try
    {
        HMAC< SHA256 > hmac(key, key.size());

        StringSource ss2(plain, true,
            new HashFilter(hmac,
                new StringSink(mac)
            ) // HashFilter      
        ); // StringSource
    }
    catch (const CryptoPP::Exception& e)
    {
        cerr << e.what() << endl;
        exit(1);
    }

    /*********************************\
    \*********************************/

    // Pretty print
    encoded.clear();
    StringSource ss3(mac, true,
        new HexEncoder(
            new StringSink(encoded)
        ) // HexEncoder
    ); // StringSource

    cout << "hmac: " << encoded << endl;

    return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <crypt.h>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

void findPass(string pass, const string& hash)
{
    crypt_data *pCryptData = new crypt_data;
    size_t pos = hash.find_last_of('$');
    string hashHead = hash.substr(0,pos);
    do {
        string newHash(crypt_r(pass.data(),hashHead.data(),pCryptData));
        if (newHash == hash) {
            cout<<"Hash: "<<hash<<endl<<"Pass: "<<pass<<endl;
            break;
        }
    } while ( next_permutation( pass.begin(), pass.end() ) );
    delete pCryptData;
}

int main()
{
    string hashpasswd, start_point = "123456789";
    ifstream File_with_hash;
	File_with_hash.open("/home/mouse/first_/9lb_1/Debug/hash8");
    while (true) {
        File_with_hash >> hashpasswd;
		if(File_with_hash.fail())
			break;
        findPass(start_point, hashpasswd);
    }
}
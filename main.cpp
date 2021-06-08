#include <iostream>
#include <cstring>
#include <algorithm>
#include <crypt.h>
#include <fstream>
#include <thread>
using namespace std;
class findPass
{
public:
    void operator()(string pass, const string& hash)
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
};
int main()
{	int kolvo = 8;
    string hash,hashes[kolvo];
    thread thread_array[kolvo];
    ifstream MyFile;
    int x =0;
    MyFile.open("/home/mouse/first_/9lb_1/Debug/hash8");
    while(true) {
        MyFile >> hashes[x];
        x++;
		if(MyFile.fail())
			break;
    }
    for (int i=0; i<kolvo; i++) {
        hash = hashes[i];
        thread_array[i] = thread(findPass(),"123456789", hash);
    }
    for (int k=0; k<kolvo; k++) {
        if (thread_array[k].joinable()) {
            thread_array[k].join();
        }
    }
    return 0;
}
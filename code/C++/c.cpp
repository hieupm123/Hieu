#include<iostream>
#include<ctime>
#include<unistd.h>
#include<set>
#include<vector>
using namespace std;
int rand(int a, int b){
	return a + rand()%(b-a+1);
}
// string gen_random(const int len) {
//     string tmp_s;
//     static const char alphanum[] =
//         "0123456789"
//         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
//         "abcdefghijklmnopqrstuvwxyz";
//     srand( (unsigned) time(NULL) * getpid());
//     tmp_s.reserve(len);
//     for (int i = 0; i < len; ++i) 
//         tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
//     return tmp_s;
// }
string gen_random(const long long len) {
    string tmp_s;
    static const char alphanum[] =
        // "0123456789"
        // "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    	// "*.";
    	// "0123456789";
    srand( (unsigned) time(NULL) * getpid());
    tmp_s.reserve(len);
    for (int i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    return tmp_s;
}
int main(int argc, char* argv[]){
	srand(stoi(argv[1]));
	int n = rand(1,20);
    cout<<n<<"\n";
    for(int i = 0; i < n; ++i){
        int a = rand(-1,1);
        cout<<a<<" ";
    }
    cout<<"\n";
}
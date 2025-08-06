#include<iostream>
#include<map>
using namespace std;

int main() {
    map<string,int> mp;
    printf("Testing map class\n");
    mp["z"] = 0;
    mp["z"] = 1;
    mp["y"] = 2;
    mp["b"] = 3;
    mp["a"] = 4;

    printf("z=%d\n",(mp.count("z") ? mp["z"] : 42));
    printf("x=%d\n",(mp.count("x") ? mp["x"] : 42));

    printf("Iterate\n");
    for(auto cur = mp.begin(); cur != mp.end(); ++cur)
        printf("%s=%d\n", cur->first.c_str(), cur->second);
}
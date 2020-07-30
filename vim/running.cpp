#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ll    long long
#define uint  unsigned int
#define ull   unsigned long long
#define ld    long double

const int MOD = int(1e9+7);
const ll oo  = (ll)(1e9+20);
const ll lloo  = (ll)(1e18)+40;

string reset{"\033[0m"};
string red_fill{"\033[7;107;91m"};
string red_bold{"\033[1;31m"};
string blue_fill{"\033[7;49;34m"};
string blue_bold{"\033[49;34m"};
string green_fill{"\033[7;49;32m"};
string green_bold{"\033[49;32m"};
string yellow_fill{"\033[7;49;33m"};
string yellow_bold{"\033[49;33m"};

pair<string, string> get_filename(string path) {
    return {
        path.substr(0, path.find(".")),
        path.substr(path.find("."), path.size())
    };
}

auto main(int argc, char* argv[]) -> int {
    auto [file, ext] = get_filename(argv[1]);

    string filename = string(file);

    string compiler = "g++ -std=c++17 -DLOCAL=1 -o \""+filename+".o\" \""+filename+ext+"\"";
    system(compiler.c_str());
     
    for(int i = 2; i < argc; ++i) {
        auto before = chrono::high_resolution_clock::now();

        cout << blue_fill << "File " + string(argv[i]) << reset << endl;

        string execu = "timeout 3s \""+filename+".o\" < \"" + string(argv[i]) + ".in\"";
        system(execu.c_str());

        auto after = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
        after - before);
        
        if(duration.count() >= 2000.0) {
            cout << endl <<
            red_fill << "Time Limit Exceeded  " <<
            green_fill << ":" << reset << red_fill << " " <<
            red_fill << fixed << setprecision(10) << duration.count() << reset <<
            green_fill << " ms" <<reset << endl;
        } else {
            cout <<
            green_fill << "Finished in :" << reset <<
            yellow_fill << " " << fixed << setprecision(10) << duration.count() << reset <<
            green_fill << " ms" <<reset << endl;
        }
        cout << green_bold << "≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡" << reset << "\n\n";
    }
    return 0;
}

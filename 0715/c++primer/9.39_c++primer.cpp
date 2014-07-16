#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    string line1 = "hgalhlaghalghlah";
    string line2 = "hagahglaglagasdjgaww";
    string line3 = "aag;agja;jgwpjg";
    string sentence = line1 + ' ' + line2 + ' ' + line3;
    cout << "size" << sentence.size()<< endl;
    return 0;
}

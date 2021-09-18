#include <fstream>
#include <iostream>
#include <string>

int main(){
        int n;
        std::cin>>n;
        std::string sometext;
        std::getline(std::cin, sometext);
         std::string filename;
for (int i=1;i<=n;i++){
filename="file_"+std::to_string(i)+".txt";
    std::ofstream fout(filename); 
    fout<<sometext<<" "<<i;
}
}
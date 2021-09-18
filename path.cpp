#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <filesystem>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::recursive_directory_iterator;
using std::filesystem::filesystem_error;
void printfile(string filename){
    int fd=open(filename.c_str(),O_RDONLY);
    int sz;
    char *c = (char *) calloc(100, sizeof(char));
    do{
         sz = read(fd, c, 100);
        cout<< c;
    }
    while (sz == 100);
} 
void pa(string path){
    int v ;
 
    for (const auto & file : recursive_directory_iterator(path)){
             v=open(file.path().c_str(), O_DIRECT);
            
             if(v<0)
            {
            pa(file.path());
            }
           else{
           
           cout << "content of file "<<file.path()<< endl;
           printfile(file.path());
           cout<<endl;
           }
    
}
}
int main() {
    pa("./");
}


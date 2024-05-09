#include <iostream>
#include<map>//should be included for using map
#include <vector>

using namespace std;

int main() {
  //creation vala part
  map<int,char>MeraMap;

  //insertion vala part
  MeraMap[0] = 'a';
  MeraMap[1] = 'b';
  MeraMap[2] = 'c';
  // MeraMap[3].push_back('d');

  //acces vala part
  // cout << "Printing the value of key 2: " << MeraMap[3] << endl;

  //access first and second values 
  for (auto it = MeraMap.begin(); it != MeraMap.end(); ++it) {
      std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
  }
 return 0;
}
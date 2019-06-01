//
//  check3.cpp
//  lab6
//
//  Created by Sriyuth Sagi on 2/21/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
#include <cassert>
// O(a*d*d*k + r*d*k)

void update(std::list<std::string>& data, const std::vector<std::string>& add, const std::vector<std::string>& remove) {
    for (int i=0;i<add.size();i++) {
        bool present = false;
        for (std::list<std::string>::iterator j=data.begin(); j!=data.end(); j++) {
            if(add[i] == *j) {
                present = true;
            }
        }
        if (!present) {
            std::list<std::string>::iterator j=data.begin();
            while (add[i]>*j) {
                j++;
            }
            data.insert(j, add[i]);
        }
    }
    
    for (int i=0;i<remove.size();i++) {
        for (std::list<std::string>::iterator j=data.begin(); j!=data.end(); j++) {
            if(std::string(*j).find(std::string(remove[i])) != std::string::npos) {
                data.erase(j);
            }
            
        }
    }
}




void print(const std::string &label, const std::list<std::string> &data) {
    std::cout << label;
    for (std::list<std::string>::const_iterator itr = data.begin();
         itr != data.end(); itr++) {
        std::cout << " " << *itr;
    }
    std::cout << std::endl;
}


int main() {
    
    
    // Examples demonstrating STL string find:
    // catfish contains the substring fish
    assert (std::string("catfish").find(std::string("fish")) != std::string::npos);
    // fish contains the substring fish
    assert (std::string("fish").find(std::string("fish")) != std::string::npos);
    // fish does not contain the substring catfish
    assert (std::string("fish").find(std::string("catfish")) == std::string::npos);
    
    
    // A simple example:
    std::list<std::string> data;
    data.push_back("antelope");
    data.push_back("catfish");
    data.push_back("giraffe");
    data.push_back("jellyfish");
    data.push_back("llama");
    data.push_back("whale_shark");
    data.push_back("zebra");
    
    std::vector<std::string> add;
    add.push_back("tiger");
    add.push_back("llama");
    add.push_back("elephant");
    
    std::vector<std::string> remove;
    remove.push_back("fish");
    remove.push_back("bear");
    remove.push_back("whale");
    
    print ("before:",data);
    update(data,add,remove);
    print ("after: ",data);
    
    // at the end, data should contain: antelope elephant giraffe llama tiger zebra
    assert (data.size() == 6);
    
}


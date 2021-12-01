#pragma once
#include<bits/stdc++.h>
using namespace std;

class Vechile {
    public :
        string num;
        string owner_name ;
        string type ;
        Vechile(string num ,string owner_name,string type){
            this->num =num;
            this->owner_name=owner_name;
            this->type =type ;
        }        
} ;
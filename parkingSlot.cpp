#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "vechile.cpp"

class Slot {
    public :
        string id ;
        string type ;
        bool isAvailable ;
        Vechile *vechile ;
        Slot(string id ,string type){
            this->id=id ;            
            this->type=type ; 
            isAvailable =true ;           
        }        
} ;
/**
 * In deze file vindt je de 'largest' functie.
 */



#include "Exceptions.h"
#include "Largest.h"

#include <limits>
#include <vector>


int largest(std::vector<int>* list){
    int max = std::numeric_limits<int>::max();
    for(int i = 0; i < (int) list->size() - 1; i++){
        if(list->at(i) > max){
            max = list->at(i);
        }
    }
    return max;
}


int largest2(std::vector<int>* list) {
    if(list == 0) {
        throw new IllegalArgumentException("list cannot be nullptr");
    }else if(list->empty()){
        throw new IllegalArgumentException("list cannot be empty");
    }
    int max = std::numeric_limits<int>::min();
    for(int i = 0; i < (int) list->size(); i++){
        if(list->at(i) > max){
            max = list->at(i);
        }
    }
    return max;
}

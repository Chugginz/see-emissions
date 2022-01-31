// @file c_string_utils.h

#ifndef C_STRING_UTILS_H
#define C_STRING_UTILS_H

int my_strlen(char array[]){
    int count = 0;
    
    while (array[count] != '\0'){
        count++;
    }
    
    return count;
}

#endif
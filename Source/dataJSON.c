/**
 * @author ButterSss
 * @date May 2022
 */

#include <stdio.h>
#include <json-c/json.h>
#include "dataJSON.h"

dataJSON*dataJSON_create(const char *__restrict __filename){
    dataJSON *result = malloc(sizeof(dataJSON));
    result->file = fopen(__filename, "r+");
    if (result->file == NULL){
        return NULL;
    }
    fseek(result->file, 0, SEEK_END);
    result->size = ftell(result->file);
    fseek(result->file, 0, SEEK_SET);
    result->stringFile = calloc(result->size, sizeof(char));
    fread(result->stringFile, sizeof(char), result->size, result->file);
    result->jsonFile = json_tokener_parse(result->stringFile);
    return result;
}

json_bool dataJSON_boolean(dataJSON*source, char*key){
    json_object*object;
    json_object_object_get_ex(source->jsonFile, key, &object);
    return json_object_get_boolean(object);
}

int dataJSON_int(dataJSON*source, char*key){
    json_object*object;
    json_object_object_get_ex(source->jsonFile, key, &object);
    return json_object_get_int(object);
}

long long dataJSON_long(dataJSON*source, char*key){
    json_object*object;
    json_object_object_get_ex(source->jsonFile, key, &object);
    return json_object_get_int64(object);
}

double dataJSON_double(dataJSON*source, char*key){
    json_object*object;
    json_object_object_get_ex(source->jsonFile, key, &object);
    return json_object_get_double(object);
}

char*dataJSON_string(dataJSON*source, char*key){
    json_object*object;
    json_object_object_get_ex(source->jsonFile, key, &object);
    return (char*)json_object_get_string(object);
}

int dataJSON_stringL(dataJSON*source, char*key){
    json_object*object;
    json_object_object_get_ex(source->jsonFile, key, &object);
    return json_object_get_string_len(object);
}

unsigned long long dataJSON_longU(dataJSON*source, char*key){
    json_object*object;
    json_object_object_get_ex(source->jsonFile, key, &object);
    return json_object_get_uint64(object);
}

json_type dataJSON_type(dataJSON*source, char*key){
    json_object*object;
    json_object_object_get_ex(source->jsonFile, key, &object);
    return json_object_get_type(source->jsonFile);
}

array_list*dataJSON_array(dataJSON*source, char*key){
    json_object*object;
    json_object_object_get_ex(source->jsonFile, key, &object);
    return json_object_get_array(source->jsonFile);
}

dataJSON*dataBase;

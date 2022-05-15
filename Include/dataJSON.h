/**
 * @author ButterSss
 * @date May 2022
 */

#ifndef SAPER_DATAJSON_H
#define SAPER_DATAJSON_H

#include <stdio.h>
#include <json-c/json.h>

/**
 * @def
 * use it to work with JSON
 */

typedef struct{
    FILE*file;
    size_t size;
    char*stringFile;
    json_object*jsonFile;
}dataJSON;

/**
 * @def
 * create dataJSON struct
 */

dataJSON*dataJSON_create(const char *__restrict __filename);

/**
 * @def
 * read bool
 */

json_bool dataJSON_boolean(dataJSON*source, char*key);

/**
 * @def
 * read int
 */

int dataJSON_int(dataJSON*source, char*key);

/**
 * @def
 * read long
 */

long long dataJSON_long(dataJSON*source, char*key);

/**
 * @def
 * read double
 */

double dataJSON_double(dataJSON*source, char*key);

/**
 * @def
 * read string
 */

char*dataJSON_string(dataJSON*source, char*key);

/**
 * @def
 * read string len
 */

int dataJSON_stringL(dataJSON*source, char*key);

/**
 * @def
 * read unsigned long
 */

unsigned long long dataJSON_longU(dataJSON*source, char*key);

/**
 * @def
 * read type
 */

json_type dataJSON_type(dataJSON*source, char*key);

/**
 * @def
 * read array
 */

array_list*dataJSON_array(dataJSON*source, char*key);

extern dataJSON*dataBase;

#endif //SAPER_DATAJSON_H

#include "dataJSON.h"
#include "window.h"

int main(int argc, char**argv){
    dataBase = dataJSON_create("Files/settings.json");
    window_init(argc, argv);
}

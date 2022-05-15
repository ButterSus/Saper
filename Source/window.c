/**
 * @author ButterSss
 * @date May 2022
 */

#include <GL/freeglut.h>
#include "dataJSON.h"

void display(){

}

void window_init(int argc, char**argv){
    glutInit(&argc, argv);
    array_list * windowSize = dataJSON_array(dataBase, "WindowSize");
    glutInitWindowSize(700, 700);
    glutCreateWindow(dataJSON_string(dataBase, "WindowTitle"));
    glutDisplayFunc(display);
    glutMainLoop();
}

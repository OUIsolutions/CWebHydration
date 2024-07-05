
#include "CWebStudio.h"
#include "src/one.c"
CwebNamespace cweb;


int main(int argc, char *argv[]){
    cweb = newCwebNamespace();

    CWebHyDration *hy = newCWebHyDration(NULL);

    CWebHyDrationBridge *teste = CWebHyDration_create_bridge(hy,"/teste",NULL);
    CWebHyDrationBridge *teste2 = CWebHyDration_create_bridge(hy,"/teste2",NULL);

    char* script  = CWebHyDration_create_script(hy);
    printf("%s\n",script);
    return 0;
}
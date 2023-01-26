#include <stdio.h>

void fillTerrainGrass(char terrain[21][80]) {
    int i;
    int j;
    for(i = 1; i < 20; i++) {
        for(j = 1; j < 79; j++) {
            terrain[i][j] = ':';
        }
    }
}
void buildPerimeter(char terrain[21][80]) {
    int i;
    for(i = 0; i < 21; i++) {
        terrain[i][0] = '%';
        terrain[i][79] = '%';
    }
    for(i = 0; i < 79; i++) {
        terrain[0][i] = '%';
        terrain[20][i] = '%';
    }
}

void printTerrain(char terrain[21][80]) {
    for(int i = 0; i < 21; i++) {
        for(int j = 0; j < 80; j++) {
            printf("%c", terrain[i][j]);
        }
        printf("\n");
    }
}

void buildTerrain(char terrain[21][80]) {
    buildPerimeter(terrain);
    fillTerrainGrass(terrain);
    printTerrain(terrain);
}
int main(int argsc, char* argsv[]) {
    char terrain[21][80];
    buildTerrain(terrain);
}
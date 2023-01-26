#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fillTerrainGrass(char terrain[21][80]) {
    int i, j;
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
    int i;
    for(i = 0; i < 21; i++) {
        for(int j = 0; j < 80; j++) {
            printf("%c", terrain[i][j]);
        }
        printf("\n");
    }
}

void layPath(char terrain[21][80]){
    int north, east, south, west, i, minX, minY;

    north = (rand() % 78) + 1; // generate between 1-79
    east = (rand() % 19) + 1; // generate between 1-19
    south = (rand() % 78) + 1;
    west = (rand() % 19) + 1; 

    if(east < west) {
        minX = east;
    } else minX = west;
    if(north < south) {
        minY = north;
    } else minY = south;

    printf("n: %d, e: %d, s: %d, w: %d\n", north, east, south, west);
    printf("xInt %d, yInt %d\n", minX, minY);
    printf("N/S dif %d, E/W dif %d\n", abs(north - south), abs(east - west));
    terrain[west][79] = '#';
    terrain[east][0] = '#';
    terrain[0][north] = '#';
    terrain[20][south] = '#';
    //draw original lines // y starts at 14
    for(i = 1; i < 15; i++) {
        terrain[i][north] = '#';
    }
    for(i = 14; i < 20; i++) {
        terrain[i][south] = '#';
    }
    for(i = minY; i < abs(north - south) + minY; i++) {
        terrain[14][i] = '#';
    }

    for(i = 1; i < 65; i++) {
        terrain[east][i] = '#';
    }
    for(i = 64; i < 80; i++) {
        terrain[west][i] = '#';
    }
    for(i = minX; i < abs(east - west) + minX; i++) {
        terrain[i][64] = '#';
    }
}

void buildTerrain(char terrain[21][80]) {
    buildPerimeter(terrain);
    fillTerrainGrass(terrain);
    layPath(terrain);

    printTerrain(terrain);
}
int main(int argsc, char* argsv[]) {
    char terrain[21][80];
    srand(time(NULL));
    buildTerrain(terrain);
}
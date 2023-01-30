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

int isValid(int x, int y, char terrain[21][80]) {
    if(x >= 0 && x < 21 && y >= 0 && y < 80 && terrain[x][y] == ':') {
        return 1;
    } 
    return 0;
}

void layPath(char terrain[21][80]){
    int north, east, south, west, i, minX, minY, j, pCenter, cCenter;

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

    terrain[west][79] = '#';
    terrain[east][0] = '#';
    terrain[0][north] = '#';
    terrain[20][south] = '#';
    
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

    // place pokemarts and pokecenters (next to the [14][north] (+- 1 if available))
    cCenter = 0;
    printf("North: %d\n", north);
    for(i = 4; i < 15; i++) {
        for(j = 0; j < 2; j++) {
            if(isValid(i, north + 1, terrain) == 1) {
                if(cCenter == 1) {
                    terrain[i][north + 1] = 'P';
                    pCenter = 1;
                    break;
                }
                terrain[i][north + 1] = 'C';
                cCenter = 1;
                break;
            }
            if(isValid(i, north - 1, terrain) == 1) {
                if(cCenter == 1) {
                    terrain[i][north - 1] = 'P';
                    pCenter = 1;
                    break;
                }
                terrain[i][north - 1] = 'C';
                cCenter = 1;
                break;
            }
        }
        if(cCenter == 1 && pCenter == 1) break;
    }
    
}

void createWater(char terrain[21][80]) {
    int randX, randY, i, tmp;

    randX = (rand() % 19) + 1;
    randY = (rand() % 78) + 1;

    for(i = 0; i < 7; i++) {
        break;
    }
}

void buildTerrain(char terrain[21][80]) {
    buildPerimeter(terrain);
    fillTerrainGrass(terrain);
    createWater(terrain);
    layPath(terrain);
    printTerrain(terrain);
}
int main(int argsc, char* argsv[]) {
    char terrain[21][80];
    srand(time(NULL));
    buildTerrain(terrain);
}
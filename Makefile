TerrainGenerator: TerrainGenerator.c
	gcc -Wall -Werror -g TerrainGenerator.c -o output

clean :
	rm -rf .vscode
	rm -rf .DS_Store
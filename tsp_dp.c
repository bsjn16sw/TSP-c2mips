#include<stdio.h>
#include<math.h>

float dist[7][7] = {0};		// dist[i][j] means distance from i to j
float memo[7][127] = {0};	// i is starting city index and j is bit-mask when memo[i][j]
int minPath[8] = {1, 0, 0, 0, 0, 0, 0, 1};		// Path with minimum cost

// i: current city index
// visitMask: bit-mask (marked on visited city)
float getMinCost(int i, int visitMask)
{
	int j;
	float tempCost, tempMinCost = 99999;

	// gMC1
	// If all cities are visited, return distance from i to 0.
	if(visitMask == (1 << 7) - 1){
		memo[i][visitMask] = dist[i][0];
		return dist[i][0];
	}

	// gMC2
	// If there is memoed value, just return it.
	tempCost = memo[i][visitMask];
	if(tempCost != 0)
		return tempCost;

	// gMC3
	// If there is NO memoed value, calculate it.
	// j is index of next city.
	for(j=0; j<7; j++){
		// Pass same city
		if(i == j)	continue;
		// Pass visited cities
		if(visitMask & (1 << j))	continue;

		// Calculate: distance from i to j + distance from j to end
		tempCost = dist[i][j] + getMinCost(j, visitMask | (1 << j));
		if(tempCost < tempMinCost)
			tempMinCost = tempCost;
	}

	// Memo the result and return it.
	memo[i][visitMask] = tempMinCost;
	return tempMinCost;
}

void getMinPath(float minCost)
{
	int i, j, cur = 0, visitMask = 1;

	// Get path
	for(i=1; i<7; i++){
		// Check if city indexed j is next city.
		for(j=0; j<7; j++){
			// Pass visited city
			if(visitMask & (1 << j))	continue;
			
			// Find next city
			if(minCost - dist[cur][j] == memo[j][visitMask | (1 << j)]){
				minPath[i] = j + 1; // Plus one due to 0-indexed system
				visitMask |= (1 << j);
				minCost -= dist[cur][j];
				cur = j;
				break;
			}
		}
	}
}

int main()
{
	int city[7][2] = {{0, 0}, {8, 6}, {2, 4}, {6, 7}, {1, 3}, {9, 4}, {2, 3}};
	int i, j;
	float minCost;
	
	// Calculate distances between two cities and save in dist.
	for(i=0; i<7; i++){
		for(j=i+1; j<7; j++){
			dist[i][j] = sqrt(pow(city[i][0] - city[j][0], 2) + pow(city[i][1] - city[j][1], 2));
			dist[j][i] = dist[i][j];
		}
	}

	minCost = getMinCost(0, 1);
	printf("Minimum cost: %f\nMinimum path: ", minCost);
	getMinPath(minCost);
	for(i=0; i<8; i++)
		printf("%d ", minPath[i]);
	
	return 0;
}

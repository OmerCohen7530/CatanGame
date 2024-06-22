# Catan Game Implementation

## Overview

This project is a C++ implementation of the Catan board game. It includes classes to represent the game board, players, tiles, edges, vertices, and development cards. The game allows players to take turns, build structures, and manage resources, simulating one complete round of gameplay.

## Game Rules

- Players take turns rolling dice, collecting resources, and building structures.
- Players can build roads, settlements, and cities using resources.
- Development cards provide various benefits, such as additional resources or actions.
- The game ends when a player reaches 10 victory points.

## Class Hierarchy

### Board
- Manages the tiles, edges, and vertices of the game board.
- Keeps track of player turns and the position of the robber.
- Methods to build settlements, roads, cities, share resources, and check victory points.

### Player
- Represents a player in the game.
- Manages player resources, cities, settlements, roads, and development cards.
- Methods to add resources, check victory, roll dice, place buildings, trade resources, and use development cards.

### Tile
- Represents a hexagonal tile on the game board.
- Stores the resource type, tile number, and connected vertices.

### Edge
- Represents an edge connecting two vertices on the game board where road can be built.
- Stores the road status, connected vertices, and owner.

### Vertex
- Represents a vertex where settlements or cities can be built.
- Stores the building type, owner, and connected edges.

### DevelopmentCards
- Manages the development cards owned by a player.
- Stores counts of each type of development card.
- Methods to add and remove cards, and check card counts.

## Libraries Used

- Standard Template Library (STL): `vector`, `map`
- Random: `cstdlib`, `ctime`
- Input/Output: `iostream`

## Methods Description

### Board Methods
- `Board(Player& p1, Player& p2, Player& p3)`: Constructor initializing the board with players.
- `void initialize()`: Initializes the board with tiles, edges, and vertices.
- `void buildSettlement(int vertex, Player &player)`: Builds a settlement at the specified vertex.
- `void buildRoad(int edge, Player &player)`: Builds a road at the specified edge.
- `void buildCity(int vertex, Player &player)`: Builds a city at the specified vertex.
- `void shareResources(size_t dices)`: Distributes resources based on the dice roll.
- `void reduceHalfResourcesFromPlayers()`: Reduces resources of all players by half.
- `void monopolyAction(size_t res, Player &player)`: Executes a monopoly action.
- `void chechVictoryPoints()`: Checks if any player has won the game.
- `void finishGame()`: Ends the game.
- `std::vector<Tile>& getTiles()`: Gets the tiles on the board.
- `Edge& getEdge(int id)`: Gets an edge by ID.
- `Vertex& getVertex(int id)`: Gets a vertex by ID.
- `Player& getPlayer(int id)`: Gets a player by ID.
- `int getPlayerTurn() const`: Gets the current player's turn.
- `int getRobber() const`: Gets the current position of the robber.
- `void nextTurn()`: Advances to the next player's turn.
- `void setRobber(int position)`: Sets the robber's position.

### Player Methods
- `Player(int id, string name)`: Constructor initializing a player with ID and name.
- `Player(Player &player)`: Copy constructor.
- `void addResource(ResourceType res, int amount)`: Adds resources to the player.
- `bool checkVictory()`: Checks if the player has won.
- `void rollDices(Board &board)`: Rolls dice and collects resources.
- `void initSettlements_Roads(int settlements, int roads, Board &board)`: Initializes settlements and roads.
- `void status()`: Displays player status.
- `size_t getVictoryPoints()`: Gets the player's total victory points.
- `int placeSettlement(int vertex, Board &board)`: Places a settlement.
- `int placeRoad(int edge, Board &board)`: Places a road.
- `int placeCity(int vertex, Board &board)`: Places a city.
- `bool canBuildSettlement(int vertex, Board &board)`: Checks if a settlement can be built.
- `bool canBuildRoad(int edge, Board &board)`: Checks if a road can be built.
- `bool canBuildCity(int vertex, Board &board)`: Checks if a city can be built.
- `void addAssets(string asset)`: Adds assets.
- `void tradeFromto(ResourceType from, ResourceType to, Board &board)`: Trades resources.
- `size_t countResources()`: Counts total resources.
- `void endTurn(Board &board)`: Ends the player's turn.
- `void buyDevCard(Board &board)`: Buys a development card.
- `void useDevCard(string card, Board &board)`: Uses a development card.
- `void help_Road_Building_Card(Board &board)`: Helps with road building.

### Tile Methods
- `Tile(int id, ResourceType res, int num)`: Constructor initializing a tile.
- `void addVertex(int v1, int v2, int v3, int v4, int v5, int v6)`: Adds vertices to the tile.
- `size_t getNumber() const`: Gets the tile number.
- `ResourceType getResource() const`: Gets the resource type.
- `vector<int> getVertices() const`: Gets the vertices.
- `int getId() const`: Gets the tile ID.

### Edge Methods
- `Edge(int id)`: Constructor initializing an edge.
- `void buildRoad(int player)`: Builds a road for a player.
- `void addVertices(int vertex1, int vertex2)`: Adds vertices to the edge.
- `Road getRoad() const`: Gets the road status.
- `int getId() const`: Gets the edge ID.
- `int getOwner() const`: Gets the owner.
- `vector<int> getVertices() const`: Gets the vertices.
- `void setOwner(int player)`: Sets the owner.

### Vertex Methods
- `Vertex(int id)`: Constructor initializing a vertex.
- `void build(int player, Building type)`: Builds a structure on the vertex.
- `void addEdges(int vertex, int vertex2, int vertex3 = -1)`: Adds edges to the vertex.
- `Building getBuilding() const`: Gets the building type.
- `int getId() const`: Gets the vertex ID.
- `int getOwner() const`: Gets the owner.
- `vector<int>& getEdges()`: Gets the edges.
- `void setOwner(int player)`: Sets the owner.
- `void setBuilding(Building type)`: Sets the building type.

### DevelopmentCards Methods
- `DevelopmentCards()`: Constructor initializing development cards.
- `void buyCard()`: Buys a development card.
- `void addKnight()`: Adds a knight card.
- `void addVictoryPoint()`: Adds a victory point card.
- `void addRoadBuilding()`: Adds a road building card.
- `void addYearOfPlenty()`: Adds a year of plenty card.
- `void addMonopoly()`: Adds a monopoly card.
- `void addOpenKnight()`: Adds an open knight card.
- `void removeKnight()`: Removes a knight card.
- `void removeVictoryPoint()`: Removes a victory point card.
- `void removeRoadBuilding()`: Removes a road building card.
- `void removeYearOfPlenty()`: Removes a year of plenty card.
- `void removeMonopoly()`: Removes a monopoly card.
- `void removeOpenKnight()`: Removes an open knight card.
- `void setBiggestArmy(bool biggestArmy)`: Sets the biggest army status.
- `size_t getKnight() const`: Gets the knight card count.
- `size_t getVictoryPoint() const`: Gets the victory point card count.
- `size_t getRoadBuilding() const`: Gets the road building card count.
- `size_t getYearOfPlenty() const`: Gets the year of plenty card count.
- `size_t getMonopoly() const`: Gets the monopoly card count.
- `size_t getOpenKnight() const`: Gets the open knight card count.
- `bool getBiggestArmy() const`: Gets the biggest army status.
- `size_t countCards() const`: Counts the total number of cards.
- `void status() const`: Displays the status of development cards.
- `size_t getPoints() const`: Gets the total points from the cards.

## How to Run

1. **Compile the Code:**
   ```sh
   make catan

## Testing 
To run the test after cloning the repository use ```make test``` command, and then run ```./test``` and it will run the test file

## Valgrind
For checking memory leak we can compile this project by writing in the terminal ```make vlagrind```
#include "player.hpp"
#include "board.hpp"

#include <cstdlib> // std::srand, std::rand
#include <ctime>   // std::time

Player::Player(int id, string name) : name(name), id(id){
    resources[WOOD] = 0;
    resources[BRICK] = 0;
    resources[WHEAT] = 0;
    resources[SHEEP] = 0;
    resources[IRON] = 0;

    cities = 0;
    settlements = 0;
    roads = 0;
    cards = 0;
    alreadyRolled = false;
    devCards = DevelopmentCards();

}

Player::Player(Player &player) {
    name = player.name;
    id = player.id;
    resources = player.resources;
    cities = player.cities;
    settlements = player.settlements;
    roads = player.roads;
    cards = player.cards;
    alreadyRolled = player.alreadyRolled;
    devCards = player.devCards;
}

void Player::addResource(ResourceType res, int amount) {
    resources[res] += amount;
}

bool Player::checkVictory() {
    size_t count = 0;
    count += cities * 2;
    count += settlements;
    count += cards;
    return count >= 10;
}

void Player::rollDices(Board &board)
{
    if(board.getPlayerTurn() != id)
    {
        cout << "It's not your turn" << endl;
        return;
    }
    // the srand() function is used in the constructor of 'catan' class
    size_t dice1 = rand() % 6 + 1;
    size_t dice2 = rand() % 6 + 1;
    size_t sum = dice1 + dice2;
    cout << "Player " << this->getName() << " rolled " << sum << " (" << dice1 << " + " << dice2 << ")" << endl;

    if(sum == 7)
    {
        board.reduceHalfResourcesFromPlayers();
        cout << "Player " << name << " has to move the robber" << endl;
        cout << "** In this case we will do the moving randomly for the purpose of demonstrating the game **" << endl;
        size_t position = rand() % 19 + 1;
        while (position == (size_t)board.getRobber())
        {
            position = rand() % 19 + 1;
        }
        board.setRobber(position);
    }
    else
    {
        board.shareResources(sum);
    }
    setAlreadyRolled(true);
}

void Player::initSettlements_Roads(int settlement, int road, Board &board)
{
    

    if(settlement < 0 || settlements > 53 || road < 1 || road > 72)
    {
        cout << "Invalid number of settlements or roads" << endl;
        return;
    }

    board.buildRoad(road, *this);
    board.buildSettlement(settlement, *this);
}

void Player::status()
{
    cout << "************************************" << endl;
    cout << "Player " << name << " has:" << endl;
    cout << "\tAssets: " << endl;
    cout << "\t\tSettlements: " << settlements << endl;
    cout << "\t\tCities: " << cities << endl;
    cout << "\t\tRoads: " << roads << endl;
    cout << "\tResources:" << endl;
    string res[] = {"Wood", "Brick", "Wheat", "Sheep", "Iron"};
    for(auto it = resources.begin(); it != resources.end(); it++)
    {
        cout << "\t\t" << res[it->first] << ": " << it->second << endl;
    }
    devCards.status();
    cout << "************************************" << endl;
}

void Player::buyDevCard(Board &board)
{
    if(board.getPlayerTurn() != id)
    {
        cout << "It's not your turn" << endl;
        return;
    }

    if(resources[WHEAT] < 1 || resources[SHEEP] < 1 || resources[IRON] < 1)
    {
        cout << "You don't have enough resources" << endl;
        return;
    }

    resources[WHEAT]--;
    resources[SHEEP]--;
    resources[IRON]--;
    devCards.buyCard();
    board.chechVictoryPoints();
}

void Player::useDevCard(std::string card, Board &board) {
    if (card == "Knight") {
        if(devCards.getKnight() > 0){

            devCards.removeKnight();
            devCards.addOpenKnight();
            std::cout << "Player " << name << " used a Knight card." << std::endl;
            size_t position = rand() % 19 + 1;
            while (position == (size_t)board.getRobber())
            {
                position = rand() % 19 + 1;
            }
            board.setRobber(position);

            if(devCards.getOpenKnight() == 3)
            {
                cout << "Player " << name << " got the biggest army card" << endl;
                devCards.setBiggestArmy(true);
            }
        } else {
            std::cout << "Player " << name << " does not have enuogh Knight cards." << std::endl;
        }
    } 
    else if (card == "Road Building") 
    {
        if(devCards.getRoadBuilding() > 0)
        {
            devCards.removeRoadBuilding();
            std::cout << "Player " << name << " used a Road Building card." << std::endl;
            cout << "automaticly random choosing for example." << endl;
            help_Road_Building_Card(board);
            
        } 
        else 
        {
            std::cout << "Player " << name << " does not have a Road Building card or it cannot be used." << std::endl;
        }
    } 
    else if (card == "Year of Plenty") 
    {
        if(devCards.getYearOfPlenty() > 0)
        {
            devCards.removeYearOfPlenty();
            std::cout << "Player " << name << " used a Year of Plenty card." << std::endl;
            // player can choose two resources to add
            addResource(WOOD, 1); // Example: Add one wood resource
            addResource(BRICK, 1); // Example: Add one brick resource
            cout << "Player " << name << " added one wood and one brick resource." << endl;
        } 
        else 
        {
            std::cout << "Player " << name << " does not have a Year of Plenty card or it cannot be used." << std::endl;
        }
    } 
    else if (card == "Monopoly") 
    {
        if(devCards.getMonopoly() > 0)
        {
            devCards.removeMonopoly();
            std::cout << "Player " << name << " used a Monopoly card." << std::endl;
            size_t res = rand() % 6;
            board.monopolyAction(res, *this);
        } 
        else 
        {
            std::cout << "Player " << name << " does not have a Monopoly card or it cannot be used." << std::endl;
        }
    } 
    else 
    {
        std::cout << "Player " << name << " does not have a " << card << " card or it cannot be used." << std::endl;
    }
    board.chechVictoryPoints();
}

int Player::placeSettlement(int vertex, Board &board)
{
    if(board.getPlayerTurn() != id)
    {
        cout << "It's not your turn" << endl;
        return 0;
    }

    if (!canBuildSettlement(vertex, board))
    {
        return 0;
    }
    board.buildSettlement(vertex, *this);
    addResource(WOOD, -1);
    addResource(BRICK, -1);
    addResource(SHEEP, -1);
    addResource(WHEAT, -1);
    board.chechVictoryPoints();
    return 1;
}

int Player::placeRoad(int edge, Board &board)
{
    if(board.getPlayerTurn() != id)
    {
        cout << "It's not your turn" << endl;
        return 0;
    }

    if (!canBuildRoad(edge, board))
    {
        return 0;
    }
    board.buildRoad(edge, *this);
    addResource(BRICK, -1);
    addResource(WOOD, -1);
    board.chechVictoryPoints();
    return 1;
}

int Player::placeCity(int vertex, Board &board)
{
    if(board.getPlayerTurn() != id)
    {
        cout << "It's not your turn" << endl;
        return 0;
    }

    if (!canBuildCity(vertex, board))
    {
        return 0;
    }
    board.buildCity(vertex, *this);
    addResource(IRON, -3);
    addResource(WHEAT, -2);
    board.chechVictoryPoints();
    return 1;
}

bool Player::canBuildSettlement(int vertex, Board &board)
{
    if(settlements >= 5)
    {
        cout << "You can't build more settlements" << endl;
        return false;
    }

    if (vertex < 0 || vertex > 53)
    {
        cout << "Invalid vertex" << endl;
        return false;
    }

    Vertex cuurnet_vertex = board.getVertex(vertex);
    if (cuurnet_vertex.getBuilding() != NO_BUILDING)
    {
        cout << "This vertex already has a bulding" << endl;
        return false;
    }

    // check if i own road to the side of the vertex
    vector<int> edges = cuurnet_vertex.getEdges();
    bool hasRoad = false;
    for (int edge : edges)
    {
        Edge current_edge = board.getEdge(edge);
        if (current_edge.getOwner() == getId())
        {
            hasRoad = true;
            break;
        }
    }
    if (!hasRoad)
    {
        cout << "You don't have a road to this vertex" << endl;
        return false;
    }
    
    // check if there is a building in the adjacent vertices
    vector<int> edges_2 = cuurnet_vertex.getEdges();
    for (int edge_2 : edges_2)
    {
        Edge current_edge_2 = board.getEdge(edge_2);
        vector<int> vertices = current_edge_2.getVertices();
        for (int vertex_2 : vertices)
        {
            Vertex current_vertex = board.getVertex(vertex_2);
            if (current_vertex.getBuilding() != NO_BUILDING)
            {
                cout << "One of the adjacent vertices already has a building" << endl;
                return false;
            }
        }
    }

    // if has enough resources
    if (resources[WOOD] < 1 || resources[BRICK] < 1 || resources[WHEAT] < 1 || resources[SHEEP] < 1)
    {
        cout << "You don't have enough resources" << endl;
        return false;
    }
    
    return true;
}

bool Player::canBuildRoad(int edge, Board &board) 
{
    if(roads >= 15)
    {
        cout << "You can't build more roads" << endl;
        return false;
    }

    if (edge < 1 || edge > 72)
    {
        cout << "Invalid edge" << endl;
        return false;
    }

    Edge cuurnet_edge = board.getEdge(edge);
    if (cuurnet_edge.getRoad() != NO_ROAD)
    {
        cout << "This edge already has a road" << endl;
        return false;
    }

    vector<int> vertices = cuurnet_edge.getVertices();
    for (int vertex : vertices)
    {
        Vertex current_vertex = board.getVertex(vertex);
        if (current_vertex.getOwner() > 0)
        {
            Player vertex_owner = board.getPlayer(current_vertex.getOwner());
            if (current_vertex.getOwner() != getId())
            {
                cout << "One of the vertices is owned by the opponent" << endl;
                return false;
            }
        }
    }

    // if has enough resources
    if (resources[WOOD] < 1 || resources[BRICK] < 1)
    {
        cout << "You don't have enough resources" << endl;
        return false;
    }
    
    return true;
}

bool Player::canBuildCity(int vertex, Board &board)
{
    if(cities >= 4)
    {
        cout << "You can't build more settlements" << endl;
        return false;
    }

    if (vertex < 1 || vertex > 72)
    {
        cout << "Invalid vertex" << endl;
        return false;
    }

    Vertex cuurnet_vertex = board.getVertex(vertex);
    if (cuurnet_vertex.getBuilding() != SETTLEMENT)
    {
        cout << "This vertex doesn't have a settlement" << endl;
        return false;
    }

    if (cuurnet_vertex.getBuilding() == SETTLEMENT && cuurnet_vertex.getOwner() != getId())
    {
        cout << "This vertex is not owned by you" << endl;
        return false;
    }
    {
        cout << "This vertex doesn't have a settlement" << endl;
        return false;
    }

    // if has enough resources
    if (resources[IRON] < 3 || resources[WHEAT] < 2)
    {
        cout << "You don't have enough resources" << endl;
        return false;
    }

    return true;
}

void Player::addAssets(string asset)
{
    if(asset == "city")
    {
        cities++;
        settlements--;
    }
    else if(asset == "settlement")
    {
        settlements++;
    }
    else if(asset == "road")
    {
        roads++;
    }
    else if(asset == "card")
    {
        cards++;
    }
}

void Player::tradeFromto(ResourceType from, ResourceType to, Board &board)
{
    string res [] = {"Wood", "Brick", "Wheat", "Sheep", "Iron"};
    if(board.getPlayerTurn() != id)
    {
        cout << "It's not your turn" << endl;
        return;
    }

    if(resources[from] < 4)
    {
        cout << "You don't have enough " << res[from] << " to trade" << endl;
        return;
    }

    resources[from] -= 4;
    resources[to] += 1;
    cout << "Traded 4 " << res[from] << " for 1 " << res[to] << endl;
}

void Player::setHalfResources()
{
    if (countResources() < 7)
    {
        return;
    }
    size_t needToReduce = countResources()/2;
    size_t temp = 0;
    for(auto it = resources.begin(); it != resources.end(); it++)
    {
        if (needToReduce <= 0)
        {
            break;
        }
        // update the resources
        // claculate how much i have left to reduce
        temp = it->second;
        it->second /= 2;
        temp -= it->second;
        needToReduce -= temp;
    }
    cout << "\tReduced half resources from player " << getName() << endl;
}

size_t Player::countResources()
{
    size_t count = 0;
    for(auto it = resources.begin(); it != resources.end(); it++)
    {
        count += it->second;
    }
    return count;
}

void Player::endTurn(Board &board)
{
    if(board.getPlayerTurn() != id)
    {
        cout << "It's not your turn" << endl;
        return;
    }
    // if the player didn't roll the dices, roll them
    if (!alreadyRolled)
    {
        rollDices(board);
    }
    board.nextTurn();
}

void Player::setAlreadyRolled(bool rolled)
{
    alreadyRolled = rolled;
}

bool Player::getAlreadyRolled() const
{
    return alreadyRolled;
}

int Player::getId() const {
    return id;
}

string Player::getName() const {
    return name;
}

size_t Player::getVictoryPoints()
{
    size_t count = 0;
    count += cities * 2;
    count += settlements;
    count += devCards.getPoints();
    return count;
}

void Player::help_Road_Building_Card(Board &board)
{
    if(roads >= 15)
    {
        cout << "You can't build more roads" << endl;
        return;
    }

    size_t count = 0;
    size_t times = 0;
    size_t edge = 0;
    while (count < 2)
    {
        // to avoid infinite loop
        if (times > 100)
        {
            cout << "No more roads can be built" << endl;
            break;
        }
        times++;


        edge = rand() % 72 + 1;
        
        // check if there is a road in the edge
        if ( board.getEdge(edge).getRoad() == NO_ROAD)
        {
            // check if it is legal to build a road
            Edge cuurnet_edge = board.getEdge(edge);
            vector<int> vertices = cuurnet_edge.getVertices();
            for (int vertex : vertices)
            {
                Vertex current_vertex = board.getVertex(vertex);
                if (current_vertex.getOwner() > 0)
                {
                    Player vertex_owner = board.getPlayer(current_vertex.getOwner());
                    if (current_vertex.getOwner() != getId())
                    {
                        // "One of the vertices is owned by the opponent"
                        continue;
                    }
                }
            }

            // build
            board.buildRoad(edge, *this);
            count++;
        }
    }
}

size_t Player::getResources(ResourceType res)
{
    return resources[res];
}




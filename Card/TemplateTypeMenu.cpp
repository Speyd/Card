#include "Menu.h"
#include "Menu.cpp"
#include "Card.h"
#include "Player.h"
#include <memory>

template class Menu<Card*>;
template class Menu<Player*>;
template class Menu<bool>;
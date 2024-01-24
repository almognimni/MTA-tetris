#include "Player.h"


//player::player()  myPlayerBoard(), isAlive(true) {};

void Player::handleInput(char key)
{

    if (ID == 1)
    {
        switch (key)
        {
        case (char)GameConfig::Players_eKeys::p1RIGHT:
            myPlayerBoard.moveCurrentShape(GameConfig::eKeys::RIGHT);
            break;
        case (char)GameConfig::Players_eKeys::p1LEFT:
            myPlayerBoard.moveCurrentShape(GameConfig::eKeys::LEFT);
            break;
        case (char)GameConfig::Players_eKeys::p1ROTATE_CLOCKWISE:
            myPlayerBoard.moveCurrentShape(GameConfig::eKeys::ROTATE_CLOCKWISE);
            break;
        case (char)GameConfig::Players_eKeys::p1ROTATE_COUNTERCLOCKWISE:
            myPlayerBoard.moveCurrentShape(GameConfig::eKeys::ROTATE_COUNTERCLOCKWISE);
            break;
        case (char)GameConfig::Players_eKeys::p1DROP:
            myPlayerBoard.moveCurrentShape(GameConfig::eKeys::DROP);
            break;
        default:
            return; //No valid key for the player
        }

    }
    else if (ID == 2)
    {
        switch (key)
        {
        case (char)GameConfig::Players_eKeys::p2RIGHT:
            myPlayerBoard.moveCurrentShape(GameConfig::eKeys::RIGHT);
            break;
        case (char)GameConfig::Players_eKeys::p2LEFT:
            myPlayerBoard.moveCurrentShape(GameConfig::eKeys::LEFT);
            break;
        case (char)GameConfig::Players_eKeys::p2ROTATE_CLOCKWISE:
            myPlayerBoard.moveCurrentShape(GameConfig::eKeys::ROTATE_CLOCKWISE);
            break;
        case (char)GameConfig::Players_eKeys::p2ROTATE_COUNTERCLOCKWISE:
            myPlayerBoard.moveCurrentShape(GameConfig::eKeys::ROTATE_COUNTERCLOCKWISE);
            break;
        case (char)GameConfig::Players_eKeys::p2DROP:
            myPlayerBoard.moveCurrentShape(GameConfig::eKeys::DROP);
            break;
        default:
            return; //No valid key for the player
        }

    }
}

bool Player::checkIfLost()
{
    if (myPlayerBoard.isOverlapping() == true)
    {
        killPlayer();
        return true;
    }
    else
        return false;
}
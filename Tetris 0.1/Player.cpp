#include "Player.h"

void Player::handleInput(char key)
{

    if (ID == 1)
    {
        switch (key)
        {
        case (char)GameConfig::Players_eKeys::p1RIGHT:
            myPlayerBoard.moveCurrentTetromino(GameConfig::eKeys::RIGHT);
            break;
        case (char)GameConfig::Players_eKeys::p1LEFT:
            myPlayerBoard.moveCurrentTetromino(GameConfig::eKeys::LEFT);
            break;
        case (char)GameConfig::Players_eKeys::p1ROTATE_CLOCKWISE:
            myPlayerBoard.moveCurrentTetromino(GameConfig::eKeys::ROTATE_CLOCKWISE);
            break;
        case (char)GameConfig::Players_eKeys::p1ROTATE_COUNTERCLOCKWISE:
            myPlayerBoard.moveCurrentTetromino(GameConfig::eKeys::ROTATE_COUNTERCLOCKWISE);
            break;
        case (char)GameConfig::Players_eKeys::p1DROP:
            myPlayerBoard.moveCurrentTetromino(GameConfig::eKeys::DROP);
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
            myPlayerBoard.moveCurrentTetromino(GameConfig::eKeys::RIGHT);
            break;
        case (char)GameConfig::Players_eKeys::p2LEFT:
            myPlayerBoard.moveCurrentTetromino(GameConfig::eKeys::LEFT);
            break;
        case (char)GameConfig::Players_eKeys::p2ROTATE_CLOCKWISE:
            myPlayerBoard.moveCurrentTetromino(GameConfig::eKeys::ROTATE_CLOCKWISE);
            break;
        case (char)GameConfig::Players_eKeys::p2ROTATE_COUNTERCLOCKWISE:
            myPlayerBoard.moveCurrentTetromino(GameConfig::eKeys::ROTATE_COUNTERCLOCKWISE);
            break;
        case (char)GameConfig::Players_eKeys::p2DROP:
            myPlayerBoard.moveCurrentTetromino(GameConfig::eKeys::DROP);
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
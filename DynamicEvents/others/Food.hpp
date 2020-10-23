#pragma once

#include <algorithm>
#include <sstream>
#include <memory>
#include "SnakeController.hpp"
#include "EventT.hpp"

namespace Food
{
    std::pair<int, int> m_foodPosition;

    std::unique_ptr<EventT<Snake::DisplayInd>> sendPlaceNewFood(int x, int y)
    {
        m_foodPosition = std::make_pair(x, y);

        Snake::DisplayInd placeNewFood;
        placeNewFood.x = x;
        placeNewFood.y = y;
        placeNewFood.value = Snake::Cell_FOOD;

    return std::move(std::make_unique<EventT<Snake::DisplayInd>>(placeNewFood));
    }

    std::unique_ptr<EventT<Snake::DisplayInd>> sendClearOldFood()
    {
        Snake::DisplayInd clearOldFood;
        clearOldFood.x = m_foodPosition.first;
        clearOldFood.y = m_foodPosition.second;
        clearOldFood.value = Snake::Cell_FREE;

        return std::move(std::make_unique<EventT<Snake::DisplayInd>>(clearOldFood));
    }
} // namespace Food
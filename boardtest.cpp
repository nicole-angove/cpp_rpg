#include <gtest/gtest.h>
#include "board.h"
#include "element.h"



TEST(Board, GemCountsForEachElementAfterMove) {
    Board board;

    // set up the gems

    board.setSphere(Element::FIRE, Sphere({Element::SPIRIT}));
    board.setSphere(Element::EARTH, Sphere({Element::EARTH}));

    // count the gems before the move

    int fireCountExpected = board.count(Element::ALL, Element::FIRE);
    int waterCountExpected = board.count(Element::ALL, Element::WATER);
    int earthCountExpected = board.count(Element::ALL, Element::EARTH);
    int spiritCountExpected = board.count(Element::ALL, Element::SPIRIT);
    int lightningCountExpected = board.count(Element::ALL, Element::LIGHTNING);

    // do the move

    Move move1 = {.gem = Element::SPIRIT, .source = Element::FIRE, .destination = Element::SPIRIT};
    Move move2 = {.gem = Element::EARTH, .source = Element::EARTH, .destination = Element::WATER};

    std::vector<Move> card = {move1, move2};

    board.doMoves(card);

    // count the gems after the move

    int fireCountActual = board.count(Element::ALL, Element::FIRE);
    int waterCountActual = board.count(Element::ALL, Element::WATER);
    int earthCountActual = board.count(Element::ALL, Element::EARTH);
    int spiritCountActual = board.count(Element::ALL, Element::SPIRIT);
    int lightningCountActual = board.count(Element::ALL, Element::LIGHTNING);

    // compare the two counts

    EXPECT_EQ(fireCountExpected, fireCountActual);
    EXPECT_EQ(waterCountExpected, waterCountActual);
    EXPECT_EQ(earthCountExpected, earthCountActual);
    EXPECT_EQ(spiritCountExpected, spiritCountActual);
    EXPECT_EQ(lightningCountExpected, lightningCountActual);
}
